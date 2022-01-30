package week1.sangmin.problem4;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Problem4 {
    public static void main(String[] args) throws Exception {
        int N, K;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        K = Integer.parseInt(br.readLine());
        int[] ary = new int[N];
        String[] lines = br.readLine().split(" ");
        for(int i = 0; i < lines.length; i++) {
            ary[i] = Integer.parseInt(lines[i]);
        }
        Arrays.sort(ary);
        int[] diff = new int[N-1];
        for(int i = 0 ; i < diff.length; i++){
            diff[i] = ary[i+1] - ary[i];
        }
        Arrays.sort(diff);
        int result = 0;
        for(int i = 0; i < diff.length - K + 1; i++){
            result += diff[i];
        }
        System.out.println(result);
    }
}


/*
10
5
20 3 14 6 7 8 18 10 12 15

6
2
1 6 9 3 6 7

 */