package week9.sangmin.problem1;
import java.util.Arrays;
import java.util.Scanner;

class Pair implements Comparable<Pair>{
    int A, B;

    public Pair(int a, int b) {
        A = a;
        B = b;
    }

    @Override
    public int compareTo(Pair o) {
        return Integer.compare(this.A, o.A);
    }
}

public class Problem1 {
    static int N;
    static Pair[] pairs;
    static int[] dp;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        pairs = new Pair[N];
        dp = new int[N];

        for(int i = 0; i < N; i++) {
            pairs[i] = new Pair(sc.nextInt(), sc.nextInt());
        }

        Arrays.sort(pairs);
        int result = Integer.MIN_VALUE;
        Arrays.fill(dp, 1);

        for(int i = 0; i < N; i++) {
            int curA = pairs[i].A;
            int curB = pairs[i].B;

            for(int j = 0; j < i; j++) {
                int beforeA = pairs[j].A;
                int beforeB = pairs[j].B;

                if(curB > beforeB) {
                    dp[i] = Math.max(dp[i] , dp[j] + 1);
                }
            }
            result = Math.max(result, dp[i]);
        }
        System.out.println(N - result);
    }
}

