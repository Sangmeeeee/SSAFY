package week15.sangmin.problem1;

class Solution {
    public int solution(String s) {
        int answer = Integer.MAX_VALUE;
        if(s.length() == 1) return 1;
        for(int wordLength = 1; wordLength <= s.length() / 2; wordLength++) {
            int result = 0;
            for(int startIdx = 0; startIdx + wordLength <= s.length(); startIdx += wordLength){
                String base = s.substring(startIdx, startIdx + wordLength);
                int count = 1;
                for(int nextIdx = startIdx + wordLength; nextIdx + wordLength <= s.length(); nextIdx+=wordLength){
                    if(base.equals(s.substring(nextIdx, nextIdx + wordLength))){
                        startIdx = nextIdx;
                        count++;
                    }else
                        break;
                }

                result += base.length();
                if(count != 0) result += Integer.toString(count + 1).length();
            }
            result += (s.length() % wordLength);
            answer = Math.min(result, answer);
        }
        return answer;
    }
}

public class Problem1 {
    public static void main(String[] args) {
//        new Solution().solution("aabbaccc"); // 7
//        new Solution().solution("xztjabcdabcd"); // 9
//        new Solution().solution("aaaaaaaaaaaabcd"); // 6
//        new Solution().solution("xxxxxxxxxxyyy"); // 5
    }
}
