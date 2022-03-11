package com.inteli.study.week7.d0308;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Problem2 {
    public static void main(String[] args) throws IOException {
        int N,K;
        long [] S;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        Map<Long,Long>map = new HashMap<>();//누적합 history

        N = Integer.parseInt(str[0]);
        K = Integer.parseInt(str[1]);
        S = new long[N];
        str = br.readLine().split(" ") ;
        //input A and get S
        S[0] = Long.parseLong(str[0]);
        for(int i=1;i<N;i++){
            S[i] = Long.parseLong(str[i]) + S[i-1];
        }
        //sol
        long answer=0;
        for (int i = 0; i < N; i++) {
            if(S[i] ==K)answer++;
            if(map.containsKey(S[i]-K)) answer+= map.get(S[i]-K);
            if(map.containsKey(S[i])){
                map.put(S[i], map.get(S[i]) + 1l);
            }
            else
                map.put(S[i], 1l);
        }
        System.out.println(answer);
    }
}
//수들의 합4
//https://www.acmicpc.net/problem/2015
//참고자료
//https://mangu.tistory.com/100
//솔직히 문제 어려웠.. map 이랑 누적합을 연결시켜서 생각하는게 너무 생소했다.
//map의 value가 빈도수, 또는 경우의 수 라는 것을 생각해보면 좋겠다.
//long.