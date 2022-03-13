package week7.sangmin.problem2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Problem2 {
    public static void main(String[] args) throws IOException {
        Map<Long, Long> map = new HashMap<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int K = Integer.parseInt(line[0]);
        int N = Integer.parseInt(line[1]);
        long[] sum = new long[K + 1];
        line = br.readLine().split(" ");
        long result = 0;
        map.put(0L,1L);
        for(int i = 1; i <= K; i++){
            sum[i] = sum[i-1] + Long.parseLong(line[i - 1]);
            if(map.containsKey(sum[i] - N)){
                result += map.get(sum[i] - N);
            }
            if(map.containsKey(sum[i])){
                map.put(sum[i], map.get(sum[i]) + 1);
            }else{
                map.put(sum[i], 1L);
            }
        }
        System.out.println(result);
    }
}
