package week6.sangmin.problem3;

import java.util.Scanner;

public class Problem3 {
    static int[][] map = new int[51][51];
    static boolean[][] isVisit = new boolean[51][51];
    static int N,M; // 세로, 가로

    static class Cleaner{
        int y,x,dir;
        int count;

        public Cleaner(int y, int x, int dir) {
            this.y = y;
            this.x = x;
            this.dir = dir;
            count = 0;
        }

        public void clean(){
            isVisit[y][x] = true;
            count++;
            searchLeft();
        }

        public void searchLeft(){
            for(int i = 0; i < 4; i++){
                int nextY = y, nextX = x;
                if(dir == 0){ // 북쪽을 바라봄
                    nextX = x - 1;
                }else if(dir == 1){ // 동쪽을 바라봄
                    nextY = y - 1;
                }else if(dir == 2){ // 남쪽을 바라봄
                    nextX = x + 1;
                }else if(dir == 3){ // 서쪽을 바라봄
                    nextY = y + 1;
                }
                if(!isVisit[nextY][nextX] && map[nextY][nextX] != 1){
                    y = nextY;
                    x = nextX;
                    if(dir == 0){ // 북쪽을 바라보고있음
                        dir = 3;
                    }else if(dir == 1){ // 동쪽을 바라보고있음
                        dir = 0;
                    }else if(dir == 2){ // 남쪽을 바라보고있음
                        dir = 1;
                    }else{ // 서쪽을 바라보고있음
                        dir = 2;
                    }
                    clean();
                    return;
                }else{
                    if(dir == 0){ // 북쪽을 바라보고있음
                        dir = 3;
                    }else if(dir == 1){ // 동쪽을 바라보고있음
                        dir = 0;
                    }else if(dir == 2){ // 남쪽을 바라보고있음
                        dir = 1;
                    }else{ // 서쪽을 바라보고있음
                        dir = 2;
                    }
                }
           }
            if(dir == 0){ // 북
                y = y + 1;
            }else if(dir == 1){ // 동
                x = x - 1;
            }else if(dir == 2){ // 남
                y = y - 1;
            } else if (dir == 3){ // 서
                x = x + 1;
            }
            if(map[y][x] == 1){
                return;
            }else{
                searchLeft();
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        Cleaner cleaner = new Cleaner(sc.nextInt(), sc.nextInt(), sc.nextInt());
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++) {
                map[i][j] = sc.nextInt();
            }
        }
        cleaner.clean();
        System.out.println(cleaner.count);
    }
}
