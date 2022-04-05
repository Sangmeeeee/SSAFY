package week10.sangmin.problem2;

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
        return Integer.compare(this.num, o.num);
    }
}

public class Problem2 {
    static int N, V, E;
    static int K, C;
    static int[] members;
    static List<List< Node >> graph = new ArrayList<>();

    public static int[] find(int start){
        int[] dist = new int[V + 1];
        Arrays.fill(dist, 10000 * 100 + 2);
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(start, 0));
        dist[start] = 0;
        while (!pq.isEmpty()){
            Node curNode = pq.poll();
            if(dist[curNode.num] < curNode.value) continue;

            for(Node nextNode : graph.get(curNode.num)){
                if(dist[nextNode.num] > curNode.value + nextNode.value){
                    dist[nextNode.num] = curNode.value +nextNode.value;
                    pq.add(new Node(nextNode.num, dist[nextNode.num]));
                }
            }
        }
        return dist;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        N = Integer.parseInt(line[0]);
        V = Integer.parseInt(line[1]);
        E = Integer.parseInt(line[2]);

        line = br.readLine().split(" ");
        K = Integer.parseInt(line[0]);
        C = Integer.parseInt(line[1]);

        members = new int[N + 1];
        line = br.readLine().split(" ");
        for(int i = 1; i <= N; i++){
            members[i] = Integer.parseInt(line[i - 1]);
        }

        for(int i = 0; i <= V; i++){
            graph.add(new ArrayList<>());
        }

        for(int i = 0; i < E; i++){
            line = br.readLine().split(" ");
            int a = Integer.parseInt(line[0]);
            int b = Integer.parseInt(line[1]);
            int l = Integer.parseInt(line[2]);
            graph.get(a).add(new Node(b, l));
            graph.get(b).add(new Node(a, l));
        }

        int[] result1 = find(K);
        int[] result2 = find(C);

        int sum = 0;
        for(int i = 1; i <= N; i++){
            sum += result1[members[i]] == (10000 * 100 + 2) ? -1 : result1[members[i]];
            sum += result2[members[i]] == (10000 * 100 + 2) ? -1 : result2[members[i]];
        }
        System.out.println(sum);
    }
}
