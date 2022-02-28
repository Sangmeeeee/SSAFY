package week5.sangmin.problem2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem2 {
    static char[][] map = new char[22][22];
    static int[] dx = {0,0,-1,1};
    static int[] dy = {-1,1,0,0};
    static int min = Integer.MAX_VALUE;
    static int R;
    static int C;

    static void dfs(int count, int x1, int y1, int x2, int y2){
        if(count > 10){
            return;
        }

        if((x1 < 1 || x1 > R || y1 < 1 || y1 > C) && (1 <= x2 && x2 <= R && 1 <= y2 && y2 <= C)){ // 동전 하나만 나감
            min = Math.min(min, count);
            return;
        }
        if((x2 < 1 || x2 > R || y2 < 1 || y2 > C) && (1 <= x1 && x1 <= R && 1 <= y1 && y1 <= C)){ // 동전 하나만 나감
            min = Math.min(min, count);
            return;
        }
        if((x1 < 1 || x1 > R || y1 < 1 || y1 > C) && (x2 < 1 || x2 > R || y2 < 1 || y2 > C)){ // 둘 다 나가면 그냥 종료
            return;
        }

        for(int i = 0; i < 4; i++){
            int nextX1 = x1 + dx[i]; int nextY1 = y1 + dy[i]; int nextX2 = x2 + dx[i]; int nextY2 = y2 + dy[i];
            if(map[nextY1][nextX1] == '#') {
                nextX1 = x1;
                nextY1 = y1;
            }
            if(map[nextY2][nextX2] == '#'){
                nextX2 = x2;
                nextY2 = y2;
            }
            dfs(count + 1, nextX1, nextY1, nextX2, nextY2);

        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] firstLine = br.readLine().split(" ");

        C = Integer.parseInt(firstLine[0]);
        R = Integer.parseInt(firstLine[1]);
        int x1 = -1, y1 = 0, x2 = 0, y2 = 0;

        for(int i = 1; i <= C; i++){
            String str = br.readLine();
            for(int j = 1; j <= R; j++){
                map[i][j] = str.charAt(j - 1);

                if(map[i][j] == 'o'){
                    if(x1 == -1){
                        x1 = j;
                        y1 = i;
                    }else{
                        x2 = j;
                        y2 = i;
                    }
                }
            }
        }
        dfs(0, x1, y1, x2, y2);
        if(min == Integer.MAX_VALUE){
            min = -1;
        }
        System.out.println(min);
    }
}
