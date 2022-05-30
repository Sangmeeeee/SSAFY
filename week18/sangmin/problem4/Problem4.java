package week18.sangmin.problem4;

import java.util.*;

class Solution {

    String closedTime = "23:59";
    Map<String, Integer> garage = new HashMap<>(); // Number, time
    Map<String, Integer> out = new HashMap<>(); // Number, time

    int changeTime(String time){
        String[] token = time.split(":");
        return Integer.parseInt(token[0]) * 60 + Integer.parseInt(token[1]);
    }

    public int[] solution(int[] fees, String[] records) {
        for(String record : records){
            String[] token = record.split(" ");
            String carNumber = token[1];
            if(token[2].equals("IN")){
                garage.put(carNumber, changeTime(token[0]));
            }else{
                int time = 0;
                if(out.containsKey(carNumber)){
                    time += out.get(carNumber);
                }
                time += (changeTime(token[0]) -  garage.get(carNumber));
                garage.remove(carNumber);
                out.put(carNumber, time);
            }
        }

        for(String carNumber : garage.keySet()){
            int time = 0;
            if(out.containsKey(carNumber)){
                time += out.get(carNumber);
            }
            time += (changeTime(closedTime) -  garage.get(carNumber));
            out.put(carNumber, time);
        }

        List<String> keySet = new ArrayList<>(out.keySet());
        Collections.sort(keySet);

        int[] answer = new int[keySet.size()];

        for(int i = 0; i < keySet.size(); i++){
            String key = keySet.get(i);
            int sum = fees[1];
            int time = out.get(key);
            if(time > fees[0]){
                time -= fees[0];
                sum += (Math.ceil((double)time/fees[2]) * fees[3]);
            }
            answer[i] = sum;
        }
        return answer;
    }
}

public class Problem4 {
    public static void main(String[] args) {
        new Solution().solution(new int[]{180, 5000, 10, 600}, new String[]{"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"});
    }
}
