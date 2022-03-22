package week9.sangmin.extra.problem6;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem6 {
    private final static int Z = 26;

    static long[] dp = new long[5001];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder(br.readLine());
        dp[0] = 1;
        dp[1] = 1;
        if(sb.charAt(0)=='0') {
            System.out.println("0");
            return;
        }
        for(int i = 1; i < sb.length(); i++) {
            char beforeC = sb.charAt(i - 1);
            char curC = sb.charAt(i);
            int num =  (beforeC - '0') * 10 + (curC - '0');
            // 0이 포함 X? O?
            if(curC == '0') { // 10, 20
                if(beforeC == '1' || beforeC == '2') {
                    dp[i + 1] = dp[i - 1];
                }else { // 30
                    break;
                }
            }else {
                if(num > Z) { // 37
                    dp[i + 1] = dp[i];
                }else {
                    // 02
                    if(beforeC == '0') {
                        dp[i + 1] = dp[i];
                    }else {	// 22
                        dp[i + 1] = dp[i] + dp[i - 1];
                    }
                }
            }
            dp[i] %= 1000000;
        }
        System.out.println(dp[sb.length()] % 1000000);
    }
}