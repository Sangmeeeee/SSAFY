package week20.sangmin.problem2;

import java.util.*;

class Solution {

    Map<String, Integer> map = new HashMap<>();
    Set<String> set = new HashSet<>();
    int dist = Integer.MAX_VALUE;

    public int[] solution(String[] gems) {
        int[] answer = new int[2];
        int left = 0, right = 0;

        for(String gem : gems){
            set.add(gem);
        }

        while (true){
            if(map.size() == set.size()){
                String target = gems[left++];
                int targetCounts = map.get(target);
                if(targetCounts == 1){
                    map.remove(target);
                }else{
                    map.put(target, map.get(target) - 1);
                }
            }else if(right == gems.length){
                break;
            }
            else{
                String target = gems[right++];
                if(!map.containsKey(target)){
                    map.put(target, 1);
                }else{
                    map.put(target, map.get(target) + 1);
                }
            }

            if(map.size() == set.size()){
                if(right - left < dist){
                    dist = right - left;
                    answer[0] = left + 1;
                    answer[1] = right;
                }
            }
        }
        return answer;
    }
}

public class Problem2 {
    public static void main(String[] args) {
//        new Solution().solution(new String[]{"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"});
//        new Solution().solution(new String[]{"AA", "AB", "AC", "AA", "AC"});
//        new Solution().solution(new String[]{"XYZ", "XYZ", "XYZ"});
//        new Solution().solution(new String[]{"ZZZ", "YYY", "NNNN", "YYY", "BBB"});
//        new Solution().solution(new String[]{"ZZZ"});
//        new Solution().solution(new String[]{"A","A","A","B","B"});
//        new Solution().solution(new String[]{"A","B","B","B","B","B","B","C","B","A"});
        new Solution().solution(new String[]{"A", "A", "B"});
    }
}
