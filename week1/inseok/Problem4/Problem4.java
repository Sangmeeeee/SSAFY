package com.inteli.d0127;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Problem4_2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int K = Integer.parseInt(br.readLine());
        int [] sensorArr = new int[N];//sensor
        int []distArr = new int[N-1];//사이 간격을 나타내는 arr
        int sum=0;
        String[] inputLine = br.readLine().split(" ");
        for(int i=0;i<N;i++){
            sensorArr[i] = Integer.parseInt(inputLine[i]);
        }
        Arrays.sort(sensorArr);//센서 소트(done)
        for(int i=0;i<sensorArr.length-1;i++){
            distArr[i] = sensorArr[i+1]-sensorArr[i];
        }

        Arrays.sort(distArr);//위에서 부터 k-1개 뺄수 있는 권한이 생김!
        for(int i=0;i<N-1-(K-1);i++){
            sum+=distArr[i];
        }
        System.out.println(sum);
    }
}
//센서
//2212
//https://joodaram.tistory.com/63