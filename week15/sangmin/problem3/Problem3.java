package week15.sangmin.problem3;

import java.util.LinkedList;
import java.util.Queue;

class Node{
    int y, x;

    public Node(int y, int x) {
        super();
        this.y = y;
        this.x = x;
    }
}

class Solution {

    int[] dx = {0,0,-1,1};
    int[] dy = {-1,1,0,0};
    boolean[][] isVisit;
    int maxArea = Integer.MIN_VALUE;
    int areaCount = 0;

    public void bfs(int startY, int startX, int value, int[][] picture, int m, int n) {
        int count = 0;
        areaCount++;
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(startY, startX));

        while(!q.isEmpty()) {
            Node curNode = q.poll();
            int curY = curNode.y;
            int curX = curNode.x;
            if(isVisit[curY][curX]) continue;
            count++;
            isVisit[curY][curX] = true;

            for(int dir = 0; dir < 4; dir++) {
                int nextY = curY + dy[dir];
                int nextX = curX + dx[dir];
                if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) continue;
                if(!isVisit[nextY][nextX] && picture[nextY][nextX] == value) {
                    q.add(new Node(nextY, nextX));
                }
            }
        }
        maxArea = Math.max(maxArea, count);
    }

    public int[] solution(int m, int n, int[][] picture) {

        isVisit = new boolean[m][n];

        for(int y = 0; y < m; y++) {
            for(int x = 0; x < n; x++) {
                if(isVisit[y][x] || picture[y][x] == 0) continue;
                bfs(y,x, picture[y][x], picture, m, n);
            }
        }

        int[] answer = new int[2];
        answer[0] = areaCount;
        answer[1] = maxArea;
        return answer;
    }
}

public class Problem3 {
    public static void main(String[] args) {
        new Solution().solution(6, 4, new int[][] {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}});
    }
}
