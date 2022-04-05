package week10.sangmin.problem1;

import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Node implements Comparable<Node>{
    int num, dist;

    Node(int num, int dist){
        this.num = num;
        this.dist = dist;
    }

    @Override
    public int compareTo(Node o){
        return Integer.compare(this.dist, o.dist);
    }
}

class Solution {
    public int solution(int N, int[][] road, int K) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] dist = new int[N + 1];
        Arrays.fill(dist, 2000 * 10000 + 1);
        dist[1] = 0;

        List<List<Node>> graph = new ArrayList<>();
        for(int i = 0; i <= N; i++){
            graph.add(new ArrayList<>());
        }

        for(int[] info : road){
            graph.get(info[0]).add(new Node(info[1],info[2]));
            graph.get(info[1]).add(new Node(info[0],info[2]));
        }

        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(1, 0));

        while (!pq.isEmpty()){
            Node curNode = pq.poll();
            if(curNode.dist > dist[curNode.num] ) continue;
            for(Node nextNode : graph.get(curNode.num)){
                if(dist[nextNode.num] > nextNode.dist + curNode.dist){
                    dist[nextNode.num] = nextNode.dist + curNode.dist;
                    pq.add(new Node(nextNode.num, dist[nextNode.num]));
                }
            }
        }
        int answer = 0;
        for(int i = 1; i <= N; i++){
            if(dist[i] <= K) answer++;
        }
        return answer;
    }
}

public class Problem1{
    public static void main(String[] args) {

    }
}