package week12.sangmin.problem1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Node{
    int to, value;
    public Node(int to, int value) {
        this.to = to;
        this.value = value;
    }
}

public class Problem1 {
    static List<List<Node>> list = new ArrayList<>();
    static long[] dist;
    static int N, M;
    static int INF = 987654321;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        N = Integer.parseInt(line[0]);
        M = Integer.parseInt(line[1]);
        dist = new long[N + 1];
        for(int i = 0; i <= N; i++){
            list.add(new ArrayList<>());
        }
        Arrays.fill(dist, INF);

        for(int i = 0; i < M; i++){
            line = br.readLine().split(" ");
            int A = Integer.parseInt(line[0]);
            int B = Integer.parseInt(line[1]);
            int C = Integer.parseInt(line[2]);
            list.get(A).add(new Node(B,C));
        }

        boolean isUpdate = false;
        dist[1] = 0;
        for(int i = 0; i < N; i++){
            isUpdate = false;
            for(int from = 1; from <= N; from++){
                for(Node nextNode : list.get(from)){
                    if(dist[from] == INF) continue;
                    if(dist[nextNode.to] > dist[from] + nextNode.value){
                        dist[nextNode.to] = dist[from] + nextNode.value;
                        isUpdate = true;
                    }
                }
            }
            if(!isUpdate){
                break;
            }
        }

        boolean isCycle = false;

        if(isUpdate) {
            for (int from = 1; from <= N; from++) {
                for (Node nextNode : list.get(from)) {
                    if(dist[from] == INF) break;
                    if (dist[nextNode.to] > dist[from] + (long) nextNode.value) {
                        isCycle = true;
                    }
                }
            }
        }

        if(isCycle){
            System.out.println(-1);
            return;
        }
        for(int i = 2; i <= N; i++){
            System.out.println(dist[i] == INF ? -1 : dist[i]);
        }
    }
}


/*
3 2
1 2 4
1 2 3

3 2
1 2 3
1 2 4
 */