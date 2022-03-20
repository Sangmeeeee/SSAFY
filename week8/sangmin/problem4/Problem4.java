package week8.sangmin.problem4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Problem4 {
    static int[] inDegrees;
    static int[] times;
    static int[] results;
    static int N;
    static List<List<Integer>> graph = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        N = Integer.parseInt(line[0]);
        inDegrees = new int[N + 1];
        times = new int[N + 1];
        results = new int[N + 1];
        for(int i = 0; i <= N; i++){
            graph.add(new ArrayList<>());
            results[i] = 0;
        }

        for(int i = 1; i <= N; i++){
            line = br.readLine().split(" ");
            times[i] = Integer.parseInt(line[0]);
            int size = Integer.parseInt(line[1]);
            inDegrees[i] = size;
            for(int j = 0; j < size; j++){
                graph.get(Integer.parseInt(line[j + 2])).add(i);
            }
        }

        Queue<Integer> q = new LinkedList<>();
        int max = Integer.MIN_VALUE;
        for(int i = 1; i <= N; i++){
            if(inDegrees[i] == 0){
                q.add(i);
                results[i] = times[i];
                max = Math.max(times[i], max);
            }
        }

        while(!q.isEmpty()){
            int curNode = q.poll();
            for(int nextNode : graph.get(curNode)){
                inDegrees[nextNode]--;

                results[nextNode] = Math.max( times[nextNode] + results[curNode], results[nextNode]);
                if(inDegrees[nextNode] == 0){
                    max = Math.max(results[nextNode], max);
                    q.add(nextNode);
                }
            }
        }
        System.out.println(max);
    }
}

/*
7
5 0
1 1 1
3 1 2
6 1 1
1 2 2 4
8 2 2 4
4 3 3 5 6
 */