package week20.sangmin.problem1;

import java.util.*;

class Node{
    boolean isDeleted;
    Node left, right;

    public Node(boolean isDeleted, Node left, Node right) {
        this.isDeleted = isDeleted;
        this.left = left;
        this.right = right;
    }
}

class Solution {

    Node[] list = new Node[1000001];
    Stack<Node> removed = new Stack<>();
    Node curNode;

    void doCommand(String[] command){
        int dist;
        Node leftNode, rightNode;
        switch (command[0]){
            case "U" :
                dist = Integer.parseInt(command[1]);
                for(int i = 0; i < dist; i++){
                    curNode = curNode.left;
                }
                break;
            case "D" :
                dist = Integer.parseInt(command[1]);
                for(int i = 0; i < dist; i++){
                    curNode = curNode.right;
                }
                break;
            case "C" :
                curNode.isDeleted = true;
                removed.push(curNode);

                leftNode = curNode.left;
                rightNode = curNode.right;

                if(leftNode == null){
                    curNode = rightNode;
                    rightNode.left = null;
                }else if(rightNode == null){
                    curNode = leftNode;
                    leftNode.right = null;
                }else{
                    curNode = rightNode;
                    rightNode.left = leftNode;
                    leftNode.right = rightNode;
                }
                break;
            case "Z" :
                Node targetNode = removed.pop();
                leftNode = targetNode.left;
                rightNode = targetNode.right;
                targetNode.isDeleted = false;
                if(leftNode == null){
                    rightNode.left = targetNode;
                }else if(rightNode == null){
                    leftNode.right = targetNode;
                }else{
                    rightNode.left = targetNode;
                    leftNode.right = targetNode;
                }
                break;
        }
    }

    public String solution(int n, int k, String[] cmd) {
        list[0] = new Node(false, null, null);
        for(int i = 1; i < n; i++){
            Node curNode = new Node(false, null, null);
            Node prevNode = list[i - 1];
            curNode.left = prevNode;
            prevNode.right = curNode;
            list[i] = curNode;
        }
        curNode = list[k];

        for (int i = 0; i < cmd.length; i++){
            doCommand(cmd[i].split(" "));
        }

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; i++){
            sb.append( list[i].isDeleted ? 'X' : 'O');
        }
        return sb.toString();
    }
}

public class Problem1 {
    public static void main(String[] args) {
        new Solution().solution(8, 2, new String[]{"D 2","C","U 3","C","D 4","C","U 2","Z","Z"});
        new Solution().solution(8, 2, new String[]{"D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"});
    }
}
