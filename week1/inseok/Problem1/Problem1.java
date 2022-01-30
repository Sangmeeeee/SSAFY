package com.inteli.d0124;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

//https://www.acmicpc.net/problem/9935
//문자열 폭발
//O(?)
//88분...

public class Problem1 {

    static class Block{
        int idx;//string 위치
        int bIdx;//bomb idx
        Block(int idx,int bIdx){
            this.idx = idx;
            this.bIdx = bIdx;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder newSt = new StringBuilder();
        StringBuilder bombSt = new StringBuilder();
        newSt.append(br.readLine());
        bombSt.append(br.readLine());

        //sol
        int bombIdx =0;//스택 비교위치
        int [] bombMap = new int[newSt.length()];//기본(0),제거 위치(1)
        //int stack <integer bombIdx> : 무관련글자 -> 모두pop / 뒷글자 ->push / 다찼음 ->pop 하면서 bombMap에 위치 표시
        Stack<Block> Stack = new Stack<>();

        for(int a : bombMap){a=0;}//init 필수?

        for (int i=0;i<newSt.length();i++) {
            if(newSt.charAt(i)==bombSt.charAt(bombIdx)){
                Stack.push(new Block(i,bombIdx++));
            }
            else if(newSt.charAt(i)==bombSt.charAt(0)){//0이면 스택 다시 넣어도 되는 기회
                Stack.push(new Block(i,0));
                bombIdx=1;
            }
            else {//safe
                bombIdx=0;
                while (!Stack.empty()) {
                    Stack.pop();//get bombIdx and push block again
                }
            }

            if(bombIdx==bombSt.length()){//full bomb
                bombIdx=0;
                for(int j=0;j<bombSt.length();j++){//제거
                    Block bl = Stack.pop();
                    bombMap[bl.idx]=-1;
                }
                if(!Stack.empty()){//top
                    Block bl = Stack.pop();//get bombIdx and push block again
                    bombIdx=bl.bIdx+1;
                    Stack.push(bl);
                    //System.out.println("bombIdx : "+bombIdx);
                }else{
                    bombIdx=0;
                }

            }
        }

        StringBuilder answer = new StringBuilder();
        for (int i = 0; i < bombMap.length; i++) {
            if(bombMap[i]==0)
                answer.append(newSt.charAt(i));
            //answer.append(i);
        }
        if(answer.length()==0){
            System.out.println("FRULA");
        }
        else {
            System.out.println(answer);
        }
    }
}
