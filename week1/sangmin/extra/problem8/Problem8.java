package week1.sangmin.extra.problem8;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

class Pair implements Comparable<Pair>{
    int start, end;

    public Pair(int start, int end) {
        this.start = start;
        this.end = end;
    }

    @Override
    public String toString() {
        return start + " " + end;
    }

    @Override
    public int compareTo(Pair o) {
        if(this.end == o.end){
            return this.start - o.start;
        }
        return this.end - o.end;
    }
}

public class Problem8 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        Pair[] list = new Pair[N];
        for(int i = 0; i < N; i++){
            String str = br.readLine();
            String[] nums = str.split(" ");
            int start = Integer.parseInt(nums[0]);
            int end = Integer.parseInt(nums[1]);
            list[i] = new Pair(start, end);
        }
        Arrays.sort(list);
        int count = 0;
        int endTime = 0;
        for(int i = 0; i < N; i++){
            if(endTime <= list[i].start){
                endTime = list[i].end;
                count++;
            }
        }
        System.out.println(count);
    }
}

/*
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14

12
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14
0 4
 */