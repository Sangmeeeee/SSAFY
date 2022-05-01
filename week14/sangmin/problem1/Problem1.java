package week14.sangmin.problem1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

class Node{
    boolean isEnd = false;
    Map<Character, Node> child = new HashMap<>();
}

public class Problem1 {

    static Node root;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        for(int test_case = 1; test_case <= t; test_case++){

            int n = Integer.parseInt(br.readLine());
            boolean isPossible = true;
            root = new Node();

            for(int i = 0; i < n; i++){
                String line = br.readLine();
                Node curNode = root;
                for(int idx = 0; idx < line.length(); idx++){
                    Map<Character, Node> child = curNode.child; // 현재 노드와 연결되어있는 child들
                    char key = line.charAt(idx);
                    if(!child.containsKey(key)){ // 현재 자식에 key가 포함되어있지 않다면 넣어줌
                        child.put(key, new Node());
                        curNode = child.get(key);
                    }else{ // 현재 자식에 key가 포함되어있다면 이동해줌, 근데 마지막이라는 표시가 있다면 isPossible은 false

                        if(idx == line.length() - 1){ // 현재 키가 문자열의 마지막인데 이미 존재해 있다면 불가능함
                            isPossible = false;
                        }

                        curNode = child.get(key);

                        if(curNode.isEnd) isPossible = false; // 가고 있는데 이미존재하고 이미존재하는데다가 그 존재하는게 문자열의 마지막이면
                    }
                    if(idx == line.length() - 1){
                        curNode.isEnd = true;
                    }
                }
            }
            if(isPossible){
                System.out.println("YES");
            }else{
                System.out.println("NO");
            }
        }
    }
}

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
NO
YES

1
2
8999999999
8


2
2
1234
12345
 */