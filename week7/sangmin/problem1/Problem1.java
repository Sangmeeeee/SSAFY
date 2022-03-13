package week7.sangmin.problem1;

import java.util.Scanner;

public class Problem1 {
    static int N;
    static int size;
    static int[] sumAry = new int[50001];
    static int[][] dp = new int[50001][4];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        int[] ary = new int[N + 1];
        for(int i = 1; i <= N; i++){
            ary[i] = sc.nextInt();
        }
        size = sc.nextInt();
        for(int i = 1; i <= size; i++){
            sumAry[size] += ary[i];
        }
        int front = 1;
        for(int i = size+1; i <= N; i++){
            sumAry[i] += (sumAry[i-1] + ary[i] - ary[front++]);
        }

        for(int i = 1; i < 4; i++){
            for(int j = i * size; j <= N; j++){
                dp[j][i] = Math.max( dp[j - size][i - 1] + sumAry[j], dp[j-1][i] );
            }
        }
        System.out.println(dp[N][3]);
    }
}

/*
7
35 40 50 10 30 45 60
2

7
2 100 100 2 2 2 2
2
 */