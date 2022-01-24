package week1.sangmin.extra.problem6;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.regex.Pattern;

public class Problem6 {
    public static void main(String[] args) throws Exception {
        int T;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String pattern = "(100+1+|01)+";

        T = Integer.parseInt(br.readLine());
        while(T-- > 0){
            String str = br.readLine();
            System.out.println(Pattern.matches(pattern, str) ? "YES" : "NO");
        }
    }
}

/*
3
10010111
011000100110001
0110001011001

4
10010
100101
100011111100011111
01011001

 */