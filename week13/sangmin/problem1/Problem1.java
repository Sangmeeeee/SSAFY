package week13.sangmin.problem1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Problem1 {

    static int N, M;
    static List<List<Integer>> parties = new ArrayList<>(); // 파티 정보
    static int[] parents; // 부모 저장
    static boolean[] isKnown; // 알고있는 사람들인지?

    static int findParent(int num){
        if(parents[num] == num) return num;
        parents[num] = findParent(parents[num]);
        return parents[num];
    }

    static void union(int num1, int num2){ // 부모는 무조건 알고있는 사람이 되야한다. 그게 아니라면 상관 없음
        if(isKnown[num1]){
            parents[num2] = num1;
        }else if(isKnown[num2]){
            parents[num1] = num2;
        }else{
            parents[num2] = num1;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        N = Integer.parseInt(line[0]);
        parents = new int[N + 1];
        for(int i = 0; i <= N; i++){
            parents[i] = i;
        }
        isKnown = new boolean[N + 1];

        M = Integer.parseInt(line[1]);
        for(int i = 0; i < M; i++){
            parties.add(new ArrayList<>());
        }

        line = br.readLine().split(" ");
        for(int i = 0; i < Integer.parseInt(line[0]); i++){
            isKnown[Integer.parseInt(line[i + 1])] = true;
        }

        for(int i = 0; i < M; i++){
            line = br.readLine().split(" ");
            int peoples = Integer.parseInt(line[0]);
            for(int j = 0; j < peoples; j++){
                parties.get(i).add(Integer.parseInt(line[j + 1]));
            }
        }

        for(int i = 0; i < M; i++){
            for(int idx = 0; idx < parties.get(i).size() - 1; idx++){
                int num1 = parties.get(i).get(idx);
                int num2 = parties.get(i).get(idx + 1);
                int parent1 = findParent(num1);
                int parent2 = findParent(num2);
                if(parent1 != parent2){
                    union(parent1, parent2);
                }
            }
        }
        int notPossible = 0;
        for(int i = 0; i < M; i++){
            for(int pepole : parties.get(i)){
                if(isKnown[findParent(pepole)]){
                    notPossible++;
                    break;
                }
            }
        }
        System.out.println(M - notPossible);
    }
}

/*
10 9
4 1 2 3 4
2 5 1
2 6 2
1 7
1 8
2 7 8
1 9
1 10
2 3 10
1 4

만약 생각없이 union 해주면 아래와 같은 경우 틀린 답이 되버림
    static void union(int num1, int num2){
        parents[num2] = num1;
    }
10 9
4 1 2 3 4
2 6 2
2 5 1
1 7
1 8
2 7 8
1 9
1 10
2 3 10
1 4
 */