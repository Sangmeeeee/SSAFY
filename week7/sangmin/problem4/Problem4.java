package week7.sangmin.problem4;

import java.util.Scanner;

public class Problem4 {
    static long N;

    static void find(long left, long cur_size, long cur_k) {
        if(cur_size == 3) {
            System.out.println(N == 1 ? "m" : "o");
            return;
        }
        long before_size = (cur_size - (cur_k + 3)) / 2;
        long mid = left + before_size;
        long right_start = mid + cur_k + 3;
        if(N < mid) {
            find(left,  before_size, cur_k - 1);
        }else if(mid <= N && N < right_start) {
            System.out.println(N - mid == 0 ? "m" : "o");
            return;
        }else if(right_start <= N){
            N -= right_start;
            N++;
            find(left, before_size, cur_k - 1);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextLong();

        long k = 0;
        long size = 3;
        while(true) {
            k++;
            if( 2 * size + k + 3 >= N) {
                find(1, 2 * size + k + 3, k);
                break;
            }
            size = 2 * size + k + 3;
        }
    }
}