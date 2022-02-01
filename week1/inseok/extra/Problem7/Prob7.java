package com.inteli.d0201;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Week1Prob7 {
    public static int compareIdx(StringBuilder s){
        int left,right;
        int ret=0;
        for(int i=0;i<s.length()/2;i++){//끝 앞 비교
            left =i;
            right = s.length()-(i+1);
            int comp = Character.compare(s.charAt(left),s.charAt(right));
            if(comp==0){
                continue;
            }else if(comp>0){
                ret = s.length()-1;
                break;
            }else if(comp<0){
                ret = 0;
                break;
            }
        }

        return ret;// 포문 continue라는건 abcdcba ::어느거 빼도 노상관.
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder s = new StringBuilder();
        StringBuilder T = new StringBuilder();
        int N = Integer.parseInt(br.readLine());
        for(int i=0;i<N;i++){
            s.append(br.readLine());//\n 들어갈까봐 조마했음
        }
        //sol
        for(int i=0;i<N;i++){
            int idx = compareIdx(s);//System.out.println("length:"+s.length()+" delIdx: " + idx);
            T.append(s.charAt(idx));
            s.deleteCharAt(idx);
            if(i%80==79){
                T.append("\n");
            }
        }
        System.out.println(T);
    }
}
//문자열 생성.
//n문자 문자열 S
//new 문자열 T
//규칙 :S의 가장 앞문자 하나를 T의 마지막,
// S가장 뒤 문자를 T의 마지막

//양쪽 같을때 어느거 가져 올지 판단.(public int CompareTo 써볼 예정.)
//틀,41분 
//맞 45분