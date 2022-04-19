package week13.sangmin.problem2;

import java.util.Scanner;

public class Problem2 {
    static int G, P;
    static boolean[] isDocking; // gates
    static int[] parents;

    static int findParent(int num) {
        if(num == parents[num]) {
            return num;
        }
        parents[num] = findParent(parents[num]);
        return parents[num];
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        G = sc.nextInt();

        isDocking = new boolean[G + 1];
        parents = new int[G + 1];
        for(int i = 0; i <= G; i++) {
            parents[i] = i;
        }

        P = sc.nextInt();
        for(int i = 0; i < P; i++) {
            int plain = sc.nextInt();
            if(!isDocking[plain]) { // 만약 docking이 안되있다면 해당 gate에 안착
                isDocking[plain] = true;

                if(parents[plain] == plain && plain != 1) { // gate에 안착하고 만약 parents가 초기화 상태라면 plain - 1로 부모를 정해줌
                    parents[plain] = plain - 1;
                }
            }else {
                int parent = findParent(plain); // findParent하면서 flat하게 바꾸어줌
                if(!isDocking[parent]) { // 부모까지 가서 docking이 안되있다면 해당 gate에 안착
                    isDocking[parent] = true;

                    if(parents[parent] == parent && parent != 1) { // gate에 안착하고 parents가 초기화 상태라면 똑같이 parent - 1로 부모를 정해줌
                        parents[parent] = parent - 1;
                    }
                }else {
                    int result = 0;
                    for(int g = 1; g <= G; g++) {
                        if(isDocking[g]) result++;
                    }
                    System.out.println(result);
                    return;
                }
            }
        }
        int result = 0;
        for(int g = 1; g <= G; g++) {
            if(isDocking[g]) result++;
        }
        System.out.println(result);
    }
}