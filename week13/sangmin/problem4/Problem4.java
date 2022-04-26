package week13.sangmin.problem4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem4 {

    static boolean[][] edges;
    static int[] parents;
    static int N, M;

    static int findParents(int num){
        if(parents[num] == num) return num;
        return parents[num] = findParents(parents[num]);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        N = Integer.parseInt(line[0]);
        line = br.readLine().split(" ");
        M = Integer.parseInt(line[0]);

        edges = new boolean[N + 1][N + 1];
        parents = new int[N + 1];
        for(int i = 1; i <= N; i++){
            parents[i] = i;
            line = br.readLine().split(" ");
            for(int j = 1; j <= N; j++){
                if(Integer.parseInt(line[j - 1]) == 1){
                    edges[i][j] = true;
                }
            }
        }

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(edges[i][j]){
                    int leftParent = findParents(i);
                    int rightParent = findParents(j);
                    if(leftParent != rightParent){
                        parents[leftParent] = rightParent;
                    }
                }
            }
        }

        line = br.readLine().split(" ");
        for(int i = 0; i < line.length - 1; i++){
            int left = Integer.parseInt(line[i]);
            int right = Integer.parseInt(line[i + 1]);
            int leftParent = findParents(left);
            int rightParent = findParents(right);
            if(leftParent != rightParent){
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}


/*
3
3
0 1 0
1 0 1
0 1 0
1 2 3
YES

3
3
0 1 0
1 0 0
0 0 0
1 2 3
NO
 */