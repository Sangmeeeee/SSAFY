package week4.sangmin.problem2;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Problem2_DFS {

    static boolean[] isTree;
    static boolean isCycle;

    static void dfs(List<Integer>[] list, int before, int cur){
        isTree[cur] = true;
        for(int i = 0; i < list[cur].size(); i++){
            int to = list[cur].get(i);
            if(to != before) {
                if (isTree[to] == false) {
                    dfs(list, cur, to);
                } else {
                    isCycle = true;
                }
            }
        }
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N; int M;

        String line[];
        int test_case = 1;
        while(true) {
            line = br.readLine().split(" ");
            N = Integer.parseInt(line[0]);
            M = Integer.parseInt(line[1]);

            if (N == 0 && M == 0) {
                break;
            }

            List<Integer>[] list = new List[N + 1];
            for(int i = 1; i <= N; i++){
                list[i] = new ArrayList<Integer>();
            }

            for (int i = 0; i < M; i++) {
                line = br.readLine().split(" ");
                int num1 = Integer.parseInt(line[0]);
                int num2 = Integer.parseInt(line[1]);

                list[num1].add(num2);
                list[num2].add(num1);
            }

            isTree = new boolean[N + 1];
            int count = 0;
            for(int i = 1; i <= N; i++){
                isCycle = false;
                if(!isTree[i]){
                    dfs(list, 0, i);
                    if(!isCycle){
                        count++;
                    }
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

/*
6 3
1 2
2 3
3 4
6 5
1 2
2 3
3 4
4 5
5 6
6 6
1 2
2 3
1 3
4 5
5 6
6 4
0 0

6 6
1 1
2 2
3 3
4 4
5 5
6 6

6 7
1 1
2 2
3 3
4 4
5 6
6 6
6 4

 */