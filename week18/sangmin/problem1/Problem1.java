package week18.sangmin.problem1;

import java.util.PriorityQueue;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Node implements Comparable<Node>{
    int seqNum;
    String origin;
    String head;
    int number;

    public Node(int seqNum, String origin, String head, int number) {
        this.seqNum = seqNum;
        this.origin = origin;
        this.head = head;
        this.number = number;
    }

    @Override
    public int compareTo(Node o) {
        if(head.compareTo(o.head) == 0){
            if(Integer.compare(this.number, o.number) == 0){
                return Integer.compare(this.seqNum, o.seqNum);
            }
            return Integer.compare(this.number, o.number);
        }
        return head.compareTo(o.head);
    }
}


class Solution {

    PriorityQueue<Node> pq = new PriorityQueue<>();
    String regex = "([[a-z]|[-]|[\\s]]+)([0-9]+)";
    Pattern pattern = Pattern.compile(regex);

    String[] tokenizer(String fileName){
        String[] temp = new String[2];
        Matcher matcher = pattern.matcher(fileName.toLowerCase());
        if(matcher.find()) {
            temp[0] = matcher.group(1);
            temp[1] = matcher.group(2);
        }
        return temp;
    }

    public String[] solution(String[] files) {
        String[] answer = new String[files.length];

        for(int seqNum = 0; seqNum < files.length; seqNum++){
            String[] token = tokenizer(files[seqNum]);
            pq.add(new Node(seqNum, files[seqNum], token[0], Integer.parseInt(token[1])));
        }
        int idx = 0;
        while (!pq.isEmpty()){
            answer[idx++] = pq.poll().origin;
        }
        return answer;
    }
}

public class Problem1 {

    public static void main(String[] args) {
//        new Solution().solution(new String[]{"F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"});
//        new Solution().solution(new String[]{"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"});
//        new Solution().solution(new String[]{"foo9.txt","foo010bar020.zip","F-15"});
    }
}
