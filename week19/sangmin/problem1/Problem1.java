package week19.sangmin.problem1;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

class Solution {

    SimpleDateFormat simpleDateFormat = new SimpleDateFormat("HH:mm:ss.SSS");

    public int solution(String[] lines) throws ParseException {
        int[] counts = new int[lines.length];
        int max = Integer.MIN_VALUE;

        for(int idx = 0; idx < lines.length; idx++){
            String[] token = lines[idx].split(" ");
            Date baseDate = simpleDateFormat.parse(token[1]);
            long baseTime = baseDate.getTime();

            for(int nextIdx = idx; nextIdx < lines.length; nextIdx++){
                String[] nextToken = lines[nextIdx].split(" ");
                Date nextDate = simpleDateFormat.parse(nextToken[1]);
                double sec = Double.parseDouble(nextToken[2].substring(0, nextToken[2].length() - 1));

                long nextStartTime = nextDate.getTime() - (long)(sec * 1000) + 1;

                if(baseTime + 1000 > nextStartTime){
                    counts[idx]++;
                }
            }
            max = Math.max(max, counts[idx]);
        }
        return max;
    }
}

public class Problem1 {
    public static void main(String[] args) throws ParseException {
        new Solution().solution(new String[]{
                "2016-09-15 20:59:57.421 0.351s",
                "2016-09-15 20:59:58.233 1.181s",
                "2016-09-15 20:59:58.299 0.8s",
                "2016-09-15 20:59:58.688 1.041s",
                "2016-09-15 20:59:59.591 1.412s",
                "2016-09-15 21:00:00.464 1.466s",
                "2016-09-15 21:00:00.741 1.581s",
                "2016-09-15 21:00:00.748 2.31s",
                "2016-09-15 21:00:00.966 0.381s",
                "2016-09-15 21:00:02.066 2.62s"
        });
    }
}
