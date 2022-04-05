package week10.sangmin.problem4;

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
        super();
        this.num = num;
        this.value = value;
    }

    @Override
    public int compareTo(Node o) {
        return Integer.compare(this.value, o.value);
    }
}

public class Problem4 {
    static int V;
    static int E;
    static int startNode;
    static List<Node>[] list;
    static int[] dist;

    static void dijkstra(int startNode) {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(startNode, 0));
        dist[startNode] = 0;

        while(!pq.isEmpty()) {
            int curIdx = pq.peek().num;
            int curDist = pq.poll().value;

            if(curDist > dist[curIdx]) continue;

            for(int i = 0; i < list[curIdx].size(); i++) {
                Node nextNode = list[curIdx].get(i);

                if( curDist + nextNode.value < dist[nextNode.num] ) {
                    dist[nextNode.num] = curDist + nextNode.value;
                    pq.add(new Node(nextNode.num, curDist + nextNode.value));
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] firstLine = br.readLine().split(" ");
        V = Integer.parseInt(firstLine[0]);
        E = Integer.parseInt(firstLine[1]);
        startNode = Integer.parseInt(br.readLine());

        list = new ArrayList[V + 1];
        for(int i = 0; i <= V; i++) {
            list[i] = new ArrayList<>();
        }
        dist = new int[V + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);

        for(int i = 0 ; i < E; i++) {
            String[] line = br.readLine().split(" ");
            list[Integer.parseInt(line[0])].add(new Node(Integer.parseInt(line[1]),Integer.parseInt(line[2])));
        }

        dijkstra(startNode);
        for(int i = 1; i < dist.length; i++) {
            if(dist[i] == Integer.MAX_VALUE)
                System.out.println("INF");
            else
                System.out.println(dist[i]);
        }
    }
}