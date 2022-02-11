package com.inteli.study.week3.d0211;
import java.util.PriorityQueue;

public class Problem5 {

    public int solution(int[] scoville, int K) {
        int answer = -1;
        PriorityQueue<Long> pq = new PriorityQueue<>();//그대로 하면 minHeap (maxHeap은 Comparator.reverseOrder())
        long min=-1;
        int cnt=0;
        //input
        for(int i=0;i<scoville.length;i++){
            pq.offer((long)scoville[i]);
            if((long)scoville[i]<min)
                min = (long)scoville[i];
        }
        //sol
        while(pq.size()!=1){
            if(K <= min)break;
            long mix = pq.poll()+ 2*pq.poll();
            pq.offer(mix);
            min = pq.peek();
            cnt++;
        }
        if(pq.size()==1 && min < K)
            answer=-1;
        else{
            answer= cnt;
        }
        return answer;
    }
}
//long(9+9+9 는 int 범위 넘기때문에)
//O(nlogn)괜찮나? 범위 100만인데? 되지.. 왜 안되니.. 1,000,000 = 2^15? 백만 곱하기 15 정도일텐데
//25분