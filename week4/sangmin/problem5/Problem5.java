package week4.sangmin.problem5;

import java.util.ArrayList;

class Solution{

    static ArrayList<Integer>[] list;
    static boolean[] isVisit;
    static int min = Integer.MAX_VALUE;

    static void dfs(int count, int targetIdx, int curIdx){
        isVisit[curIdx] = true;
        if(curIdx == targetIdx){
            min = Math.min(count, min);
        }
        for(int idx = 0; idx < list[curIdx].size(); idx++){
            int nextIdx = list[curIdx].get(idx);
            if(!isVisit[nextIdx]){
                dfs(count + 1, targetIdx, nextIdx);
            }
        }

        isVisit[curIdx] = false;
    }


    public int solution(String begin, String target, String[] words){
        int answer = 0;

        list = new ArrayList[ words.length + 1 ];
        isVisit = new boolean[ words.length + 1 ];
        boolean isContainTarget = false;

        for(int i = 0; i < list.length; i++){
            list[i] = new ArrayList<>();
        }
        int targetIdx = 0;
        for(int i = 0; i < list.length; i++){
            String str;

            if(i == 0) str = begin;
            else str = words[i - 1];

            if(target.equals(str)) {
                isContainTarget = true;
                targetIdx = i;
            }

            for(int j = i + 1; j < list.length; j++){
                String temp = words[j - 1];
                int differentCount = 0;

                for(int k = 0; k < str.length(); k++){
                    if(str.charAt(k) != temp.charAt(k)) differentCount++;
                }

                if(differentCount == 1){
                    list[i].add(j);
                    list[j].add(i);
                }
            }
        }

        if(!isContainTarget) answer = 0;
        else {
            dfs(0, targetIdx, 0);
            answer = min;
        }
        return answer;
    }
}

public class Problem5 {
    public static void main(String[] args) {
        new Solution().solution("hit","cog",new String[]{"hot", "dot", "dog", "lot", "log", "cog"});
        new Solution().solution("hit","cog",new String[]{"hot", "dot", "dog", "lot", "log"});
    }
}
