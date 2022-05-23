package week17.sangmin.problem4;

import java.time.LocalTime;
import java.time.temporal.ChronoUnit;
import java.util.PriorityQueue;

class Node implements Comparable<Node>{
    int seqNum;
    long timeDiff;
    String name;
    String melody;

    public Node(int seqNum, long timeDiff, String name, String melody) {
        this.seqNum = seqNum;
        this.timeDiff = timeDiff;
        this.name = name;
        this.melody = melody;
    }

    @Override
    public int compareTo(Node o) {
        if(Long.compare(o.timeDiff, this.timeDiff) == 0){
            return Integer.compare(this.seqNum, o.seqNum);
        }
        return Long.compare(o.timeDiff, this.timeDiff);
    }
}

class Solution {

    PriorityQueue<Node> pq = new PriorityQueue<>();

    String replace(String origin){
        return origin
                .replaceAll("C#", "H")
                .replaceAll("D#", "I")
                .replaceAll("F#", "J")
                .replaceAll("G#", "K")
                .replaceAll("A#", "L");
    }

    public String solution(String m, String[] musicinfos) {
        m = replace(m);
        for(int seqNum = 0; seqNum < musicinfos.length; seqNum++){
            String musicInfo = musicinfos[seqNum];
            String[] token = musicInfo.split(",");
            String[] time = token[0].split(":");
            LocalTime startTime = LocalTime.of(Integer.parseInt(time[0]), Integer.parseInt(time[1]));
            time = token[1].split(":");
            LocalTime endTime = LocalTime.of(Integer.parseInt(time[0]), Integer.parseInt(time[1]));
            token[3] = replace(token[3]);
            long diffTime = ChronoUnit.MINUTES.between(startTime, endTime);
            if(diffTime >= token[3].length()){
                StringBuilder sb = new StringBuilder(token[3]);
                for(int i = 0; i < diffTime / token[3].length(); i++){
                    sb.append(token[3]);
                }
                for(int idx = 0; idx < token[3].length() % diffTime; idx++){
                    sb.append(token[3].charAt(idx));
                }
                pq.add(new Node(seqNum, diffTime, token[2], replace(sb.toString())));
            }else{
                StringBuilder sb = new StringBuilder();
                for(int idx = 0; idx < diffTime; idx++){
                    sb.append(token[3].charAt(idx));
                }
                pq.add(new Node(seqNum, diffTime, token[2], replace(sb.toString())));
            }
        }

        while (!pq.isEmpty()){
            Node curNode = pq.poll();
            if(curNode.melody.contains(m)){
                return curNode.name;
            }
        }
        return "(None)";
    }
}

public class Problem4 {
    public static void main(String[] args) {
//        new Solution().solution("ABCDEFG", new String[]{"12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"});
//        new Solution().solution("CC#BCC#BCC#BCC#B", new String[]{"03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"});
//        new Solution().solution("CC#BCC#BCC#BCC#B", new String[]{"03:00,03:01,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"});
    }
}
