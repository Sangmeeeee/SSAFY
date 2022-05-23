package week17.sangmin.problem5;

import java.util.*;

class Solution {

    String str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    Map<String, Integer> map = new HashMap<>();

    void init(){
        for(int idx = 0; idx < str.length(); idx++){
            map.put(str.charAt(idx) + "", idx + 1);
        }
    }

    public int[] solution(String msg) {
        List<Integer> list = new ArrayList<>();
        init();
        for(int idx = 0; idx < msg.length(); idx++){
            boolean isEnd = true;
            StringBuilder sb = new StringBuilder();
            sb.append(msg.charAt(idx));
            for(int nextIdx = idx + 1; nextIdx < msg.length(); nextIdx++) {
                if (!map.containsKey(sb.append(msg.charAt(nextIdx)).toString())) {
                    idx = nextIdx - 1;
                    isEnd = false;
                    break;
                }
            }
            if(!isEnd) {
                if(!map.containsKey(sb.toString())){
                    map.put(sb.toString(), map.size() + 1);
                }
                String output = sb.toString().substring(0, sb.length() - 1);
                list.add(map.get(output));
            }else{
                String output = sb.toString();
                list.add(map.get(output));
                break;
            }
        }
        int[] answer = new int[list.size()];
        for(int i = 0; i < list.size(); i++){
            answer[i] = list.get(i);
        }
        return answer;
    }
}

public class Problem5 {
    public static void main(String[] args) {
//        new Solution().solution("KAKAO");
        new Solution().solution("TOBEORNOTTOBEORTOBEORNOT");
    }
}
