package week18.sangmin.problem2;

class Solution {

    StringBuilder sb = new StringBuilder();

    public String solution(int n, int t, int m, int p) {
        sb.append(0);
        int num = 1;
        while (sb.length() <= t * m + p){
            int temp = num++;
            StringBuilder convert = new StringBuilder();
            while (temp > 0) {
                convert.append(temp % n >= 10 ? (char)((temp % n) + 55) + "" : temp % n);
                temp /= n;
            }
            sb.append(convert.reverse());
        }
        StringBuilder result = new StringBuilder();
        for(int idx = 0; idx < t; idx++){
            result.append(sb.charAt(idx * m + p - 1));
        }
        return result.toString();
    }
}

public class Problem2 {
    public static void main(String[] args) {
        new Solution().solution(2,4,2,1);
//        new Solution().solution(16, 16, 2, 1);
//        new Solution().solution(16, 16, 2, 2);
    }
}
