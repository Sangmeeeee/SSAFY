package com.inteli.study.week7.d0310;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem3_3 {
    static int N;
    static int[] boxWidth = new int[20];
    static int[] boxArr = new int[20];
    static int cube_count;// 채워넣은 큐브의 개수
    static boolean impossibleFlag=false;
    static void fillSpace(int x, int y, int z) {
        if (!impossibleFlag) return;
        if (x == 0 || y == 0 || z == 0) return;
        for (int i=20-1;i>=0;i--) {
            if(boxArr[i]!=0){
                if(x >= boxWidth[i] && y >= boxWidth[i] && z >= boxWidth[i]){
                    int xs, ys,zs;
                    int longX, longY, longZ;
                    xs = x / boxWidth[i];
                    ys = y / boxWidth[i];
                    zs = z / boxWidth[i];
                    if (boxArr[i] < xs * ys * zs) {
                        xs = 1;
                        ys = 1;
                        zs = 1;
                    }
                    cube_count+=(xs*ys*zs);
                    boxArr[i] -=(xs*ys*zs);
                    longX=boxWidth[i]*xs;
                    longY=boxWidth[i]*ys;
                    longZ=boxWidth[i]*zs;

                    fillSpace(longX, longY, z-longZ);
                    fillSpace(x-longX,longY,z);
                    fillSpace(x,y-longY,z);

                    return;
                }
            }
        }
        impossibleFlag = false;// 채울 수 없는 경우
    }
    static int solution(int length, int width, int height) {
        impossibleFlag = true;
        fillSpace(length, width, height);
        return  impossibleFlag ? cube_count : -1;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String []str;
        int length,width,height;

        //input firstLine
        str= br.readLine().split(" ");
        length = Integer.parseInt(str[0]);
        width = Integer.parseInt(str[1]);
        height = Integer.parseInt(str[2]);
        //input second Line
        N = Integer.parseInt(br.readLine());

        //input third Line ~
        for (int i = 0; i < N; i++) {
            str = br.readLine().split(" ");
            int power = Integer.parseInt(str[0]);
            boxArr[power]= Integer.parseInt(str[1]);
        }
        for (int i = 0; i < 20; i++) {
            boxWidth[i] = (int)Math.pow(2,i);
        }
        //sol
        int answer = solution(length, width, height);

        System.out.println(answer);
    }
}
//https://www.acmicpc.net/problem/1493
//https://dhpark-blog.tistory.com/entry/BOJ-1493-%EB%B0%95%EC%8A%A4-%EC%B1%84%EC%9A%B0%EA%B8%B0
