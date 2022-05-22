package week17.sangmin.problem2;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

class Node{
    int y, x;

    public Node(int y, int x) {
        this.y = y;
        this.x = x;
    }
}

class Solution {

    int[] dy = {0,1,1}; //오 아래 대각
    int[] dx = {1,0,1};

    int bfs(int y, int x, char target, char[][] map, int m, int n, Set<Node> result){
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(y, x));
        int count = 1;

        for(int dir = 0; dir < 3; dir++){
            int nextY = y + dy[dir];
            int nextX = x + dx[dir];
            if(0 <= nextX && nextX < n && 0 <= nextY && nextY < m && map[nextY][nextX] == target){
                q.add(new Node(nextY, nextX));
                count++;
            }
        }

        if(count == 4){
            while (!q.isEmpty()){
                result.add(q.poll());
            }
        }
        return count;
    }

    public int solution(int m, int n, String[] board) {
        char[][] map = new char[m][n];
        int answer = 0;
        for(int i = 0; i < board.length; i++){
            map[i] = board[i].toCharArray();
        }

        boolean isChange;
        do {
            isChange = false;
            Set<Node> results = new HashSet<>();
            for(int y = 0; y < m; y++){
                for(int x = 0; x < n; x++) {
                    if(map[y][x] != '0'){
                        int count = bfs(y, x, map[y][x], map, m, n, results);
                        if(count == 4){
                            isChange = true;
                        }
                    }
                }
            }

            for(Node curNode : results){
                if(map[curNode.y][curNode.x] != '0') answer++;
                map[curNode.y][curNode.x] = '0';
            }

            for(int x = 0; x < n; x++){
                Queue<Character> q = new LinkedList<>();
                for(int y = m - 1; y >= 0; y--){
                    if(map[y][x] != '0') q.add(map[y][x]);
                }
                while (q.size() < n){
                    q.add('0');
                }
                for(int y = m - 1; y >= 0; y--){
                    map[y][x] = q.poll();
                }
            }
            // need to move

        } while (isChange);
        return answer;
    }
}

public class Problem2 {
    public static void main(String[] args) {
//        new Solution().solution(6, 6, new String[]{"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"});
        new Solution().solution(4, 5, new String[]{"CCBDE", "AAADE", "AAABF", "CCBBF"});
    }
}
