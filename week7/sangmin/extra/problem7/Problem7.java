package week7.sangmin.extra.problem7;

import java.util.Scanner;

public class Problem7 {
    static int N;
    static char[][] map;

    static void init(){
        map[0][0] = '*';
        map[0][1] = '*';
        map[0][2] = '*';
        map[1][0] = '*';
        map[1][1] = ' ';
        map[1][2] = '*';
        map[2][0] = '*';
        map[2][1] = '*';
        map[2][2] = '*';
    }

    static void mapCopy(int k, int y, int x, boolean isMiddle){
        y *= (k/3);
        x *= (k/3);

        for(int i = 0; i < k / 3; i++){
            for(int j = 0; j < k / 3; j++){
                if(!isMiddle)
                    map[y + i][x + j] = map[0 + i][0 + j];
                else
                    map[y + i][x + j] = ' ';
            }
        }
    }

    static void copy(int k){
        // k 가 3일때 return 해줌
        if(k == 3) return;
        // k는 k - 1을 copy해줌
        copy(k / 3);
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(i == 0 && j == 0) continue;
                else if(i == 1 && j == 1){
                    mapCopy(k, i, j, true);
                }else{
                    mapCopy(k, i, j, false);
                }
            }
        }
    }

    static String aryToString(char[][] map){
        StringBuilder sb = new StringBuilder();
        for(char[] line : map){
            for(char c : line){
                sb.append(c);
            }
            sb.append('\n');
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        map = new char[N][N];
        init();
        copy(N);
        System.out.println(aryToString(map));
    }
}
