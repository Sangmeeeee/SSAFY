package com.inteli.d0126;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Stack;

public class Problem3 {
    static class Pair{
        int lIdx;
        int rIdx;
        Pair(int lIdx, int rIdx){
            this.lIdx = lIdx;
            this.rIdx = rIdx;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();

        Stack<Integer> stack = new Stack<>();
        List<Pair> pairList = new ArrayList<>();

        List<String>answerList = new ArrayList<>();//compareto
        StringBuilder sb ;//= new StringBuilder();

        for(int i=0;i<line.length();i++) {
            if (line.charAt(i) == '(') {
                stack.push(i);
            } else if (line.charAt(i) == ')') {
                pairList.add(new Pair(stack.pop(), i));//앞에 삽입
            }
        }

        int [] ma = new int[line.length()];//00000000000000000
        int [] m = new int[pairList.size()];//00000

        for(int i=1;i< (1<<pairList.size());i++){
            int num = i;
            int idx = 0;
            sb = new StringBuilder();
            while(num!=0){
                m[idx++]= num%2;
                num = num/2;
            }
            for(int j=0;j<pairList.size();j++){
                if(m[j]==1){
                    ma[pairList.get(j).lIdx]=1;
                    ma[pairList.get(j).rIdx]=1;
                }
            }
            for(int j=0;j<line.length();j++){
                if(ma[j]==0){
                    sb.append(line.charAt(j));
                }
            }
            answerList.add(sb.toString());
            for(int j=0;j< pairList.size();j++){//init
                m[j]=0;
            }for(int j=0;j< line.length();j++){
                ma[j]=0;
            }
        }
        Collections.sort(answerList);

        for(int i=0;i<answerList.size()-1;i++){
            if(answerList.get(i).equals(answerList.get(i+1))){
                answerList.remove(i--);
            }
        }

        answerList.forEach(ob->System.out.println(ob));
    }
}
//괄호제거
//https://www.acmicpc.net/problem/2800

