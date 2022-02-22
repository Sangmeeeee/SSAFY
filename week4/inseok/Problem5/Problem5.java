package com.inteli.study.week4.d0219;

import java.util.LinkedList;
import java.util.Queue;

public class Problem5 {
    static String begin="hit";//-1
    static String target="cog";
    static String[] words={"hot", "cot", "dog", "cog", "log", "sog"};

    //문제 : 도중에 target 이 나와도 멈춰 야 한다(꼭 최후에 target 이 있어야 하는건 아님!)
    public static void main(String[] args) {
        int answer =0;
        Queue<Node> queue = new LinkedList<>();
        boolean answerFlag=false;
        //init (start)
        for(int i=0;i<words.length;i++){
            if(check(begin, words[i])){
                System.out.printf("1: "+begin+ " 2: "+words[i]+"\n");
                if(target.equals(words[i])){
                    answerFlag=true;
                    answer=1;
                    break;
                }
                queue.offer(new Node(i));
            }
        }
        //sol
        while(!queue.isEmpty()){
            if(answerFlag){
                break;
            }
            Node curNode = queue.poll();
            if(target.equals(words[curNode.idx])){
                answer=curNode.depth;
                answerFlag=true;
                break;
            }
            //만약 뒤에 idx 들과 비교해서 nextStep 갈수 있는애들 넣기(대신 depth 신경 쓰기.)
            for(int i=0;i< words.length;i++){
                if(check(words[curNode.idx],words[i])){
                    System.out.printf("1: "+words[curNode.idx]+ " 2: "+words[i]+" "+(curNode.depth+1)+"\n");
                    queue.offer(new Node(i,curNode.depth+1));
                }
            }
        }

        System.out.println(answer);
    }
    //단어 bfs 타고 들어가도 되는지 체크하는 함수
    public static boolean check(String from , String to){
        int diff=0;
        boolean answer=true;
        for (int i = 0; i < from.length(); i++) {
            if(from.charAt(i) != to.charAt(i)){
                diff++;
            }
        }
        if (diff ==1)
            return true;
        return false;
    }
    //bfs 최소라서 사실 dfs보다 bfs 가 맞는거 같다.
    //queue : 넣고, level 표시 하고, class (idx, depth) 먼저 마지막 idx 까지 도달 하면 그걸 ret
    static class Node{
        int idx;
        int depth;
        public Node(int idx, int depth) {
            this.idx = idx;
            this.depth = depth;
        }
        public Node(int idx) {
            this.idx = idx;
            this.depth=1;
        }
    }
}
