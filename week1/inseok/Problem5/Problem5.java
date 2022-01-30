package com.inteli.d0130;

import java.util.Stack;

class Solution {
    public int check(StringBuilder newS,Stack<Integer>stack){
        int ans;
        boolean flag=false;
        for (int idx = 0; idx < newS.length(); idx++) {
            if(flag==true)break;
            switch (newS.charAt(idx)) {
                case '(':
                    stack.push(0);
                    break;
                case '[':
                    stack.push(1);
                    break;
                case '{':
                    stack.push(2);
                    break;
                case ')':
                    if (stack.empty()) {
                        flag=true;
                    }else if (stack.pop() != 0) {
                        flag=true;
                    }
                    break;
                case ']':
                    if (stack.empty()) {
                        flag=true;
                    }else if (stack.pop() != 1) {
                        ans = 0;
                    }
                    break;
                case '}':
                    if (stack.empty()) {
                        flag=true;
                    }else if (stack.pop() != 2) {
                        flag=true;
                    }
                    break;
            }
        }
        if(flag==true)return 0;
        else return 1;
    }
    public int solution(String s) {
        int answer =0;
        StringBuilder newS = new StringBuilder();
        Stack<Integer> stack;//0:() 1:[] 2:{}

        newS.append(s);
        if(newS.length()%2!=0){//홀수 : answer=0 (효율성)
            answer=0;
            return answer;
        }

        //sol
        stack = new Stack<>();
        for(int i=0;i<newS.length();i++) {
            answer += check(newS,stack);
            char c = newS.charAt(0);
            newS.deleteCharAt(0);
            newS.append(c);
        }
        return answer;
    }
}

//O(n^2)
//week1 problem 4
//https://programmers.co.kr/learn/courses/30/lessons/76502?language=java
//48분