package week3.sangmin.problem4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Problem4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] first = br.readLine().split(" ");

        int R = Integer.parseInt(first[0]);
        int C = Integer.parseInt(first[1]);
        char[][] lines = new char[R][C];

        int result = 0;
        Set<String> set = new HashSet<>();
        for(int i = 0 ; i < R; i++){
            result = i;
            set.clear();

            for(int j = 0; j < C; j++){ // Col을 돌면서
                char[] line = new char[R - i];
                for(int k = i; k < R; k++){ // row를 set에 넣어줌
                    line[k-i] = lines[k][j];
                }
                if(!set.add(new String(line))){
                    System.out.println(i - 1);
                    return;
                }
            }
        }
        System.out.println(result);
    }
}
