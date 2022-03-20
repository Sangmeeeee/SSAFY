package week8.sangmin.extra.problem11;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Problem11 {
    static int[] ary;
    static int N;

    static int find(int target, int targetIdx) {
        int left = 0;
        int right = N - 1;
        while(left < right) {
            if(left == targetIdx) left++;
            if(right == targetIdx) right--;

            if(left >= right) break;

            int sum = ary[left] + ary[right];
            if(sum == target) {
                return 1;
            }
            if(sum > target) {
                right--;
            }else { // sum < target
                left++;
            }
        }
        return 0;
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine().trim());
        ary = new int[N];
        String[] line = br.readLine().split(" ");
        for(int i = 0; i < N; i++) {
            ary[i] = Integer.parseInt(line[i]);
        }
        Arrays.sort(ary);
        int result = 0;
        for(int i = 0; i < N; i++) {
            result += find(ary[i], i);
        }
        System.out.println(result);
    }
}