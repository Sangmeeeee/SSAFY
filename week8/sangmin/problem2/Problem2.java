package week8.sangmin.problem2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Problem2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int min = Integer.MAX_VALUE;
        int N = Integer.parseInt(br.readLine());
        int[] ary = new int[N];
        String[] line = br.readLine().split(" ");
        for(int i = 0; i < N; i++){
            ary[i] = Integer.parseInt(line[i]);
        }
        Arrays.sort(ary);
        int left = 0;
        int right = N - 1;
        int leftNum = ary[0];
        int rightNum = ary[1];

        while(left < right){
            int sum = ary[left] + ary[right];
            if(Math.abs(sum) < min){
                min = Math.abs(sum);
                leftNum = ary[left];
                rightNum = ary[right];
            }

            if(sum > 0){
                right--;
            }else if(sum == 0){
                System.out.println(leftNum + " " + rightNum);
                return;
            }else{
                left++;
            }
        }
        System.out.println(leftNum + " " + rightNum);
    }
}
