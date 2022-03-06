package week6.sangmin.problem5;

import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Problem5 {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] ary = new int[N];
        for(int i = 0; i < N; i++){
            ary[i] = sc.nextInt();
        }
        Arrays.sort(ary);
        long sum = 0;
        for(int i = 0; i < N; i++){
            if(ary[i] > sum + 1) break;
            sum += ary[i];
        }
        System.out.println(sum + 1);
    }
}