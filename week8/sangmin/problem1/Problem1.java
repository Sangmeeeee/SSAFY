package week8.sangmin.problem1;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Problem1 {
    static int[] ary;
    static int N;
    static int M;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        N = Integer.parseInt(line[0]);
        M = Integer.parseInt(line[1]);

        int left = 0;
        int right = 0;
        ary = new int[N];

        for(int i = 0; i < N; i++) {
            line =  br.readLine().split(" ");
            ary[i] = Integer.parseInt(line[0]);
        }
        Arrays.sort(ary);

        int result = Integer.MAX_VALUE;

        while(right < N && left <= right) {
            if(ary[right] - ary[left] < M) { // 값이 M보다 작다면 범위를 늘려줘야한다. -> right를 당김
                right++;
            }else if(ary[right] - ary[left] == M) { // 값이 M이라면 바로 종료
                result = M;
                break;
            }else { // 값이 M보다 크다면 범위를 좁혀야한다. -> left를 당김
                result = Math.min(result, ary[right] - ary[left]);
                left++;
            }
        }
        System.out.println(result);
    }
}