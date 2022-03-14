package week7.sangmin.problem3;

import java.util.*;

class Pair{
    int pow, count;

    public Pair(int pow, int count) {
        this.pow = (int) Math.pow(2, pow);
        this.count = count;
    }
}

public class Problem3_1 {
    static long length, width, height;
    static long result = 0;
    static List<Pair> list = new ArrayList<>();
    static boolean isOk = true;

    static void div(long l, long w, long h){
        long min = Math.min(l, Math.min(w, h));
        if(!isOk) return; // 나누었지만 채울 수 없는 칸이 존재한다면 return
        if(min <= 0) return; // 나누었는데 한 변이 하나라도 0이하라면 return -> 딱 맞게 채웠기 때문에 어느 한 직육면체가 존재하지 않을수도 있음

        for(int idx = list.size() - 1; idx >= 0; idx--){ // 가장 큰 크기의 cube부터 돌면서
            if(list.get(idx).pow <= min && list.get(idx).count > 0){ // 만약 cube가 직육면체에 들어갈 수 있고 cube개수가 0보다 크다면
                result++; // 해당 큐브를 직육면체에 채워줌
                list.get(idx).count--;

                div(l, w - list.get(idx).pow,  list.get(idx).pow); // 나머지 부분을 나누어줌
                div(l - list.get(idx).pow, list.get(idx).pow, list.get(idx).pow);
                div(l, w, h - list.get(idx).pow);
                return; // 바로 종료
            }
        }
        isOk = false; // 만약 모든 크기의 큐브를 돌았음에도 직육면체를 채울 수 없다면 -1출력을 해줘야함
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        length = sc.nextLong();
        width = sc.nextLong();
        height = sc.nextLong();
        int N = sc.nextInt();
        for(int i = 0; i < N; i++){
            list.add(new Pair(sc.nextInt(), sc.nextInt()));
        }
        div(length, width, height);
        System.out.println(isOk ? result : -1);
    }
}
