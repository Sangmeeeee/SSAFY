package com.inteli.study.week3.d0209;

import java.util.*;

public class Problem3 {
    static String[] orders ={"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
    static int[] course = {2,3,4};
    static boolean[] visited=null;
    static Map<String,Integer>hMap = new HashMap<>();
    static int maxVal=0;

    public static void main(String[] args) {
        String[] answer = {};
        PriorityQueue<String> pQ = new PriorityQueue<>();
        //sort
        char[] stToChar;
        for(int i=0;i< orders.length;i++){
            stToChar=orders[i].toCharArray();
            Arrays.sort(stToChar);
            orders[i] = new String(stToChar);
        }

        //for(String s : orders) System.out.println(s);
        //course 길이 마다
        for(int cIdx=0;cIdx< course.length;cIdx++){
            //init
            hMap.clear();
            maxVal=0;
            //문자열 마다 combination
            for(int oIdx=0;oIdx<orders.length;oIdx++){
                //orders 내용물의 길이가 course 길이 보다 크거나 같다면
                if(course[cIdx] <= orders[oIdx].length()){
                    visited = new boolean[orders[oIdx].length()];
                    //combinations 진행
                    combinations(0,0,orders[oIdx],course[cIdx]);
                }
            }
            /*for(String ks : hMap.keySet()){
                System.out.print(" "+ks + " ");
            }
            System.out.println();*/

            //map 에서 value 가장 큰 녀석들만 pQ 에 저장.
            for(String ks : hMap.keySet()){
                if(hMap.get(ks)==1) continue;
                if(hMap.get(ks) == maxVal){
                    pQ.add(ks);
                }
            }
        }
        //System.out.println("maxVal:"+maxVal);
        //System.out.println("pQsize:"+pQ.size());
        //pQ poll 해서 다 담기.
        answer = new String[pQ.size()];
        for(int i=0;i< answer.length;i++){
            answer[i] = pQ.poll();
        }
        //return answer;
    }
    static void combinations(int idx,int chosen,String order,int course){
        //basis
        if(chosen == course){
            StringBuilder s = new StringBuilder();
            for(int i=0;i<order.length();i++){
                if(visited[i]){
                    s.append(order.charAt(i));
                }
            }
            if(!hMap.containsKey(s.toString())){//new
                hMap.put(s.toString(),1);
            }else{//has key
                hMap.put(s.toString() , hMap.get(s.toString())+1);
                maxVal= Math.max(maxVal, hMap.get(s.toString()));
                //System.out.println("hello");
            }
            //System.out.println(s);
            return;
        }
        if(idx== order.length())return;//이거 위치가 헷

        //inductive
        visited[idx]=true;
        combinations(idx+1,chosen+1,order,course);//abcfg
        visited[idx]=false;
        combinations(idx+1,chosen,order,course);

    }

}
//70분 부터 쓰기 시작함.
//근데 아직도 잘 모르겠음.
// CD는 왜 안되는거임?