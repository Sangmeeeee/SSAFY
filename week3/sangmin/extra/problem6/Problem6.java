package week3.sangmin.extra.problem6;

import java.util.Scanner;

public class Problem6 {
    public static void main(String[] args) {
        long min, max;
        Scanner scanner = new Scanner(System.in);
        min = scanner.nextLong();
        max = scanner.nextLong();
        boolean[] isOk = new boolean[(int)(max - min) + 1];

        long start = 2L;
        int count = 0;
        while(start * start <= max){
            long pivot = min % (start * start);
            long temp;
            if(pivot != 0) {
                temp = min + start * start - pivot;
            }else{
                temp = min;
            }
            for(; temp <= max; temp += (start*start)){
                if(isOk[(int)(temp - min)] == false) {
                    isOk[(int)(temp - min)] = true;
                    count++;
                }
            }
            start++;
        }
        System.out.println(max - min + 1 - count);
    }
}


// 1 1000000