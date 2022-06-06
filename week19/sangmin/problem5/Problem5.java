package week19.sangmin.problem5;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    int result;
    int convertTime(String row){
        String[] token = row.split(":");
        return Integer.parseInt(token[0]) * 60 + Integer.parseInt(token[1]);
    }

    int getTime(int shuttleArrivalTime, int m, int[] timetable, int startTimeTableIdx){
        //다음 승객 차례를 리턴해줌
        List<Integer> list = new ArrayList<>();
        int idx;

        for(idx = startTimeTableIdx; idx < timetable.length; idx++){
            // List에 shuttleArrival 보다 적고 count가 m보다 작을때까지 넣어줌
            int curTime = timetable[idx];

            if(curTime <= shuttleArrivalTime) list.add(curTime);
            else break;

            if(list.size() == m){
                idx++;
                break;
            }
        }

        if(list.size() == m){ //만약 크기가 m이라면 맨 뒤에 애 - 1분
            result = list.get(list.size() - 1) - 1;
        }else{ //만약 크기가 m보다 작다면 shuttleArrivalTime
            result = shuttleArrivalTime;
        }
        return idx;
    }

    public String solution(int n, int t, int m, String[] timetable) {
        int shuttleArrivalTime = 9 * 60;
        int startTimeTableIdx = 0;
        int[] convertTimeTable = new int[timetable.length];
        for(int i = 0; i < timetable.length; i++){
            convertTimeTable[i] = convertTime(timetable[i]);
        }
        Arrays.sort(convertTimeTable);
        for(int shuttle = 0; shuttle < n; shuttle++){
            startTimeTableIdx = getTime(shuttleArrivalTime, m, convertTimeTable, startTimeTableIdx);
            shuttleArrivalTime += t;
        }
        String answer = String.format("%02d:%02d", result/60, result%60);
        return answer;
    }
}

public class Problem5 {
    public static void main(String[] args) {
//        new Solution().solution(1, 1, 5, new String[]{"08:00", "08:01", "08:02", "08:03"});
//        new Solution().solution(2, 10, 2, new String[]{"09:10", "09:09", "08:00"});
//        new Solution().solution(10, 60, 45, new String[]{"23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"});
//        new Solution().solution(1, 1, 5, new String[]{"00:01", "00:01", "00:01", "00:01", "00:01"});
//        new Solution().solution(1, 10, 3, new String[]{"08:55", "08:55", "08:59"});
//        new Solution().solution(10, 25, 1, new String[]{ "09:00", "09:10" ,"09:20" ,"09:30" ,"09:40" ,"09:50", "10:00", "10:10" ,"10:20" ,"10:30" ,"10:40" ,"10:50" });
    }
}
