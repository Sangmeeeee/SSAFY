package week10.sangmin.extra.problem8;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

class Node implements Comparable<Node>{
    int num, value;

    public Node(int num, int value) {
        this.num = num;
        this.value = value;
    }

    @Override
    public int compareTo(Node o) {
        return Integer.compare(this.value, o.value);
    }
}

public class Problem8 {
    static int N;
    static int M;
    static int X;

    static int[] dijkstra(int[] dist, List<List<Node>> graph){
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(X, 0));
        dist[X] = 0;
        while (!pq.isEmpty()){
            Node curNode = pq.poll();

            if(dist[curNode.num] < curNode.value) continue;

            for(Node nextNode : graph.get(curNode.num)){
                if(dist[nextNode.num] > curNode.value + nextNode.value){
                    dist[nextNode.num] = curNode.value + nextNode.value;
                    pq.add(new Node(nextNode.num, dist[nextNode.num]));
                }

            }
        }
        return dist;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        List<List<Node>> graph = new ArrayList<>();
        List<List<Node>> reverseGraph = new ArrayList<>();

        String[] line = br.readLine().split(" ");
        N = Integer.parseInt(line[0]);
        M = Integer.parseInt(line[1]);
        X = Integer.parseInt(line[2]);

        int[] xton = new int[N + 1];
        int[] ntox = new int[N + 1];
        ntox = new int[N + 1];
        for(int i = 0; i <= N; i++){
            graph.add(new ArrayList<>());
            reverseGraph.add(new ArrayList<>());
        }

        Arrays.fill(xton, 10000 * 1000 + 1);
        Arrays.fill(ntox, 10000 * 1000 + 1);

        for(int i = 0; i < M; i++){
            line = br.readLine().split(" ");
            int from = Integer.parseInt(line[0]);
            int to = Integer.parseInt(line[1]);
            int value = Integer.parseInt(line[2]);
            graph.get(from).add(new Node(to, value));
            reverseGraph.get(to).add(new Node(from, value));
        }

        xton = dijkstra(xton, graph);
        ntox = dijkstra(ntox, reverseGraph);

        int result = Integer.MIN_VALUE;

        for(int i = 1; i <= N; i++){
            result = Math.max(result, xton[i] + ntox[i]);
        }
        System.out.println(result);
    }
}
