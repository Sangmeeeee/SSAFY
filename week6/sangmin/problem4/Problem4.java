package week6.sangmin.problem4;

import java.util.Arrays;
import java.util.Scanner;

public class Problem4 {

    static char[] reverseCopy(char[] origin, int lastIdx){
        char[] copy = new char[lastIdx];
        for(int i = 0; i < lastIdx; i++){
            copy[i] = origin[lastIdx - i - 1];
        }
        return copy;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] source = sc.nextLine().toCharArray();
        char[] target = sc.nextLine().toCharArray();

        int lastIdx = target.length;
        while (lastIdx-- > source.length){
            if(target[lastIdx] == 'B'){
                target = reverseCopy(target, lastIdx);
            }
        }
        System.out.println(Arrays.equals(source, Arrays.copyOf(target, lastIdx + 1)) ? 1 : 0);
    }
}
