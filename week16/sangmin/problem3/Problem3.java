package week16.sangmin.problem3;

import java.util.Stack;

class Solution {
    String op = "+-*";
    int[][] orders = {{0,1,2}, {0,2,1}, {1,0,2}, {1,2,0}, {2,0,1}, {2,1,0}};

    long parseLine(String line){
        String[] tokens = line.split(" ");
        Stack<Long> nums = new Stack<>();

        for(String token : tokens){
            if(token.equals("*") || token.equals("-") || token.equals("+")){
                long num2 = nums.pop();
                long num1 = nums.pop();

                switch (token){
                    case "*" : nums.push(num1 * num2);
                        break;
                    case "+" : nums.push(num1 + num2);
                        break;
                    case "-" : nums.push(num1 - num2);
                        break;
                }
            }else{
                nums.push(Long.parseLong(token));
            }
        }
        return nums.pop();
    }

    long calc(int[] order, String expression){
        Stack<Character> ops = new Stack<>();

        StringBuilder postOrder = new StringBuilder();

        int front = 0, rear = 0;
        for(; rear < expression.length(); rear++){
            if(expression.charAt(rear) == '+' || expression.charAt(rear) == '-' || expression.charAt(rear) == '*'){
                postOrder.append(expression.substring(front, rear) + " ");
                switch (order[op.indexOf(expression.charAt(rear))]){
                    case 0 : while (!ops.isEmpty()){
                        postOrder.append(ops.pop() + " ");
                    }
                        break;
                    case 1 : while (!ops.isEmpty() && order[op.indexOf(ops.peek())] >= 1){
                        postOrder.append(ops.pop() + " ");
                    }
                        break;
                    case 2 : while (!ops.isEmpty() && order[op.indexOf(ops.peek())] >= 2){
                        postOrder.append(ops.pop() + " ");
                    }
                        break;
                }
                ops.push(expression.charAt(rear));
                front = rear+1;
            }
        }
        postOrder.append(expression.substring(front, rear)+ " ");
        while (!ops.isEmpty()){
            postOrder.append(ops.pop() + " ");
        }
        return parseLine(postOrder.toString());
    }

    public long solution(String expression) {
        long answer = Long.MIN_VALUE;
        System.out.println(expression);
        for(int i = 0; i < 6; i++){
            answer = Math.max(Math.abs(calc(orders[i], expression)), answer);
        }
        return answer;
    }
}

public class Problem3 {
    public static void main(String[] args) {
        new Solution().solution("100-200*300-500+20");
        new Solution().solution("50*6-3*2");
//        new Solution().solution("100");
    }
}
