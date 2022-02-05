package com.inteli.d0202;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Week1Problem9 {
    static class Pair implements Comparable<Pair>{
        int start;
        int end;

        public Pair(int start, int end) {
            this.start = start;
            this.end = end;
        }

        @Override
        public int compareTo(Pair o) {
            if(Integer.compare(this.start ,o.start)==0){
                return  Integer.compare(this.end,this.end);//오름
            }
            return Integer.compare(this.start,o.start);//오름
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N= Integer.parseInt(br.readLine());
        String[] line;
        int startTime=0,endTime=0;
        int length=0;
        List<Pair> pairList = new ArrayList<>();
        for(int i=0;i<N;i++){
            line = br.readLine().split(" ");
            pairList.add(new Pair(Integer.parseInt(line[0]),Integer.parseInt(line[1])));
        }
        Collections.sort(pairList);
        //sol
        for(Pair p:pairList){
            if(startTime<=p.start&&p.start<=endTime){//연장
                endTime = Math.max(endTime,p.end);
            }else{//새로
                length += endTime-startTime;
                startTime=p.start;
                endTime=p.end;
            }
        }
        length+= endTime-startTime;
        System.out.println(length);
    }
}
//선긋기
//https://www.acmicpc.net/problem/2170
//선을 그었을때 그려진 선의 총길이. 근데, 중복되게 그려놓으면 한번으로 계산
// 1차원.
//입력 : 1line: 선갯수 N
// ~ : 선그을때의 두점의 위치 x,y
//출력 : 첫재 줄에 그은 선의 총 길이 출력
//자 이번에는 시간복잡도, 공간복잡도 생각하면서 풀자(N<1000000)
//3분 이해
//어떻게 풀까? : 다중조건 정렬?로 풀수는 있겠는데
//1:시작, 2: 끝
//최악의 공간복잡도 1,000,000 칸의 arrayList
//이건 좀 아니다. 저장 하는것을 없애고 바로바로!
//startTime , endTime, length
//시간복잡도는 O(NlogN) : timsort
//21분
