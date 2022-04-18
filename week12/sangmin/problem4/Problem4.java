package week12.sangmin.problem4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Node{
    int to, value;
    public Node(int to, int value) {
        this.to = to;
        this.value = value;
    }
}

public class Problem4 {
    static int N, M;
    static List<List<Node>> edges = new ArrayList<>();
    static List<List<Node>> rev = new ArrayList<>();
    static final long INF = 100000 * 20000 + 1;
    static long[] dist;
    static int[] parent;
    static boolean[] isVisit;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        N = Integer.parseInt(line[0]);
        M = Integer.parseInt(line[1]);
        dist = new long[N + 1];
        parent = new int[N + 1];
        isVisit = new boolean[N + 1];
        Arrays.fill(dist, INF);
        dist[1] = 0;
        for(int i = 0; i <= N; i++){
            parent[i] = i;
        }
        for(int i = 0; i <= N; i++){
            edges.add(new ArrayList<>());
            rev.add(new ArrayList<>());
        }


        for(int i = 0; i < M; i++){
            line = br.readLine().split(" ");
            int from = Integer.parseInt(line[0]);
            int to = Integer.parseInt(line[1]);
            int value = Integer.parseInt(line[2]);
            edges.get(from).add(new Node(to, -value));
            rev.get(to).add(new Node(from, value));
        }

        parent[1] = 0;
        isVisit[N] = true;
        Queue<Integer> q = new LinkedList<>();
        q.add(N);
        while(!q.isEmpty()) {
            int cur = q.poll();
            for(Node nextNode : rev.get(cur)) {
                if(!isVisit[nextNode.to]) {
                    isVisit[nextNode.to] = true;
                    q.add(nextNode.to);
                }
            }
        }

        boolean isCycle = false;
        for(int i = 0; i <= N; i++){
            for(int from = 1; from <= N; from++){
                if(dist[from] == INF) continue;
                for(Node edge : edges.get(from)){
                    if(dist[edge.to] > dist[from] + edge.value){
                        dist[edge.to] = dist[from] + edge.value;
                        parent[edge.to] = from;
                        if(i == N && isVisit[edge.to]) isCycle = true;
                    }
                }
            }
        }

        if(isCycle || dist[N] == INF){
            System.out.println(-1);
        }else{
            List<Integer> result = new ArrayList<>();
            int p = N;
            while (p != 0){
                result.add(p);
                p = parent[p];
            }
            Collections.reverse(result);
            StringBuilder sb = new StringBuilder();
            for(int i = 0; i < result.size(); i++){
                sb.append(result.get(i) + " ");
            }
            System.out.println(sb.toString());
        }
    }
}

/*
5 7
1 2 3
1 3 4
3 1 -7
2 3 2
3 4 1
4 2 -5
4 5 1

5 7
1 2 3
1 3 4
3 1 -7
2 3 2
3 4 1
4 2 -2
4 5 1

5 7
1 2 1
2 3 1
3 4 1
4 5 1
1 5 10
1 2 50
2 5 80

1 2 3
 */