package week8.sangmin.problem5;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Problem5 {
    static List<List<Integer>> graph = new ArrayList<>();
    static int[] inDegree;
    static int N, M;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        N = Integer.parseInt(line[0]);
        M = Integer.parseInt(line[1]);
        for(int i = 0; i <= N; i++){
            graph.add(new ArrayList<>());
        }
        inDegree = new int[N + 1];
        for(int i = 0; i < M; i++){
            line = br.readLine().split(" ");
            graph.get( Integer.parseInt(line[0]) ).add( Integer.parseInt(line[1]) );
            inDegree[Integer.parseInt(line[1])]++;
        }

        Queue<Integer> q = new LinkedList<>();
        for(int i = 1; i <= N; i++){
            if(inDegree[i] == 0)
                q.add(i);
        }
        StringBuilder sb = new StringBuilder();
        while (!q.isEmpty()){
            int curNode = q.poll();
            sb.append(curNode + " ");
            for(int nextNode : graph.get(curNode)){
                inDegree[nextNode]--;
                if(inDegree[nextNode] == 0){
                    q.add(nextNode);
                }
            }
        }
        System.out.println(sb.toString());
    }
}
