package week3.sangmin.problem1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Problem1 {

    public static int sum(PriorityQueue<Integer> pq){
        int result = 0;
        while (pq.size() > 1){
            int sum = pq.poll() + pq.poll();
            result += sum;
            pq.add(sum);
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i = 0; i < N; i++){
            pq.add(Integer.parseInt(br.readLine()));
        }
        System.out.println(pq.size() == 1 ? 0 : sum(pq));
    }
}




/*
3
10
20
40
 */