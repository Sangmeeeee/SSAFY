package com.inteli.study.week6.d0303;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem4 {
    static StringBuilder S,T;
    static void deleteT(){
        char last= T.charAt(T.length()-1);
        T.delete(T.length()-1,T.length());
        if(last =='B'){
            T.reverse();
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        S = new StringBuilder();
        T = new StringBuilder();
        S.append(br.readLine());
        T.append(br.readLine());
        if(S.length()>T.length()){
            System.out.println(0);
            return;
        }
        else{
            while(S.length()!=T.length()){
                deleteT();
            }
        }
        if(S.toString().equals(T.toString())){
            System.out.println(1);
        }else{
            System.out.println(0);
        }
    }
}
//https://www.acmicpc.net/problem/12904
//A와 B

//삭제가 맞는듯?
//뒤보고 숫자 같아졌을때 체크
//reverse 가 있길래 StringBuilder썼음(String 변환이 잘 될거 같았음)