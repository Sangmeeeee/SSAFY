package week19.sangmin.problem4;

import java.util.LinkedList;
import java.util.Queue;

class Solution {

    boolean isOk(int[][] key, int[][] map){
        int k = map.length + (key.length * 2) - 2;
        int[][] newMap = new int[k][k];
        int startY = 0, startX = 0;

        while (startY + key.length <= k){
            startX = 0;
            while (startX + key.length <= k){
                // copy origin
                for(int y = key.length - 1; y < key.length + map.length - 1; y++)
                    for(int x = key.length - 1; x < key.length + map.length - 1; x++)
                        newMap[y][x] = map[y - key.length + 1][x - key.length + 1];

                boolean isPossible = true;

                // key를 위치에 따라 복사해주면서 겹쳐져 있는 부분이 있으면 false
                for(int col = 0; col < key.length; col++)
                    for(int row = 0; row < key.length; row++){
                        if(key[col][row] == 1 && newMap[startY + col][startX + row] == 1) isPossible = false;
                        if(key[col][row] == 1) newMap[startY + col][startX + row] = key[col][row];
                    }

                for(int y = key.length - 1; y < key.length + map.length - 1; y++)
                    for(int x = key.length - 1; x < key.length + map.length - 1; x++)
                        if(newMap[y][x] == 0) isPossible = false;

                if(isPossible) return true;

                for(int col = 0; col < key.length; col++)
                    for(int row = 0; row < key.length; row++)
                        newMap[startY + col][startX + row] = 0;

                startX++;
            }
            startY++;
        }
        return false;
    }

    int[][] rotateRight(int m, int[][] map){
        Queue<Integer> q = new LinkedList<>();
        int[][] temp = new int[m][m];

        for(int y = 0; y < m; y++){
            for(int x = 0; x < m; x++){
                q.add(map[y][x]);
            }
            int targetX = m - 1 - y;
            for(int targetY = 0; targetY < m; targetY++){
                temp[targetY][targetX] = q.poll();
            }
        }
        return temp;
    }

    public boolean solution(int[][] key, int[][] lock) {
        if(isOk(key, lock)){
            return true;
        }else{
            key = rotateRight(key.length, key);
            if(isOk(key, lock)){
                return true;
            }else{
                key = rotateRight(key.length, key);
                if(isOk(key, lock)){
                    return true;
                }else{
                    key = rotateRight(key.length, key);
                    if(isOk(key, lock)){
                        return true;
                    }else{
                        return false;
                    }
                }
            }
        }
    }
}

public class Problem4 {
    public static void main(String[] args) {
        new Solution().solution(new int[][]{{0, 0, 0}, {1, 0, 0}, {0, 1, 1}}, new int[][]{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}});
    }
}
