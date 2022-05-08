package week15.sangmin.problem5;

class Solution {

    String solve(String w) {

        if(w.length() == 0) return "";
        StringBuilder nextU = null;
        StringBuilder nextV = null;

        int count = 0;
        int idx;
        boolean isCorrectString = w.charAt(0) == ')' ? false : true;
        for(idx = 0; idx < w.length(); idx++) {
            count = w.charAt(idx) == '(' ? count + 1 : count - 1;
            if(count == 0) {
                nextU = new StringBuilder(w.substring(0, idx + 1));
                break;
            }
        }

        nextV = new StringBuilder(w.substring(idx + 1, w.length()));

        if(isCorrectString) {
            return nextU.toString() + solve(nextV.toString());
        }else {
            StringBuilder temp = new StringBuilder();
            temp.append('(');
            temp.append(solve(nextV.toString()));
            temp.append(')');
            for(int i = 1; i < nextU.toString().length() - 1; i++) {
                if(nextU.charAt(i) == ')') temp.append('(');
                else temp.append(')');
            }
            return temp.toString();
        }
    }

    public String solution(String p) {
        String answer = solve(p);
        return answer;
    }
}

public class Problem5 {
    public static void main(String[] args) {
        new Solution().solution(")()(");
        new Solution().solution(")(");
        new Solution().solution("())))(((");
    }
}
