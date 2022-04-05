package week10.sangmin.problem3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

class Node implements Comparable<Node>{
    int num;
    long value;

    public Node(int num, long value) {
        super();
        this.num = num;
        this.value = value;
    }

    @Override
    public int compareTo(Node o) {
        // TODO Auto-generated method stub
        return Long.compare(this.value, o.value);
    }
}

public class Problem3 {
    static int N, M;
    static int from, to;
    static long[] dist;
    static int[] parents;
    static List< List<Node> > graph = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        N = Integer.parseInt(line[0]);
        dist = new long[N + 1];
        parents = new int[N + 1];
        for(int i = 0; i <= N; i++) {
            parents[i] = i;
            dist[i] = 10000000001L;
            graph.add(new ArrayList<>());
        }

        line = br.readLine().split(" ");
        M = Integer.parseInt(line[0]);
        PriorityQueue<Node> pq = new PriorityQueue<>();
        for(int i = 0; i < M; i++) {
            line = br.readLine().split(" ");
            int num1 = Integer.parseInt(line[0]);
            int num2 = Integer.parseInt(line[1]);
            int value = Integer.parseInt(line[2]);
            graph.get(num1).add(new Node(num2, value));
        }
        line = br.readLine().split(" ");
        from = Integer.parseInt(line[0]);
        to = Integer.parseInt(line[1]);

        dist[from] = 0;
        pq.add(new Node(from, 0));
        while(!pq.isEmpty()) {
            Node curNode = pq.poll();
            if(dist[curNode.num] < curNode.value) continue;
            for(Node nextNode : graph.get(curNode.num)) {
                if(dist[nextNode.num] > curNode.value + nextNode.value) {
                    dist[nextNode.num] = curNode.value + nextNode.value;
                    pq.add(new Node(nextNode.num, dist[nextNode.num]));
                }
            }
        }
        System.out.println(dist[to]);
    }
}