package week16.sangmin.problem1;

import java.util.HashMap;
import java.util.Map;
import java.util.regex.Pattern;

class Solution {
    public int solution(String str1, String str2) {

        String regex = "[a-z][a-z]";
        str1 = str1.toLowerCase();
        str2 = str2.toLowerCase();

        int fisrtSubStringCount = 0;
        int secondSubStringCount = 0;
        int unionCount = 0;

        Map<String, Integer> map = new HashMap<>();

        for(int idx = 0; idx < str1.length() - 1; idx++) {
            String temp = str1.substring(idx, idx + 2);
            if(Pattern.matches(regex, temp)) {
                fisrtSubStringCount++;
                if(!map.containsKey(temp)) {
                    map.put(temp, 1);
                }else {
                    map.put(temp, map.get(temp) + 1);
                }
            }
        }

        for(int idx = 0; idx < str2.length() - 1; idx++) {
            String temp = str2.substring(idx, idx + 2);
            if(Pattern.matches(regex, temp)) {
                secondSubStringCount++;
                if(map.containsKey(temp)) {
                    unionCount++;
                    int afterUnion = map.get(temp) - 1;
                    if(afterUnion == 0) {
                        map.remove(temp);
                    }else {
                        map.put(temp, afterUnion);
                    }
                }
            }
        }

        return fisrtSubStringCount == 0 && secondSubStringCount == 0 ? 65536 : (int) Math.floor((double) unionCount / (fisrtSubStringCount + secondSubStringCount - unionCount) * 65536);
    }
}

public class Problem1 {
    public static void main(String[] args) {

    }
}
