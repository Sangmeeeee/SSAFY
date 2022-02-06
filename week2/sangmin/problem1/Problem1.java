package week2.sangmin.problem1;

import java.util.*;

public class Problem1 {
    static int[] op = new int[4];
    static int[] ary;
    static int N;
    static int max = Integer.MIN_VALUE;
    static int min = Integer.MAX_VALUE;

    public void cal(char[] ops, int idx){
        if(idx == N - 1){
            StringBuilder sb = new StringBuilder();
            Stack<Character> stack = new Stack();
            int i = 1;
            int j = 0;
            sb.append(ary[0] + " ");
            while(i < N){
                switch (ops[j]){
                    case '+' : case '-' :
                        while(!stack.isEmpty()){
                            sb.append(stack.pop() + " ");
                        }
                        stack.push(ops[j++]);
                        break;
                    case '*' : case '/' :
                        while(!stack.isEmpty() && (stack.peek() == '*' || stack.peek() == '/')){
                            sb.append(stack.pop() + " ");
                        }
                        stack.push(ops[j++]);
                        break;
                }
                sb.append(ary[i++] + " ");
            }
            while(!stack.isEmpty()){
                sb.append(stack.pop() + " ");
            }
            String[] args = sb.toString().split(" ");
            Stack<Integer> result = new Stack<>();
            for(String arg : args){
                int num1, num2;
                if(arg.equals("+")){
                    num2 = result.pop();
                    num1 = result.pop();
                    result.push(num1 + num2);
                }else if(arg.equals("-")){
                    num2 = result.pop();
                    num1 = result.pop();
                    result.push(num1 - num2);
                }else if(arg.equals("*")){
                    num2 = result.pop();
                    num1 = result.pop();
                    result.push(num1 * num2);
                }else if(arg.equals("/")){
                    num2 = result.pop();
                    num1 = result.pop();
                    result.push(num1 / num2);
                }else{
                    result.push(Integer.parseInt(arg));
                }
            }
            max = Math.max(result.peek(), max);
            min = Math.min(result.peek(), min);
            return;
        }
        for(int i = 0; i < 4; i++){
            if(op[i] != 0){
                op[i]--;
                if(i == 0){
                    ops[idx] = '+';
                    cal(ops, idx+1);
                }else if(i == 1){
                    ops[idx] = '-';
                    cal(ops, idx+1);
                }else if(i == 2){
                    ops[idx] = '*';
                    cal(ops, idx+1);
                }else if(i == 3){
                    ops[idx] = '/';
                    cal(ops, idx+1);
                }
                op[i]++;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();ary = new int[N];

        for(int i = 0; i < N; i++){
            ary[i] = scanner.nextInt();
        }

        for(int i = 0; i < 4; i++){
            op[i] = scanner.nextInt();
        }

        new Problem1().cal(new char[N - 1], 0);
        System.out.println(max);
        System.out.println(min);
    }
}

/*
10
1 2 3 4 5 6 7 8 9 9
2 1 5 1

5
1 1 2 3 4
1 1 2 1


4
5 6 7 8
1 1 1 0

6
100 50 30 4 5 6
2 1 1 1

6
1 2 3 4 5 6
2 1 1 1

3
3 4 5
1 0 1 0

3
1 2 3
1 0 1 0

 */