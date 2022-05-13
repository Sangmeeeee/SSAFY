package week16.sangmin.problem2;

import java.util.LinkedList;
import java.util.Queue;

class Node{
    int y,x;

    public Node(int y, int x) {
        this.y = y;
        this.x = x;
    }
}

class Solution {

    int[] dy = {-1,1,0,0};
    int[] dx = {0,0,-1,1};
    boolean isPossible;

    void bfs(int startY, int startX, String[] map){
        boolean[][] isVisit = new boolean[5][5];
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(startY, startX));

        while (!q.isEmpty()){
            Node curNode = q.poll();
            isVisit[curNode.y][curNode.x] = true;

            for(int dir = 0; dir < 4; dir++) {
                int nextY = curNode.y + dy[dir];
                int nextX = curNode.x + dx[dir];

                if(Math.abs(startY - nextY) + Math.abs(startX - nextX) <= 2){
                    if(0 <= nextX && nextX < 5 && 0 <= nextY && nextY < 5 && !isVisit[nextY][nextX]){
                        if(map[nextY].charAt(nextX) == 'O') {
                            q.add(new Node(nextY, nextX));
                        }else if(map[nextY].charAt(nextX) == 'P'){
                            isPossible = false;
                            return;
                        }
                    }
                }
            }
        }
    }

    public int[] solution(String[][] places) {
        int[] answer = new int[5];
        for (int test_case = 0; test_case < 5; test_case++){
            isPossible = true;
            for(int y = 0; y < 5; y++){
                for(int x = 0; x < 5; x++){
                    if(places[test_case][y].charAt(x) == 'P'){
                        bfs(y, x, places[test_case]);
                    }
                }
            }
            System.out.println(isPossible);
            answer[test_case] = isPossible ? 1 : 0;
        }
        return answer;
    }
}

public class Problem2 {
    public static void main(String[] args) {
//        new Solution().solution(new String[][]{{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}});
        new Solution().solution(new String[][]{{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}});
    }
}
