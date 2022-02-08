package week3.sangmin.problem2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Problem2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for(int test_case = 0; test_case < T; test_case++){
            int N = Integer.parseInt(br.readLine());
            PriorityQueue<Long> pq = new PriorityQueue<>();
            for(String num : br.readLine().split(" ")){
                pq.add(Long.parseLong(num));
            }
            Long result = 0L;
            while (pq.size() > 1){
                Long sum = pq.poll() + pq.poll();
                result += sum;
                pq.add(sum);
            }
            System.out.println(result);
        }
    }
}

/*
3
4
40 30 30 50
15
1 21 3 4 5 35 5 4 3 5 98 21 14 17 32
3
30 30 30



30 + 30 = 60 30
60 + 30 = 90
90 + 60 = 150

 */