package week12.sangmin.problem5;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Node{
    int to, value;
    public Node(int to, int value) {
        this.to = to;
        this.value = value;
    }
}

public class Problem5 {
    static int N, M;
    static int START, END;
    static final long INF = 100 * 100 * 1000000 + 1;
    static List<List<Node>> edges = new ArrayList<>();
    static List<List<Integer>> rev = new ArrayList<>();
    static int[] earns;
    static long[] values;
    static boolean[] isVisit;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        N = Integer.parseInt(line[0]);
        START = Integer.parseInt(line[1]);
        END = Integer.parseInt(line[2]);
        M = Integer.parseInt(line[3]);

        earns = new int[N];
        values = new long[N];
        isVisit = new boolean[N];
        for(int i = 0; i < N; i++){
            edges.add(new ArrayList<>());
            rev.add(new ArrayList<>());
        }

        for(int i = 0; i < M; i++){
            line = br.readLine().split(" ");
            int start = Integer.parseInt(line[0]);
            int end = Integer.parseInt(line[1]);
            int value = Integer.parseInt(line[2]);
            edges.get(start).add(new Node(end, value));
            rev.get(end).add(start);
        }

        // END로 가는 경로중에 포함되는 Node들을 판단
        Queue<Integer> q = new LinkedList<>();
        q.add(END);
        while (!q.isEmpty()){
            int cur = q.poll();
            isVisit[cur] = true;
            for(int next : rev.get(cur)){
                if(!isVisit[next]){
                    q.add(next);
                }
            }
        }

        line = br.readLine().split(" ");
        for(int i = 0; i < N; i++){
            earns[i] = Integer.parseInt(line[i]);
        }
        Arrays.fill(values, INF);
        values[START] = -earns[START];
        boolean isCycle = false;
        for(int i = 0; i <= N; i++){
            for(int from = 0; from < N; from++){
                if(values[from] == INF) continue;
                for(Node nextNode : edges.get(from)){
                    if(values[nextNode.to] > values[from] + nextNode.value - earns[nextNode.to]){
                        values[nextNode.to] = values[from] + nextNode.value - earns[nextNode.to];
                        if(isVisit[nextNode.to] && i == N){
                            isCycle = true;
                        }
                    }
                }
            }
        }
        if(isCycle){
            System.out.println("Gee");
        }else if(values[END] == INF){
            System.out.println("gg");
        }else{
            System.out.println(-values[END]);
        }
    }
}

/*
5 0 4 7
0 1 13
1 2 17
2 4 20
0 3 22
1 3 4747
2 0 10
3 4 10
0 0 0 0 0

-32

5 0 4 5
0 1 10
1 2 10
2 3 10
3 1 10
2 4 10
0 10 10 110 10

Gee

3 0 2 3
0 1 10
1 0 10
2 1 10
1000 1000 47000

gg

2 0 1 2
0 1 1000
1 1 10
11 11

Gee

1 0 0 1
0 0 10
7

7

5 0 4 7
0 1 13
1 2 17
2 4 20
0 3 22
1 3 4747
2 0 10
3 4 10
8 10 20 1 100000
99988




 */
