package week17.sangmin.problem1;

import java.util.HashSet;
import java.util.Set;

class Solution {

    Set<String> isKey = new HashSet<>();

    void dfs(int depth, int size, Set<Integer> keys, String[][] relation){
        if(keys.size() == size){
            boolean isDuplicate = false;
            for(String iskey : isKey){
                int count = iskey.length();
                for(int idx = 0; idx < iskey.length(); idx++){
                    if(keys.contains( iskey.charAt(idx) - '0' )) count--;
                }
                if(count == 0) isDuplicate = true;
            }
            if(isDuplicate) return;

            Set<String> rows = new HashSet<>();

            for(int row = 0; row < relation.length; row++) {
                StringBuilder sb = new StringBuilder();
                for (int num : keys) {
                    sb.append(relation[row][num]);
                }
                rows.add(sb.toString());
            }

            if(rows.size() == relation.length){
                StringBuilder sb = new StringBuilder();
                for(int num : keys){
                    sb.append(num);
                }
                isKey.add(sb.toString());
            }
            return;
        }

        for(int i = depth; i < relation[0].length; i++){
            keys.add(i);
            dfs(i+1, size, keys, relation);
            keys.remove(i);
        }
    }

    public int solution(String[][] relation) {
        for(int size = 1; size <= relation[0].length; size++){
            dfs(0, size, new HashSet<>(), relation);
        }
        return isKey.size();
    }
}

public class Problem1 {
    public static void main(String[] args) {
        new Solution().solution(new String[][]{{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}});
    }
}
