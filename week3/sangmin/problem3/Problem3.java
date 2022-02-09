package week3.sangmin.problem3;

import java.util.*;

class Solution{
    static Map<String, Integer> map = new HashMap<>();
    static int max;

    static void setSubString(String str, char[] token, int idx, int startIdx, int cnt, int size){
        if(size == cnt){
            String tk = new String(token);
            if(map.containsKey(tk)){
                max = Math.max(max, map.get(tk) + 1);
                map.put(tk, map.get(tk) + 1);
                return;
            }
            map.put(tk,1);
            return;
        }
        for(int i = idx; i < str.length(); i++){
            token[startIdx] = str.charAt(i);
            setSubString(str, token, i + 1, startIdx + 1, cnt + 1, size);
        }

    }

    public String[] solution(String[] orders, int[] course) {
        List<String> result = new ArrayList<>();
        String[] answer = {};

        for(int size : course){
            map.clear();
            max = 2;
            for(String str : orders){
                char[] sortStr = str.toCharArray();
                Arrays.sort(sortStr);
                setSubString(new String(sortStr), new char[size], 0,0, 0, size);
            }
            Iterator iter = map.keySet().iterator();
            while (iter.hasNext()){
                String key = (String) iter.next();
                if(map.get(key) == max){
                    result.add(key);
                }
            }
        }
        answer = result.toArray(new String[result.size()]);
        Arrays.sort(answer);
        return answer;
    }
}

public class Problem3 {

    public static void main(String[] args) {
        new Solution().solution(new String[]{"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"}, new int[]{2,3,4});
        new Solution().solution(new String[]{"XYZ", "XWY", "WXA"}, new int[]{2,3,4});
    }
}
