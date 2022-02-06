package week2.sangmin.extra.problem7;

import java.util.Arrays;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = new int[progresses.length];
        int idx = 0;
        int deployIdx = 0;
        while(deployIdx != progresses.length) {
            for(int i = 0; i < progresses.length; i++){ // works
                if (progresses[i] < 100) {
                    progresses[i] += speeds[i];
                }
            }

            if (progresses[deployIdx] >= 100) { // 배포 시작
                int count = 0;

                while(deployIdx < progresses.length && progresses[deployIdx] >= 100){
                    count++;
                    deployIdx++;
                }
                answer[idx++] = count;
            }
        }
        answer = Arrays.copyOf(answer, idx);
        return answer;
    }
}

public class Problem7 {
    public static void main(String[] args) {
        new Solution().solution(new int[]{1, 98, 97}, new int[]{100, 1, 3});
        System.out.println();
        new Solution().solution(new int[]{95, 90, 99, 99, 80, 99}, new int[]{1, 1, 1, 1, 1, 1});
        System.out.println();
        new Solution().solution(new int[]{95}, new int[]{1});
        System.out.println();
        new Solution().solution(new int[]{20, 99, 93, 30, 55, 10}, new int[]{1, 1, 1, 1, 1, 1});
        System.out.println();
        new Solution().solution(new int[]{5, 10, 1, 1, 30, 5}, new int[]{1, 1, 1, 1, 1, 1});
    }
}
