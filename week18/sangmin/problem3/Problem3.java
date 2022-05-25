package week18.sangmin.problem3;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Solution {

    String regex = "[1-9]+";
    Pattern pattern = Pattern.compile(regex);

    boolean isPrime(long num){
        if(num == 1) return false;
        if(num == 2) return true;

        for(long i = 2; i <= Math.sqrt(num); i++){
            if(num % i == 0) return false;
        }

        return true;
    }

    public int solution(int n, int k) {
        int answer = 0;
        StringBuilder sb = new StringBuilder();
        while (n > 0){
            sb.append(n % k);
            n /= k;
        }
        Matcher matcher = pattern.matcher(sb.reverse().toString());
        while (matcher.find()){
            if(isPrime(Long.parseLong(matcher.group()))) answer++;
        }
        return answer;
    }
}

public class Problem3 {
    public static void main(String[] args) {
        new Solution().solution(437674, 3);
    }
}
