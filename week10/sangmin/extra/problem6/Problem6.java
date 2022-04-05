package week10.sangmin.extra.problem6;

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
        // TODO Auto-generated method stub
        return Integer.compare(this.value, o.value);
    }

}

class Solution {

    static List< List<Node> > graph = new ArrayList<>();

    static int[] dijkstra(int start, int n) {
        int[] dist = new int[n + 1];

        PriorityQueue<Node> pq = new PriorityQueue<>();
        Arrays.fill(dist, 100000 * 200 + 1);
        dist[start] = 0;
        pq.add(new Node(start, 0));

        while(!pq.isEmpty()) {
            Node curNode = pq.poll();

            if(curNode.value > dist[curNode.num]) continue;

            for(Node nextNode : graph.get(curNode.num)) {
                if(dist[nextNode.num] > curNode.value + nextNode.value) {
                    dist[nextNode.num] = curNode.value + nextNode.value;
                    pq.add(new Node(nextNode.num, dist[nextNode.num]));
                }
            }
        }
        return dist;
    }

    public int solution(int n, int s, int a, int b, int[][] fares) {
        int answer = Integer.MAX_VALUE;

        for(int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }

        for(int[] fare : fares) {
            graph.get(fare[0]).add(new Node(fare[1], fare[2]));
            graph.get(fare[1]).add(new Node(fare[0], fare[2]));
        }
        int sDist[] = dijkstra(s, n);
        int aDist[] = dijkstra(a, n);
        int bDist[] = dijkstra(b, n);

        for(int i = 1; i <= n; i++) {
            answer = Math.min(answer, sDist[i] + aDist[i] + bDist[i]);
        }
        System.out.println(answer);
        return answer;
    }
}

public class Problem6 {
    public static void main(String[] args) {

    }
}
