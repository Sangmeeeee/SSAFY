package week5.sangmin.problem3;
import java.util.Scanner;

public class Problem3 {

    static int result = 0;
    static int N, X;
    static Long L, R;

    static int[] problem = new int[15];

    static void dfs(int beforeCount, int count, int idx, Long sum, Long max, Long min) {
        if(count >= 2) {
            if(L <= sum && sum <= R && X <= max - min && beforeCount != count) {
                result++;
            }
        }
        if(idx >= N || sum > R) {
            return;
        }
        // 포함 x
        dfs(count, count, idx + 1, sum, max, min);

        // 포함 o
        max = Math.max(max, problem[idx]);
        min = Math.min(min, problem[idx]);
        dfs(count, count + 1, idx + 1, sum + problem[idx], max, min);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        L = sc.nextLong();
        R = sc.nextLong();
        X = sc.nextInt();

        for(int i = 0; i < N; i++){
            problem[i] = sc.nextInt();
        }

        dfs(0, 0, 0, 0L, Long.MIN_VALUE, Long.MAX_VALUE);
        System.out.println(result);
    }
}