package week20.sangmin.problem5;

import java.util.*;

class Node{
    int y, x, dir, value;

    public Node(int y, int x, int dir, int value) {
        this.y = y;
        this.x = x;
        this.dir = dir;
        this.value = value;
    }
}

class Solution {

    int answer = Integer.MAX_VALUE;
    int map[][][] = new int[4][25][25]; // 방향, y, x
    int[] dx = {0,0,-1,1};
    int[] dy = {-1,1,0,0};

    Node makeNextNode(Node curNode, int nextY, int nextX){
        int curY = curNode.y;
        int curX = curNode.x;
        int curDir = curNode.dir;

        if(curDir == 0 || curDir == 1){
            if(curX < nextX){
                return new Node(nextY, nextX, 3, curNode.value + 600);
            }else if(curX > nextX){
                return new Node(nextY, nextX, 2, curNode.value + 600);
            }else if(curY > nextY && curDir == 0){
                return new Node(nextY, nextX, 0, curNode.value + 100);
            }else if(curY < nextY && curDir == 1){
                return new Node(nextY, nextX, 1, curNode.value + 100);
            }
        }else if(curDir == 2 || curDir == 3){
            if(curY < nextY){
                return new Node(nextY, nextX, 1, curNode.value + 600);
            }else if(curY > nextY){
                return new Node(nextY, nextX, 0, curNode.value + 600);
            }else if(curX > nextX && curDir == 2){
                return new Node(nextY, nextX, 2, curNode.value + 100);
            }else if(curX < nextX && curDir == 3){
                return new Node(nextY, nextX, 3, curNode.value + 100);
            }
        }
        return null;
    }

    void buildTrack(Node firstNode, int[][] board){
        Queue<Node> q = new LinkedList<>();
        q.add(firstNode);
        for(int dir = 0; dir < 4; dir++){
            for(int y = 0 ; y < board.length; y++){
                Arrays.fill(map[dir][y], Integer.MAX_VALUE);
            }
        }
        map[0][0][0] = 0;
        map[1][0][0] = 0;
        map[2][0][0] = 0;
        map[3][0][0] = 0;

        while (!q.isEmpty()){
            Node curNode = q.poll();

            if(curNode.y == board.length - 1 && curNode.x == board.length - 1){
                answer = Math.min(answer, curNode.value);
                continue;
            }

            for(int dir = 0; dir < 4; dir++){
                int nextY = curNode.y + dy[dir];
                int nextX = curNode.x + dx[dir];

                if(0 <= nextX && nextX < board.length && 0 <= nextY && nextY < board.length && board[nextY][nextX] != 1){
                    Node nextNode = makeNextNode(curNode, nextY, nextX);
                    if(nextNode != null && nextNode.value <= map[nextNode.dir][nextY][nextX]){
                        map[nextNode.dir][nextY][nextX] = nextNode.value;
                        q.add(nextNode);
                    }
                }
            }
        }
    }

    public int solution(int[][] board) {
        buildTrack(new Node(0, 0, 1, 0), board);
        buildTrack(new Node(0, 0, 3, 0), board);
        return answer;
    }
}

public class Problem5 {
    public static void main(String[] args) {
        new Solution().solution(new int[][]{{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,1,0,0,0},{0,0,0,1,0,0,0,1},{0,0,1,0,0,0,1,0},{0,1,0,0,0,1,0,0},{1,0,0,0,0,0,0,0}});
    }
}
