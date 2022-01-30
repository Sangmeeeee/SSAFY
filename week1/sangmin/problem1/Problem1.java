package week1.sangmin.problem1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Problem1 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = br.readLine();
        String bomb = br.readLine();
        Stack<Character> stack = new Stack<>();

        for(int i = 0; i < str.length(); i++){
            stack.push(str.charAt(i));
            if(stack.size() >= bomb.length()){
                boolean isBomb = true;

                for(int j = 0; j < bomb.length(); j++){
                    if(stack.elementAt(stack.size() - 1 - j) != bomb.charAt(bomb.length() - 1 - j) ){
                        isBomb = false;
                        break;
                    }
                }

                if(isBomb){
                    for(int j = 0; j < bomb.length(); j++){
                        stack.pop();
                    }
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        if(stack.size() == 0) {
            System.out.println("FRULA");
        }
        else{
            for (int i = 0; i < stack.size(); i++) {
                sb.append(stack.elementAt(i));
            }
            System.out.println(sb.toString());
        }
    }
}

/*
mirkovC4nizCC44
C4
* */