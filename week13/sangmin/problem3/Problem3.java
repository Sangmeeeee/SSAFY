package week13.sangmin.problem3;

import java.io.*;
import java.util.*;

class Edge implements Comparable<Edge>{
    int from, to, value;

    public Edge(int from, int to, int value) {
        super();
        this.from = from;
        this.to = to;
        this.value = value;
    }

    @Override
    public int compareTo(Edge o) {
        return Integer.compare(o.value, this.value);
    }
}

class Node{
    int num, value;

    public Node(int num, int value) {
        super();
        this.num = num;
        this.value = value;
    }
}

public class Problem3 {
    static int N, M;
    static int s, e;
    static PriorityQueue<Edge> pq = new PriorityQueue<>();
    static List<List<Node>> graph = new ArrayList<>();
    static int[] parents;
    static final int INF = 1000001;

    public static int findParent(int num) {
        if(num == parents[num]) return num;
        return parents[num] = findParent(parents[num]);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        N = Integer.parseInt(line[0]);
        parents = new int[N + 1];
        for(int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
            parents[i] = i;
        }

        M = Integer.parseInt(line[1]);
        line = br.readLine().split(" ");
        s = Integer.parseInt(line[0]);
        e = Integer.parseInt(line[1]);

        for(int i = 0; i < M; i++) {
            line = br.readLine().split(" ");
            int h1 = Integer.parseInt(line[0]);
            int h2 = Integer.parseInt(line[1]);
            int k = Integer.parseInt(line[2]);
            pq.add(new Edge(h1, h2, k));
        }

        while(!pq.isEmpty()) {
            Edge curEdge = pq.poll();
            int parent1 = findParent(curEdge.from);
            int parent2 = findParent(curEdge.to);
            if(parent1 != parent2) {
                parents[parent1] = parent2;
                graph.get(curEdge.from).add(new Node(curEdge.to, curEdge.value));
                graph.get(curEdge.to).add(new Node(curEdge.from, curEdge.value));
            }
        } // MST와 MST에 해당하는 그래프 만들어줌

        int[] dist = new int[N + 1];
        Arrays.fill(dist, INF);
        for(Node init : graph.get(s)) {
            dist[init.num] = init.value;
        }
        boolean[] isVisit = new boolean[N + 1];
        isVisit[s] = true;
        Queue<Integer> q = new LinkedList<>();
        q.add(s);

        while(!q.isEmpty()) {
            int from = q.poll();
            for(Node nextNode : graph.get(from)) {
                int to = nextNode.num;
                int from_to_value = nextNode.value;
                if(!isVisit[to]) {
                    isVisit[to] = true;
                    dist[to] = Math.min(dist[from], from_to_value);
                    q.add(to);
                }
            }
        }

        if(dist[e] == INF) {
            System.out.println(0);
        }else {
            System.out.println(dist[e]);
        }
    }
}