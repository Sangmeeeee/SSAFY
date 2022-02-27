package com.inteli.study.week5.d0225;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Problem1 {
    static int N;
    static int[] arr;
    static boolean nextPermutations(){
        //1. 교환위치 찾기(꼭대기)
        int i= 9;
        while(0<i && arr[i-1]>=arr[i]){
            --i;
        }
        if(i==0)return false;
        //2. 교환 위치에 교환할 값 찾기.
        int j = 9;
        while(arr[i-1] >= arr[j])--j;//j 가 i-1 보다 좌측을 보게 되는경우는?
        swap(i-1,j);
        //4. 교환위치 뒤(꼭대기) 부터 맨 뒤까지 만들수 있는 가장 작은 순열 생성(오름차순 정렬)
        int k=9;
        while(i<k){
            swap(i++,k--);
        }
        return true;
    }
    static  void swap(int i,int j){
        int temp= arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        return;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        int digit=1;
        arr = new int[10];
        for(int i=1;i<=10;i++){
            if(N -nCk(10,i)<0)break;
            N-=nCk(10,i);
            digit++;
        }
        //값이 9876543210 보다 큰경우 -1
        if(digit==11) {
            System.out.println(-1);
            return;
        }
        //arr init [9][8][7][6][5][4][3][2][1][0]
        for(int i=0;i<digit;i++){
            arr[9-i]=1;
        }
        //남은 횟수 N 만큼 00000111 에서 N 회 nextPermutation
        for(int i=0;i<N;i++){
            nextPermutations();

        }
        //남은N회 된 nextPermutation 에서 순차적으로 가져오기
        StringBuilder sb= new StringBuilder();
        for(int i=0;i<10;i++){
            if(arr[i]==1){
                sb.append(9-i);
            }
        }
        System.out.println(sb.toString());
    }
    static int nCk(int n, int k){
        //n!/(n-k)!*(k)!
        //n~(n-k+1) / k!;
        int NCK = n;
        for(int i=1;i<k;i++){
            NCK *=(n-i);
        }
        for(int i=1;i<=k;i++){
            NCK/=i;
        }
        return NCK;
    }
}
