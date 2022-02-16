package week4.sangmin.problem3;

import java.util.Arrays;
import java.util.Scanner;

public class Problem3 {
    static int N;
    static int M;
    static int L;
    static int[] ary;
    static int[] track;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        L = sc.nextInt();
        ary = new int[N + 2];
        ary[0] = 0;
        ary[N + 1] = L;
        track = new int[N + 1];

        for(int i = 1; i <= N; i++) {
            ary[i] = sc.nextInt();
        }

        Arrays.sort(ary);

        for(int i = 0; i < track.length; i++){
            track[i] = ary[i + 1] - ary[i];
        }

        int left = 1, right = L;
        while (left <= right){
            int mid = (left + right) / 2;
//            if(mid == 0) break;
            System.out.println(left + "\t" + mid + "\t" + right);
            int count = 0;
            for(int i = 0; i < track.length; i++){
                count += (track[i] / mid);
                if(track[i] % mid == 0) count--;
            }
            if(count > M){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        System.out.println(left);
    }
}
