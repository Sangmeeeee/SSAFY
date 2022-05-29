package week18.sangmin.problem5;

import java.util.Arrays;

class Solution {

    int score = Integer.MIN_VALUE;
    int[] result = new int[11];

    void dfs(int n, int[] apeach_info, int[] ryan_info, int depth, int apeach, int ryan){
        if(ryan > apeach && score < ryan - apeach){ // 라이언이 어피치보다 점수가 높고 둘의 차이가 가장 클 경우
            score = ryan - apeach;
            result = Arrays.copyOf(ryan_info, ryan_info.length);
            for(int temp = n; temp > 0; temp--){ // 0점에 남은 화살을 모두 쏴준다.
                result[10]++;
            }
        }
        if(depth == 11) return; // 점수가 11 이상은 존재하지 않음

        int needArrow = apeach_info[10 - depth] + 1; // 필요한 화살의 개수는 항상 어피치보다 1 많다.
        ryan_info[10 - depth] = needArrow;
        if(n - needArrow >= 0){ // 남은 화살 - 필요한 화살의 개수가 0 이상이여야 가능하다.
            if(needArrow == 1){ // apeach는 해당 점수가 포함되지 않음
                dfs(n - needArrow, apeach_info, ryan_info, depth + 1, apeach, ryan + depth);
            }else{
                dfs(n - needArrow, apeach_info, ryan_info, depth + 1, apeach - depth, ryan + depth);
            }
        }
        ryan_info[10 - depth] = 0; // 라이언이 포함하지 않는 경우
        dfs(n, apeach_info, ryan_info, depth + 1, apeach, ryan);
    }

    public int[] solution(int n, int[] info) {
        int apeach = 0;
        for(int i = 0; i < info.length; i++){
            if(info[i] != 0) apeach += (10 - i);
        }
        dfs(n, info, new int[11], 0, apeach,0);
        if(score == Integer.MIN_VALUE)
            return new int[]{-1};
        return result;
    }
}

public class Problem5 {
    public static void main(String[] args) {
//        new Solution().solution(5, new int[]{2,1,1,1,0,0,0,0,0,0,0});
//        new Solution().solution(1, new int[]{1,0,0,0,0,0,0,0,0,0,0});
//        new Solution().solution(9, new int[]{0,0,1,2,0,1,1,1,1,1,1});
//        new Solution().solution(10, new int[]{0,0,0,0,0,0,0,0,3,4,3});
    }
}
