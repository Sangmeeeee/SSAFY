package com.inteli.d0202;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Week1Prob8 {
    static class Pair implements Comparable<Pair>{//static 써야하는 이유?
        int start;
        int end;

        public Pair(int start, int end) {
            this.start = start;
            this.end = end;
        }

        @Override
        public int compareTo(Pair o) {
            if(Integer.compare(this.end , o.end)==0){
                return Integer.compare(this.start,o.start);//start 오름
            }
            return Integer.compare(this.end , o.end);//end 오름차순
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] line;
        List<Pair> pairList = new ArrayList<>();
        int startableTime=0;
        int answer=0;


        while(N-- >0){
            line = br.readLine().split(" ");
            pairList.add(new Pair(Integer.parseInt(line[0]),Integer.parseInt(line[1])));
        }
        Collections.sort(pairList);

        for(Pair pair: pairList){
            if(startableTime <= pair.start && startableTime<=pair.end){
                startableTime= pair.end;
                answer++;
            }
        }
        System.out.println(answer);
    }
}
//https://www.acmicpc.net/problem/1931
//회의실배정
//한개의 회의실,
//입력 : 회의의 수 N , 둘쨰줄~N+1 회의 시작시간 끝나는시간
//출력 최대 사용 가능한 회의 MaxNum
//dp?
//뒤를 보면서
//다중 조건 정렬 뒤 순서(오름) , 앞 순서(오름)
//arrayList로 해보고 TreeMap 써보기 : 중복 때문에 안되겠네~
//priority Queue?
//같은거 생각!!
//35분