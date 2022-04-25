package week14.inseok.problem1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class problem1 {
    static class TrieNode{
        //자식 노드 맵
        public Map<Character,TrieNode> childNodes = new HashMap<>();
        //마지막 글자 여부
        public boolean isLastChar;
    }
    static class Trie{
        //루트노드
        public TrieNode rootNode;
        public boolean consistency=true;
        //생성자
        public Trie() {
            this.rootNode = new TrieNode();
        }
        //insert 등 메서드 여기서 구현 하는게 정석 인거 같긴함.
        //insert(String)
        void insert(String str){
            TrieNode curNode = this.rootNode;
            boolean cTemp= consistency;//consistency Temp

            for(int i=0;i<str.length();i++){
                //일관성 먼저 체크
                //값 체크 하다가 isLastChar 가 true 인 녀석을 온전히 만나면서 지나가면 cTemp 변경
                if(curNode.isLastChar==true){
                    cTemp = false;
                }
                //이부분 이해가 좀... 특히 람다함수.. c가 뭐임?
                //일단 이해한바로는 앞 쪽이 "있으면" part 로, value를 반환.
                //뒤쪽은 없을때 람다함수 실행인데 그부분이 이해가 좀 안됨.
                curNode = curNode.childNodes.computeIfAbsent(str.charAt(i),c->new TrieNode());
            }
            curNode.isLastChar=true;
            //curNode 기준으로
            // 뭐라도 뒤에 있으면 일관성 노노
            for(int i=0;i<26;i++){
                if(curNode.childNodes.containsKey((char)('0'+i))){
                    cTemp=false;
                }
            }
            consistency= cTemp;
        }
        //checkCons : 트라이 자료구조의 일관성 체크

    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //testCase
        int T = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for (int testCase = 1; testCase <= T; testCase++) {
            //input N
            int N = Integer.parseInt(br.readLine());

            //make Trie
            Trie trie = new Trie();
            //input Strings
            String inputStr = null;
            for (int i = 0; i < N; i++) {
                inputStr  = br.readLine();
                //init Trie
                trie.insert(inputStr);
            }
            if(trie.consistency==true){
                sb.append("YES\n");
            }else{
                sb.append("NO\n");
            }
        }//END testCase
        System.out.print(sb.toString());
        //System.out.println((char)('0'+3));
    }//END MAIN
}

//전화번호 목록
//https://www.acmicpc.net/problem/5052

/*
        2
        3
        911
        97625999
        91125426
        5
        113
        12340
        123440
        12345
        98346
*/