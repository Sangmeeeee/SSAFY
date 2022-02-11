package week3.sangmin.problem5;

import java.util.PriorityQueue;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Long> pq = new PriorityQueue<>();

        for(int s : scoville){
            pq.add((long) s);
        }

        while (pq.peek() < K && pq.size() >= 2){
            pq.add(pq.poll() + (2 * pq.poll()));
            answer++;
        }

        System.out.println(answer);

        if(answer == 0 || pq.peek() < K) return -1;
        return answer;
    }
}

public class Problem5 {
    public static void main(String[] args) {
        new Solution().solution(new int[]{1, 2, 3, 9, 10, 12}, 7);
        new Solution().solution(new int[]{1, 2}, 7);
    }
}
