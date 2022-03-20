package week8.sangmin.extra.problem9;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
public class Problem9 {
    static int N, M;
    static List<List<Integer>> graph = new ArrayList<>();
    static int[][] dist = new int[101][101]; // i에서 j까지 필요 개수
    static int[] inner = new int[101];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        for(int i = 0; i <= N; i++){
            graph.add(new ArrayList<>());
        }

        for(int i = 0; i < M; i++){
            String[] line = br.readLine().split(" ");
            int node1 = Integer.parseInt(line[0]); // 5
            int node2 = Integer.parseInt(line[1]); // 2
            int d = Integer.parseInt(line[2]); // 2
            graph.get(node1).add(node2); // 역으로 만듬
            dist[node1][node2] = d; // 필요 개수
            inner[node2]++;
        }

        Queue<Integer> q = new LinkedList<>();
        q.add(N);

        while(!q.isEmpty()){
            int curNode = q.poll();
            for(int nextNode : graph.get(curNode)){
                inner[nextNode]--;

                // N에서 다음 노드로 가는 개수 = N에서 현재 노드로 가는 개수 * 현재 노드에서 다음 노드로 가는 개수
                dist[N][nextNode] += (dist[curNode][nextNode] * dist[N][curNode]);

                if(inner[nextNode] == 0){
                    q.add(nextNode);
                }
            }
        }
        for(int i = 1; i < N; i++){
            if(graph.get(i).size() == 0){
                System.out.println(i + " " + dist[N][i]);
            }
        }
    }
}