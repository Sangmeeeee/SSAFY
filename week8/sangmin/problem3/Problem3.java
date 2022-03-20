package week8.sangmin.problem3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Problem3 {
    static int[] inner;
    static int[] result;
    static int N, M;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        N = Integer.parseInt(line[0]);
        M = Integer.parseInt(line[1]);
        inner = new int[N];
        result = new int[N];
        Arrays.fill(result, Integer.MAX_VALUE);
        List<List<Integer>> lists = new ArrayList<>();
        for(int i = 0; i < N; i++){
            lists.add(new ArrayList<>());
        }
        // 이까지 초기화

        for(int i = 0; i < M; i++){
            line = br.readLine().split(" ");
            int from = Integer.parseInt(line[0]) - 1;
            int to = Integer.parseInt(line[1]) - 1;
            lists.get(from).add(to); // from에서 to로 가는 graph 그려줌
            inner[to]++; // 들어오는 노드 개수 count
        }

        Queue<Integer> q = new LinkedList<>();
        for(int i = 0; i < N; i++){
            if(inner[i] == 0) { // 들어오는 노드의 개수가 0이라는 소리는 시작 node라는 소리
                q.add(i);
                result[i] = 1;
            }
        }

        while(!q.isEmpty()){
            int from = q.poll();
            for(int to : lists.get(from)){
                inner[to]--;
                if(inner[to] == 0){ // 선수과목을 다 들었다는 소리니까
                    if(result[from] + 1 < result[to]){
                        result[to] = result[from] + 1;
                    }
                    q.add(to);
                }
            }
        }
        for(int num : result){
            System.out.print(num + " ");
        }
    }
}
