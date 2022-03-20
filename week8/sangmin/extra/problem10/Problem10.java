package week8.sangmin.extra.problem10;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem10 {
    static int N,S;
    static int[] ary;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        N = Integer.parseInt(line[0]);
        S = Integer.parseInt(line[1]);
        ary = new int[N];
        line = br.readLine().split(" ");
        for(int i = 0; i < N; i++){
            ary[i] = Integer.parseInt(line[i]);
        }
        int sum = 0;
        int left = 0;
        int result = Integer.MAX_VALUE;
        for(int right = 0; right < N; right++){
            sum += ary[right];
            if(sum >= S){
                while (sum >= S){
                    sum -= ary[left];
                    left++;
                }
                result = Math.min(result, right - left + 1);
            }
        }
        System.out.println(result == Integer.MAX_VALUE ? 0 : (result + 1));
    }
}

/*

10 10
10 10 10 10 10 10 10 10 10 10 10 10

10 1000
1 1 1 1 1 1 1 1 1 1


10 23
6 8 9 1 2 3 2 3 10 9 10
 */