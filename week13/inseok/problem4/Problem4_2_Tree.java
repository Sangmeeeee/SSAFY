package week13.inseok.problem4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem4_2_Tree {
    static void makeSet(int[] set , int N){
        for (int i = 0; i < N; i++) {
            set[i] = i;
        }
    }
    static void union(int x, int y, int[] set){
        int ancX = find(x,set);//x의 조상
        int ancY = find(y,set);//y의 조상
        if(x==y)return;
        set[ancY] = ancX;
    }
    static int find(int x, int[] set){
       if (set[x] == x) {
            return x;
        } else {
            // 각 노드의 부모 노드를 찾아 올라간다.
            return find(set[x],set);//압축 하는 방법도 있다.
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N,M;
        N=  Integer.parseInt(br.readLine());
        M=  Integer.parseInt(br.readLine());
        int [][] adjMat=new int[N+1][N+1];
        int[] cityPlan = new int[M];
        int [] set = new int[N+1];
        //adjmat
        for (int i = 1; i <= N; i++) {
            String [] str= br.readLine().split(" ");
            for (int j = 1; j <= N; j++) {
                adjMat[i][j] = Integer.parseInt(str[j-1]);
            }
        }
        //도시 계획
        String[] str = br.readLine().split(" ");
        for (int i = 0; i < M; i++) {
            cityPlan[i] = Integer.parseInt(str[i]);
        }
        //sol
        // (make set)
        makeSet(set,N);
        //2차 for 문 union
        for (int i = 1; i <= N; i++) {
            for (int j = i+1; j <= N; j++) {
                if(adjMat[i][j] == 1){
                    union(i,j,set);
                }
            }
        }
        //cityPlan
        int originAns=find(cityPlan[0],set);
        String answer = "YES";
        for (int i=0; i < M ;i++){
            if( find(cityPlan[i] , set) != originAns){
                answer="NO";
                break;
            }
        }
        System.out.println(answer);
    }
}
//자료구조
//find를 조금 더 재귀적으로 짜서 union 까지 쉽게 만드는 방법.

//find 할때 tree depth 를 줄이는 방법도 있다.
/*
static int find(int x, int[] set){
    if (set[x] == x) {
        return x;
    } else {
        // 각 노드의 부모 노드를 찾아 올라간다.
        return find(set[x],set);//압축 하는 방법도 있다.
    }
}
*/
