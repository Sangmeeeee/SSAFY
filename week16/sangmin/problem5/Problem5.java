package week16.sangmin.problem5;

import java.util.*;

class Solution {

    Map<String, List<Integer>> map = new HashMap<>();

    int binarySearch(String key, int target){
        List<Integer> list = map.get(key);
        int left = 0;
        int right = list.size() - 1;

        while (left <= right){
            int middle = (left + right) / 2;
            if(list.get(middle) < target)
                left = middle + 1;
            else
                right = middle - 1;
        }

        return list.size() - left;
    }

    public int[] solution(String[] info, String[] query) {
        int[] answer = new int[query.length];
        for(String line : info){
            String[] token = line.split(" ");

            String[] langs = new String[]{token[0], "-"};
            String[] fields = new String[]{token[1], "-"};
            String[] careers = new String[]{token[2], "-"};
            String[] soulfoods = new String[]{token[3], "-"};
            for(String lang : langs)
                for(String field : fields)
                    for(String career : careers)
                        for(String soulfood : soulfoods){
                            if(map.containsKey(lang+field+career+soulfood)){
                                map.get(lang+field+career+soulfood).add(Integer.parseInt(token[4]));
                            }else{
                                map.put(lang+field+career+soulfood, new ArrayList<>());
                                map.get(lang+field+career+soulfood).add(Integer.parseInt(token[4]));
                            }
                        }
        }

        for(String key : map.keySet()){
            Collections.sort(map.get(key));
        }


        for(int i = 0; i < query.length; i++){
            String q = query[i].replaceAll(" and ", "");
            int idx = q.indexOf(" ");
            int result = 0;
            if(map.containsKey(q.substring(0, idx)))
                result = binarySearch(q.substring(0, idx), Integer.parseInt(q.substring(idx + 1)));
            answer[i] = result <= 0 ? 0 : result;
        }
        return answer;
    }
}

public class Problem5 {
    public static void main(String[] args) {
        new Solution().solution(new String[]{"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"},
                new String[]{"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"});
    }
}
