package week4.sangmin.problem2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem2_Union_Find {
    static int findParent(int num, int[] parent) {
        if(parent[num] == 0) {
            return 0;
        }
        if(num == parent[num]) {
            return num;
        }
        return findParent(parent[num], parent);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N; int M;
        int[] parent = new int[502];
        String line[];
        int test_case = 1;
        while(true) {
            line = br.readLine().split(" ");
            N = Integer.parseInt(line[0]);
            M = Integer.parseInt(line[1]);

            if(N == 0) {
                break;
            }

            for(int i = 0; i <= N; i++) {
                parent[i] = i;
            }

            for(int i = 0; i < M; i++) {
                line = br.readLine().split(" ");
                int num1 = Integer.parseInt(line[0]);
                int num2 = Integer.parseInt(line[1]);

                int num1Parent = findParent(num1, parent);
                int num2Parent = findParent(num2, parent);

                if(num1Parent < num2Parent) {
                    parent[num2Parent] = num1Parent; // 부모의 크기가 작은쪽을 부모로 지정
                }else if(num1Parent > num2Parent){
                    parent[num1Parent] = num2Parent; // 부모의 크기가 작은쪽을 부모로 지정
                }else { // circle
                    parent[num2Parent] = num1Parent; // num1Parent == num2Parent
                    parent[num1Parent] = 0;
                }
            }


            int count = 0;

            for(int i = 1; i <= N; i++) {
                if(i == findParent(i, parent)) {
                    count++;
                }
            }

            if(count == 1) {
                System.out.println("Case " + test_case++ + ": There is one tree.");
            }else if(count > 1) {
                System.out.println("Case " + test_case++ + ": A forest of " + count + " trees.");
            }else {
                System.out.println("Case " + test_case++ + ": No trees.");
            }

        }

    }
}