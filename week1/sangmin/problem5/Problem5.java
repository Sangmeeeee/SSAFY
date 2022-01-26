package week1.sangmin.problem5;
import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = 0;
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            stack.clear();
            for(int j = i; j < s.length(); j++) {
                add(s.charAt(j), stack);
            }

            for(int j = 0; j < i; j++) {
                add(s.charAt(j), stack);
            }
            if(stack.size() == 0)
                answer++;
        }
        return answer;
    }

    public static void add(char c, Stack<Character> stack) {
        if(stack.isEmpty()) {
            stack.add(c);
            return;
        }
        switch(c) {
            case '}' : if(stack.peek() == '{') {
                stack.pop();
            }else {
                stack.add(c);
            }
                break;
            case ')': if(stack.peek() == '(') {
                stack.pop();
            }else {
                stack.add(c);
            }
                break;
            case ']' :  if(stack.peek() == '[') {
                stack.pop();
            }else {
                stack.add(c);
            }
                break;
            default :
                stack.add(c);
        }
    }
}


public class Problem5 {
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.solution("[](){}"));
        System.out.println(solution.solution("}]()[{"));
        System.out.println(solution.solution("[)(]"));
    }
}
