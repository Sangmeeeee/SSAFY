package week4.sangmin.extra.problem6;
import java.util.Arrays;
import java.util.Scanner;

public class Problem6 {

    static int N;
    static int M;
    static int[] numCards;
    static int[] nums;

    private static int lowerBound(int target){
        int left = 0;
        int right = numCards.length;

        while (left < right){
            int mid = (left + right) / 2;
            if(target <= numCards[mid]){
                right = mid;
            }else {
                left = mid + 1;
            }
        }
        return left;
    }

    private static int upperBound(int target){
        int left = 0;
        int right = numCards.length;

        while (left < right){
            int mid = (left + right) / 2;
            if(target < numCards[mid]){
                right = mid;
            }else {
                left = mid + 1;
            }
        }
        return left;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        numCards = new int[N];

        for(int i = 0; i < N; i++) {
            numCards[i] = sc.nextInt();
        }

        M = sc.nextInt();
        nums = new int[M];
        for(int i = 0; i < M; i++) {
            nums[i] = sc.nextInt();
        }

        Arrays.sort(numCards);

        StringBuilder sb = new StringBuilder();

        for(int i = 0; i < M; i++){
            sb.append(upperBound(nums[i]) - lowerBound(nums[i]) + " ");
        }
        System.out.println(sb.toString());
    }
}