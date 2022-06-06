package week19.sangmin.problem3;

import java.util.*;

class Node implements Comparable<Node>{
    char word;
    int y, x;
    public Node(char word, int y, int x) {
        this.word = word;
        this.y = y;
        this.x = x;
    }

    @Override
    public int compareTo(Node o){
        if(Character.compare(this.word, o.word) == 0){
            return Integer.compare(this.y, o.y);
        }
        return Character.compare(this. word, o.word);
    }
}

class Solution {

    List<Node> list = new ArrayList<>();
    int count = 0;

    boolean colFirst(int startY, int startX, int targetY, int targetX, char[][] board){
        for (; startY < targetY; startY++) {
            if (board[startY][startX] != '.') return false;
        }
        if(startX < targetX) {
            for (; startX < targetX; startX++) {
                if(board[startY][startX] != '.') return false;
            }
        }else if(startX > targetX){
            for (; startX > targetX; startX--) {
                if(board[startY][startX] != '.') return false;
            }
        }
        return true;
    }

    boolean rowFirst(int startY, int startX, int targetY, int targetX, char[][] board){
        if(startX < targetX) {
            for (; startX < targetX; startX++) {
                if(board[startY][startX] != '.') return false;
            }
        }else if(startX > targetX){
            for (; startX > targetX; startX--) {
                if(board[startY][startX] != '.') return false;
            }
        }
        for (; startY < targetY; startY++) {
            if (board[startY][startX] != '.') return false;
        }
        return true;
    }

    public String solution(int m, int n, String[] board) {
        StringBuilder sb = new StringBuilder();
        char[][] boards = new char[board.length][board[0].length()];

        for(int y = 0; y < m; y++) {
            boards[y] = board[y].toCharArray();
            for (int x = 0; x < n; x++) {
                if (boards[y][x] != '*' && boards[y][x] != '.') {
                    count++;
                    list.add(new Node(boards[y][x], y, x));
                }
            }
        }
        count /= 2;
        Collections.sort(list);

        for(int idx = 0; idx < list.size(); idx += 2) {
            Node startNode = list.get(idx);
            Node targetNode = list.get(idx + 1);

            char word = startNode.word;
            int startY = startNode.y, startX = startNode.x;
            int targetY = targetNode.y, targetX = targetNode.x;

            boards[startY][startX] = '.';
            boards[targetY][targetX] = '.';

            if(rowFirst(startY, startX, targetY, targetX, boards) || colFirst(startY, startX, targetY, targetX, boards)){
                sb.append(word);
                list.remove(startNode);
                list.remove(targetNode);
                idx = -2;
            }else{
                boards[startY][startX] = word;
                boards[targetY][targetX] = word;
            }
        }
        return sb.toString().length() == count ? sb.toString() : "IMPOSSIBLE";
    }
}

public class Problem3 {
    public static void main(String[] args) {
        new Solution().solution(3, 3, new String[]{"DBA", "C*A", "CDB"});
        new Solution().solution(2, 4, new String[]{"NRYN", "ARYA"});
        new Solution().solution(4, 4, new String[]{".ZI.", "M.**", "MZU.", ".IU."});
    }
}
