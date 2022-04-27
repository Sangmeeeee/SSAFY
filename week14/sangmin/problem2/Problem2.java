package week14.sangmin.problem2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Node{
    Map<String, Node> child = new HashMap<>();
}

public class Problem2 {
    static Node root = new Node();

    static void dfs(int depth, Node curNode){
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < depth; i++){
            sb.append(" ");
        }
        List<String> dirList = new ArrayList(curNode.child.keySet());
        Collections.sort(dirList);
        for(String dir : dirList){
            System.out.println(sb.toString() + dir);
            dfs(depth + 1, curNode.child.get(dir));
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        for(int i = 0 ; i < N; i++){
            String[] line = br.readLine().split("\\\\");
            Node curNode = root;
            for(String dir : line){
                Map<String, Node> child = curNode.child;
                if(!child.containsKey(dir)){
                    child.put(dir, new Node());
                }
                curNode = curNode.child.get(dir);
            }
        }
        dfs(0, root);
    }
}

/*
7
WINNT\SYSTEM32\CONFIG
GAMES
WINNT\DRIVERS
HOME
WIN\SOFT
GAMES\DRIVERS
WINNT\SYSTEM32\CERTSRV\CERTCO~1\X86
 */