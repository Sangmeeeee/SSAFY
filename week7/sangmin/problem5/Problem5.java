package week7.sangmin.problem5;

import java.util.Scanner;

public class Problem5 {

    static long[][] ary;
    static int N;

    static long[][] op(long[][] left, long[][] right){
        long[][] temp = new long[N][N];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                long sum = 0;
                for(int k = 0; k < N; k++){
                    sum += (left[i][k] * right[k][j]);
                }
                temp[i][j] = sum % 1000;
            }
        }
        return temp;
    }

    static long[][] cal(long B){
        if(B == 1){
            return ary;
        }
        long[][] before = cal(B/2);
        if(B % 2 == 0){
            return op(before, before );
        }else{
            return op(ary, op(before, before));
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        long B = sc.nextLong();
        ary = new long[N][N];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                ary[i][j] = sc.nextLong();
            }
        }
        long[][] result = cal(B);
        for(long[] line : result){
            for(long num : line){
                System.out.print(num%1000 + " ");
            }
            System.out.println();
        }
    }
}

/*
2 5
1 2
3 4

3 3
1 2 3
4 5 6
7 8 9

5 10
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1

 */