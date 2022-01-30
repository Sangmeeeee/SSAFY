package week1.sangmin.problem2;

import java.io.*;
import java.util.*;

class Pair implements Comparable<Pair>{
    int key, value;
    public Pair(int key, int value){
        this.key = key;
        this.value = value;
    }

    @Override
    public int compareTo(Pair o) {
        if(this.value == o.value){
            return this.key - o.key;
        }else{
            return this.value - o.value;
        }
    }
}

public class Problem2 {
    public static void main(String[] args) throws Exception{
        int R = 3, C = 3;
        int[][] ary = new int[100][100];
        int r, c, k;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String lines = br.readLine();
        String[] nums = lines.split(" ");
        r = Integer.parseInt(nums[0]); c = Integer.parseInt(nums[1]); k = Integer.parseInt(nums[2]);

        for(int i = 0; i < 3; i++){
            lines = br.readLine();
            nums = lines.split(" ");
            ary[i][0] = Integer.parseInt(nums[0]);
            ary[i][1] = Integer.parseInt(nums[1]);
            ary[i][2] = Integer.parseInt(nums[2]);
        }
        doTask(R,C,r,c,k,ary, 0);
    }

    public static void doTask(int R, int C, int r, int c, int k, int[][] ary, int count){
        Map<Integer, Integer> map = new HashMap<>(); //
        PriorityQueue<Pair> pq = new PriorityQueue<>(); // 우선순위 큐로 key, value에서 value가 낮은 순, value가 같다면 key 순
        while(ary[r-1][c-1] != k && count <= 100){
            if(R >= C){
                int maxC = Integer.MIN_VALUE;
                for(int i = 0; i < R; i++) {
                    System.out.println();
                    map.clear();
                    for (int j = 0; j < C; j++) {
                        if(ary[i][j] == 0) continue; // ary[i][j]가 0일 수 있음

                        if(map.containsKey(ary[i][j])){
                            map.put(ary[i][j], map.get(ary[i][j]) + 1); //map에 key값이 존재하면 갱신
                        }else{
                            map.put(ary[i][j],1); // map에 key 값이 존재하지 않는다면 새로 넣어줌
                        }
                    }

                    for(Map.Entry<Integer, Integer> entry : map.entrySet()){
                        pq.add(new Pair(entry.getKey(), entry.getValue())); // map에서 값을 꺼내와 pq에 넣어줌
                    }

                    for(int l = 0; l < 100; l++){
                        ary[i][l] = 0;
                    } // 연산하기 전 해당 라인 초기화

                    if(maxC < pq.size() * 2){
                        maxC = pq.size() * 2;
                    } // pq에는 Pair가 들어있기 때문에 최대 크기는 pq.size() * 2 중 가장 큰 크기

                    int j = 0;
                    while(!pq.isEmpty()) {
                        Pair pair = pq.poll();
                        ary[i][j] = pair.key;
                        ary[i][j + 1] = pair.value;
                        j += 2;
                        // (0,1) (2,3) (4,5)
                    }
                }
                C = maxC;
                if(C > 100) C = 100; // C가 100보다 크면 100으로 지정
            }else{ // R < C
                int maxR = Integer.MIN_VALUE;
                for(int i = 0; i < C; i++) {
                    map.clear();

                    for (int j = 0; j < R; j++) {
                        if(ary[j][i] == 0) continue;
                        if(map.containsKey(ary[j][i])){
                            map.put(ary[j][i], map.get(ary[j][i]) + 1);
                        }else{
                            map.put(ary[j][i],1);
                        }
                    }

                    for(Map.Entry<Integer, Integer> entry : map.entrySet()){
                        pq.add(new Pair(entry.getKey(), entry.getValue()));
                    }

                    for(int l = 0; l < 100; l++){
                        ary[l][i] = 0;
                    }

                    if(maxR < pq.size() * 2){
                        maxR = pq.size() * 2;
                    }

                    int j = 0;
                    while(!pq.isEmpty()) {
                        Pair pair = pq.poll();
                        ary[j][i] = pair.key;
                        ary[j + 1][i] = pair.value;
                        j += 2;
                    }
                }
                R = maxR;
                if(R > 100) R = 100;
            }
            count++;
        }
        if(count == 101) count = -1;
        System.out.println(count);
    }
}

/*
3 3 100
1 2 1
2 1 3
3 3 3

1 2 3
1 2 1
2 1 3
3 3 3
 */