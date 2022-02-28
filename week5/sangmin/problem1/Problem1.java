package week5.sangmin.problem1;

import java.util.*;

public class Problem1 {
    static List<Long> result = new ArrayList<>();
    static char[] nums = {'0','1','2','3','4','5','6','7','8','9'};

    static void dfs(int length, char[] ary){

        if(length > ary.length){
            return;
        }

        for(int i = 0; i < nums.length; i++){
            if(ary[length - 1] > nums[i]){
                ary[length] = nums[i];
                result.add(  Long.parseLong( new String(Arrays.copyOfRange(ary,1, length+1))  )  );
                dfs(length + 1, ary);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        char[] ary = new char[11];
        ary[0] = '9' + 1;
        dfs(1, ary);
        Collections.sort(result);
        if(N >= result.size()){
            System.out.println(-1);
        }else{
            System.out.println(result.get(N));
        }
    }
}
