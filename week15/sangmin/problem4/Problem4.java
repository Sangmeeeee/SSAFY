package week15.sangmin.problem4;

class Solution{
    char[] chars = new char[]{'A','C','F','J','M','N','R','T'};
    int count = 0;

    void dfs(int depth, char[] line, String[] data){
        if(depth == 8){ // 조건에 안걸리고 끝까지 도착하면 count + 1
            count++;
            return;
        }

        for(int idx = 0; idx < 8; idx++){ // 'A'는 0 ~ 8 번째 idx까지 들어갈 수 있음
            if(line[idx] == '0'){ // 아무데도 안들어 간 자리일경우에만 들어갈 수 있음
                if(checkCondition(data, line, chars[depth], idx)){ // 아무데도 안들어 가고 + 조건에 맞는 사람만 들어갈 수 있음
                    line[idx] = chars[depth];
                    dfs(depth + 1, line, data);
                    line[idx] = '0';
                }
            }
        }
    }

    boolean checkCondition(String[] data, char[] line, char curChar, int curCharIdx){
        for(String condition : data){
            if(curChar == condition.charAt(0) || curChar == condition.charAt(2)){ // 만약에 조건에 걸리는 사람이면
                char partnerChar = curChar == condition.charAt(0) ? condition.charAt(2) : condition.charAt(0);
                char op = condition.charAt(3);
                int range = condition.charAt(4) - '0';
                int partnerCharIdx = - 1;
                for(int i = 0; i < 8; i++){
                    if(line[i] == partnerChar){
                        partnerCharIdx = i;
                        break;
                    }
                }

                if(partnerCharIdx != -1) {
                    int realDist = Math.abs(curCharIdx - partnerCharIdx) - 1;

                    switch (op) {
                        case '=':
                            if (realDist != range) return false;
                            break;
                        case '<':
                            if (realDist >= range) return false;
                            break;
                        case '>':
                            if (realDist <= range) return false;
                            break;
                    }
                }
            }
        }
        return true;
    }

    public int solution(int n, String[] data){
        dfs(0, new char[]{'0','0','0','0','0','0','0','0'}, data);
        System.out.println(count);
        return count;
    }
}

public class Problem4 {
    public static void main(String[] args) {
        new Solution().solution(2, new String[]{"N~F=0", "R~T>2"});
        System.out.println();
//        new Solution().solution(2, new String[]{"M~C<2", "C~M>1"});
    }
}
