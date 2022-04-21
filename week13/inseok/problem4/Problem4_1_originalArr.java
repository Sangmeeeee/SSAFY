package week13.inseok.problem4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem4_1_originalArr {
    static void makeSet(int[] set , int N){
        for (int i = 0; i < N; i++) {
            set[i] = i;
        }
    }
    static void union(int x, int y, int[] set){
        //x ansc
        int ans = set[x];
        //y ansc
        int ans2 = set[y];
        if(ans == ans2) return;
        if(ans > ans2){
            int temp=  ans;
            ans = ans2;
            ans2 = temp;
        }
        //쭉갱신 set[ans2] 부터 set[i] == ans2 이면, ans 으로 다 바꾸기
        for (int i = ans2 ; i < set.length; i++) {
            if(set[i]==ans2){
                set[i] = ans;
            }
        }
    }
    static int find(int x, int[] set){
        return set[x];
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

//https://gmlwjd9405.github.io/2018/08/31/algorithm-union-find.html
//https://www.acmicpc.net/problem/1976
//여행 가자


//자료구조
// 배열의 모든 원소에 무조건 그 set의 조상의 값이 들어가도록 짰다.
// find 가 완전 기초적으로 하는대신, union 을 조금 투박하게 짰다.
// union 을 무조건 조상부터 끝까지 돌아야 하기에 N 이 커지면 재귀의 overhead 보다 더 안좋아 질 수 있겠다.

// 배열로 짤 때 조상의 값을 넣는게 아니라 재귀적으로 찾아가도록 짤 수도 있다.