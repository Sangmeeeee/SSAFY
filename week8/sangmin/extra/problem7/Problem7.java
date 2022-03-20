package week8.sangmin.extra.problem7;

import java.util.Scanner;

public class Problem7 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int left = 1;
        int right = 1;
        int G = sc.nextInt();
        boolean isExist = false;
        while (true){
            int origin = right * right;
            int remember = left * left;
            int weight = origin - remember;
            if(right * right - (right - 1) * (right - 1) > 100000){
                break;
            }
            if(weight < G){
                right++;
            }else if(weight == G){
                isExist = true;
                System.out.println(right++);
            }else{
                left++;
            }
        }
        if(!isExist){
            System.out.println(-1);
        }
    }
}
