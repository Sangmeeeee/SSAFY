package week15.sangmin.problem2;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;


class Solution {

    class Node{
        String uid;
        String command;

        public Node(String uid, String command) {
            this.uid = uid;
            this.command = command;
        }

        public String getCommand(){
            if(command.equals("Enter")){
                return "님이 들어왔습니다.";
            }else if(command.equals("Leave")){
                return "님이 나갔습니다.";
            }
            return null;
        }
    }

    Queue<Node> q = new LinkedList<>();
    Map<String, String> mapper = new HashMap<>(); // uuid, Enter

    public void doCommand(String[] line){
        String command = line[0];
        String uid = line[1];

        if(command.equals("Enter")){ // Enter
            mapper.put(uid, line[2]);
            q.add(new Node(uid, command));
        }else if(command.equals("Leave")){ // Leave
            q.add(new Node(uid, command));
        }else{ // Change
            mapper.put(uid, line[2]);
        }
    }

    public String[] solution(String[] record) {
        for(String lines : record){
            String[] line = lines.split(" ");
            doCommand(line);
        }
        int idx = 0;
        String[] answer = new String[q.size()];
        while (!q.isEmpty()){
            Node curNode = q.poll();
            answer[idx++] = mapper.get(curNode.uid) + curNode.getCommand();
        }
        return answer;
    }
}

public class Problem2 {
    public static void main(String[] args) {
        new Solution().solution(new String[]{"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"});
    }
}
