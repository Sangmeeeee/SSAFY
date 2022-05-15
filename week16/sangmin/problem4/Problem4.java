package week16.sangmin.problem4;

import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Solution {

    Map<Integer, String[]> map = new HashMap<>();
    Set<Integer> set = new HashSet<>();

    public int[] solution(String s) {
        List<Integer> list = new ArrayList<>();

        String regex = "[{][[0-9]+[,]*]+[}]";
        s = s.substring(1, s.length() - 1);
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(s);

        while (matcher.find()){
            String result = matcher.group();
            String[] token = result.substring(1, result.length() - 1).split(",");
            map.put(token.length, token);
        }

        int[] answer = new int[map.size()];
        for(int i = 1; i <= map.size(); i++){
            String[] tokens = map.get(i);
            for(String token : tokens){
                if(!set.contains(Integer.parseInt(token))){
                    answer[i - 1] = Integer.parseInt(token);
                    set.add(Integer.parseInt(token));
                }
            }
        }
        return answer;
    }
}

public class Problem4 {
    public static void main(String[] args) {
//        new Solution().solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
        new Solution().solution("{{4,2,3},{3},{2,3,4,1},{2,3}}");
    }
}
