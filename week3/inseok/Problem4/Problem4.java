package com.inteli.study.week3.d0210;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Problem4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int R,C;
        String[] cmd;
        StringBuilder[] sbArr=null ;
        String line;
        Set<String> stSet ;//이게 맞는듯?
        int count=0;
        //input
        cmd = br.readLine().split(" ");
        R = Integer.parseInt(cmd[0]);
        C = Integer.parseInt(cmd[1]);
        sbArr = new StringBuilder[C];//construct each! 아하 이렇게 해야하는구나!

        for(int i=0;i< sbArr.length;i++){
            sbArr[i]= new StringBuilder();
        }
        /*for(StringBuilder sb :sbArr){//이건 왜 안되지?
            sb = new StringBuilder();
        }*/

        br.readLine();//젤 첫째줄 필요 없음.
        for(int i=1;i<R;i++){
            line = br.readLine();
            for (int j = 0; j < C; j++) {
                sbArr[j].append(Character.toString(line.charAt(j)));
            }
        }

        for(int li=1;li<R;li++){
            boolean flag=false;
            stSet= new HashSet<>();
            //add set & check
            for(int i=0;i<C;i++){
                if(!stSet.contains(sbArr[i].toString())){
                    stSet.add(sbArr[i].toString());
                }else{
                    flag=true;
                }
            }
            //
            if(flag){
                break;
            }
            //delete
            for(int i=0;i<C;i++){
                sbArr[i].replace(0,1,"");
            }

            //count++
            count++;
        }
        System.out.println(count);
    }
}
//30분(string 만드는데) consturct를 못해서.. 저거 readme 쓰자.
//50분
//메모리 초과 뜬 이유
//바꿨을때 어떻게 바꿨는지(hashSet 객체 계속 새로 만들어주면서)
//해쉬셋 쓴 이유 (해쉬맵이랑 고민했음)
//sbArr[] 를 생성하는 방법.