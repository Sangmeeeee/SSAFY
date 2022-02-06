package week2.sangmin.extra.problem6;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Problem6 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();

        Stack<Character> stack = new Stack<>();

        StringBuilder result = new StringBuilder();

        for(int i = 0; i < str.length(); i++){
            switch (str.charAt(i)){
                case '(': stack.add(str.charAt(i));
                    break;
                case ')': while (stack.peek() != '('){
                    result.append(stack.pop());
                }
                stack.pop();
                    break;
                case '+': case '-': while (!stack.isEmpty() && stack.peek() != '('){
                    result.append(stack.pop());
                }
                stack.push(str.charAt(i));
                    break;
                case '*': case '/': while (!stack.isEmpty() && (stack.peek() != '(' && stack.peek() != '+' && stack.peek() != '-' )){
                    result.append(stack.pop());
                }
                stack.push(str.charAt(i));
                    break;
                default: result.append(str.charAt(i));
                    break;
            }
        }
        while (!stack.isEmpty()){
            result.append(stack.pop());
        }
        System.out.println(result.toString());
    }
}
