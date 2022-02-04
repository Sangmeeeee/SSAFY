package week2.sangmin.problem2;

import java.util.LinkedList;
import java.util.Queue;

class Truck{
    int weight;
    int outTime;
    public Truck(int weight, int outTime){
        this.weight = weight;
        this.outTime = outTime;
    }

    @Override
    public String toString() {
        return "weight : " + weight + ", outTime : " + outTime;
    }
}

public class Problem2 {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        int time = 0;
        Queue<Truck> queue = new LinkedList<>();

        for(int i = 0; i < truck_weights.length; i++){
            if(truck_weights[i] <= weight){ // 입장 가능
                Truck temp = new Truck(truck_weights[i], ++time + bridge_length);
                System.out.println("can add : " + temp);
                queue.add(temp);
                weight -= truck_weights[i];
                while(queue.peek().outTime <= time){
                    temp = queue.poll();
                    System.out.println("out after add: " + temp);
                    weight += temp.weight;
                }
            }else{
                while (weight < truck_weights[i]){
                    Truck temp = queue.poll();
                    System.out.println("out : " + temp);
                    weight += temp.weight;
                    time = temp.outTime;
                }
                Truck temp = new Truck(truck_weights[i], time + bridge_length); // 기다렸다 올림
                System.out.println("wait add : " + temp);
                queue.add(temp);
                weight -= truck_weights[i];
            }
        }
        answer = time;
        while(!queue.isEmpty()){
            answer = queue.poll().outTime;
        }
        System.out.println(answer);
        return answer;
    }

    public static void main(String[] args) {
        new Problem2().solution(2, 10, new int[]{7,4,5,6});
        System.out.println();
        new Problem2().solution(100, 100, new int[]{10});
        System.out.println();
        new Problem2().solution(100, 100, new int[]{10,10,10,10,10,10,10,10,10,10});
        System.out.println();
        new Problem2().solution(100, 100, new int[]{100,100,100,100,100,100,100,100,100,100});
        new Problem2().solution(2, 10, new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3});
        System.out.println();
        new Problem2().solution(5, 5, new int[]{2, 2, 2, 2, 1, 1, 1, 1, 1});
        System.out.println();
    }
}
