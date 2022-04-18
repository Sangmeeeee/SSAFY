package week12.sangmin.problem2;

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

public class Problem2 {
    static final int INF = 987654321;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int TC = Integer.parseInt(br.readLine());

        for(int test_case = 0; test_case < TC; test_case++){
            List<List<Node>> edges = new ArrayList<>();
            String[] line = br.readLine().split(" ");
            int N = Integer.parseInt(line[0]);
            int M = Integer.parseInt(line[1]);
            int W = Integer.parseInt(line[2]);

            for(int i = 0; i <= N; i++){
                edges.add(new ArrayList<>());
            }

            for(int i = 0; i < M; i++){
                line = br.readLine().split(" ");
                int S = Integer.parseInt(line[0]);
                int E = Integer.parseInt(line[1]);
                int T = Integer.parseInt(line[2]);
                edges.get(E).add(new Node(S, T));
                edges.get(S).add(new Node(E, T));
            }

            for(int i = 0; i < W; i++){
                line = br.readLine().split(" ");
                int S = Integer.parseInt(line[0]);
                int E = Integer.parseInt(line[1]);
                int T = Integer.parseInt(line[2]);
                edges.get(S).add(new Node(E, -T));
            }

            int[] dist = new int[N + 1];

            boolean flag = false;
            Arrays.fill(dist, INF);
            dist[1] = 0;

            for (int i = 0; i <= N; i++) {
                flag = false;
                for(int from = 1; from <= N; from++){
                    for(Node nextNode : edges.get(from)){
                        if(dist[nextNode.to] > dist[from] + nextNode.value){
                            dist[nextNode.to] = dist[from] + nextNode.value;
                            flag = true;
                        }
                    }
                }
            }

            System.out.println(flag ? "YES" : "NO");
        }
    }
}

/*
2
4 4 1
1 4 1
4 1 1
3 1 1
3 2 1
2 3 2
4 3 1
1 2 1
2 1 1
3 4 1
4 3 2

 */