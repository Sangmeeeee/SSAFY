package week7.sangmin.extra.problem6;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Problem6 {
    static int N, M;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        N = Integer.parseInt(line[0]);
        M = Integer.parseInt(line[1]);
        int sum = 0;
        Map<Integer, Long> map = new HashMap<>();
        line = br.readLine().split(" ");
        long result = 0;
        for(int i = 0; i < N; i++){
            sum += Integer.parseInt(line[i]);
            sum %= M;
            if(map.containsKey( sum )){
                map.put(sum, map.get(sum) + 1L);
            }else{
                map.put(sum, 1L);
            }
        }
        if(map.containsKey(0)) {
            result = map.get(0);
        }
        for(int i = 0; i < M; i++){
            if(map.containsKey(i)){
                result += map.get(i) * (map.get(i) - 1) / 2;
            }
        }
        System.out.println(result);
    }
}
