package week1.sangmin.extra.problem9;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class Problem9{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[][] list = new int[N][2];
        for(int i = 0; i < N;i ++){
            String str = br.readLine();
            String[] nums = str.split(" ");
            int start = Integer.parseInt(nums[0]);
            int end = Integer.parseInt(nums[1]);
            list[i][0] = start;
            list[i][1] = end;
        }
        Arrays.sort(list,new Comparator<int[]>()
        {
            @Override public int compare(int[] o1, int[] o2) {
                if(o1[0] == o2[0]) {
                    return o1[1] - o2[1];
                } else {
                    return o1[0] - o2[0];
                }
            }
        });
        int start = list[0][0];
        int end = list[0][1];
        int result = 0;
        for(int i = 1; i < N; i++){
            if(start <= list[i][0] && list[i][0] <= end){
                if(end <= list[i][1]){
                    end = list[i][1];
                }
            }else if(end < list[i][0]){
                result += end - start;
                start = list[i][0];
                end = list[i][1];
            }
        }
        result += end - start;
        System.out.println(result);
    }
}

/*

4
6 7
2 5
3 5
1 3
 */