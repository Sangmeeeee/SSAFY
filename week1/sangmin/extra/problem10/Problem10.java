package week1.sangmin.extra.problem10;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Pair{
    int start, end;
    public Pair(int start, int end){
        this.start = start;
        this.end = end;
    }

    @Override
    public String toString(){
        return start + " " + end;
    }
}

public class Problem10 {
    public static void main(String[] args) throws Exception {
        //11000
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        Pair[] list = new Pair[N];
        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            String[] nums = str.split(" ");
            int start = Integer.parseInt(nums[0]);
            int end = Integer.parseInt(nums[1]);
            list[i] = new Pair(start, end);
        }
        Queue<Pair> pq = new PriorityQueue<>(new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                if(o1.start == o2.start){
                    return o1.end - o2.end;
                }
                return o1.start - o2.start;
            }
        });
        pq.addAll(Arrays.asList(list));

        Queue<Pair> result = new PriorityQueue<>(new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                if(o1.end == o2.end){
                    return o1.start - o2.start;
                }
                return o1.end - o2.end;
            }
        });

        while(!pq.isEmpty()){
            if(result.isEmpty()){
                result.add(pq.poll());
                continue;
            }
            if(pq.peek().start >= result.peek().end){
                result.add(new Pair(result.peek().start, pq.peek().end));
                result.poll();
                pq.poll();
            }else{
                result.add(pq.poll());
            }
        }
        System.out.println(result.size());
//        while(!result.isEmpty()){
//            System.out.println(result.poll());
//        }
    }
}

/*
3
1 3
2 4
3 5

: 2

10
1 2
1 3
1 4
3 5
4 5
4 7
8 9
9 10
1 1
2 3

5
1 7
2 3
3 4
4 8
7 10


 */