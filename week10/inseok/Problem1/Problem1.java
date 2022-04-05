package week10.inseok.Problem1;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Problem1 {
    private static ArrayList<Edge>[] adjList; // 도시 인접리스트
    private static int[] distance; // 1번 도시와 다른 도시간의 최단 경로

    public static void main(String[] args) {
        Problem1 s = new Problem1();
        int N = 5;
        int[][] road = {{1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2}};
        int K = 3;
        System.out.println(s.solution(N, road, K));
    }

    private static void dijkstra() {
        PriorityQueue<Edge> queue = new PriorityQueue<>();
        queue.add(new Edge(1, 0));//출발 노드 지정.
        //bfs 랑 비슷하네?
        while (!queue.isEmpty()) {//미방문 간선들 쭉 돌면서?
            Edge edge = queue.poll();
            int vertex = edge.vertex;
            int weight = edge.weight;

            if (distance[vertex] < weight) {
                continue;
            }
            //해당 노드의 간선 모두 체크하면서 갱신.
            for (int i = 0; i < adjList[vertex].size(); i++) { // 해당 도시와 연결되 있는 도시들 탐색
                int vertex2 = adjList[vertex].get(i).vertex;
                int weight2 = adjList[vertex].get(i).weight + weight;
                if (distance[vertex2] > weight2) { // 최단경로 세팅
                    distance[vertex2] = weight2;
                    queue.add(new Edge(vertex2, weight2));//최단 경로 세팅 될때는 노드를 넣어줌.
                }
            }
        }
    }
    public int solution(int N, int[][] road, int K) { // N : 마을의 개수, road : 마을번호와 비용, K : 최대 가능한 비용
        int answer = 0; //초기화 과정
        adjList = new ArrayList[N + 1];//인접리스트 1~
        distance = new int[N + 1];//거리 넣어두는 배열1~
        Arrays.fill(distance, Integer.MAX_VALUE);//max 로 초기화
        //adjList 초기화
        for (int i = 1; i <= N; i++) {
            adjList[i] = new ArrayList<>();
        }
        for (int i = 0; i < road.length; i++) {
            adjList[road[i][0]].add(new Edge(road[i][1], road[i][2]));
            adjList[road[i][1]].add(new Edge(road[i][0], road[i][2]));
        }
        distance[1] = 0; //1번 도시 - 자신 최단 경로 0
        // 다익스트라
        dijkstra();
        // 1번마을에서 K 이하 비용인 도시 개수 구하기
        for (int cost : distance) {
            if (cost <= K) { answer++; }
        }
        return answer;
    }
    private static class Edge implements Comparable<Edge> {
        int vertex; //
        int weight; //배달주문 시간

        public Edge(int vertex, int weight) {
            this.vertex = vertex;
            this.weight = weight;
        }
        @Override
        public int compareTo(Edge o) {
            return weight - o.weight;
        }
    }
}
