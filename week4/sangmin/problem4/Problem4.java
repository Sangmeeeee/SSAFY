package week4.sangmin.problem4;

import java.util.ArrayList;
import java.util.Scanner;

public class Problem4 {
    static ArrayList<Integer>[] list;
    static int N;
    static int M;
    static int max = Integer.MIN_VALUE;
    static boolean[] isVisit;

    static void dfs(int node, int count, boolean[] isVisit){
        isVisit[node] = true;
        if(count == 4){
            max = 4;
            return;
        }

        for(int i = 0; i < list[node].size(); i++){
            int nextNode = list[node].get(i);
            if(!isVisit[nextNode]){
                dfs(nextNode, count + 1, isVisit);
            }
        }
        isVisit[node] = false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        list = new ArrayList[N];
        for(int i = 0; i < N; i++){
            list[i] = new ArrayList<>();
        }
        isVisit = new boolean[N];
        M = sc.nextInt();

        for(int i = 0; i < M; i++){
            int num1 = sc.nextInt();
            int num2 = sc.nextInt();

            list[num1].add(num2);
            list[num2].add(num1);
        }

        for(int i = 0; i < N; i++){
            if(max != 4) {
                dfs(i, 0, new boolean[N]);
            }
        }
        if(max == 4)
            System.out.println(1);
        else
            System.out.println(0);
    }
}

/*


 */