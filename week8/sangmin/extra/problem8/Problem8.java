package week8.sangmin.extra.problem8;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Problem8 {

    static long[] ary;
    static long leftNum;
    static long midNum;
    static long rightNum;
    static long min = Long.MAX_VALUE;
    static void find(int left, int N){
        int right = N - 1;
        int mid = left + 1;

        while(mid < right){
            long sum = ary[left] + ary[mid] + ary[right];
            if(Math.abs(sum) < min){
                min = Math.abs(sum);
                leftNum = ary[left];
                midNum = ary[mid];
                rightNum = ary[right];
            }

            if(sum > 0){
                right--;
            }else{ // sum <= 0
                mid++;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        ary = new long[N];
        String[] line = br.readLine().split(" ");
        for(int i = 0; i < N; i++){
            ary[i] = Long.parseLong(line[i]);
        }
        Arrays.sort(ary);

        for(int i = 0; i < N - 2; i++){
            find(i,N);
        }
        System.out.println(leftNum + " " + midNum + " " + rightNum);
    }
}