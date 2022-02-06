package com.inteli.d0203;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Problem1 {
    static int maxNum=-1000000001;
    static int minNum=1000000001;
    static int N;
    static int [] arr = new int[11];
    static int [] pmmd = new int [4];
    static List<Integer>numList;

    public static void BTFunction(List<Integer>pmmdList, int startIdx){//여기 헷(List<Integer>)
        if(N<=startIdx){//basis
            int temp;
            numList = new ArrayList<>();
            numList.add(arr[0]);

            for(int i=1;i<N;i++){//pmmd */
                switch (pmmdList.get(i-1)){
                    case 0:
                    case 1:
                        numList.add(arr[i]);
                        break;
                    case 2:
                        temp = numList.get(numList.size()-1);
                        temp*= arr[i];
                        numList.remove(numList.size()-1);

                        numList.add(temp);
                        break;
                    case 3:
                        temp = numList.get(numList.size()-1);
                        temp/= arr[i];
                        numList.remove(numList.size()-1);

                        numList.add(temp);
                        break;
                }
            }
            temp =numList.get(0);
            int numIdx=1;
            //System.out.println("numList size : " + numList.size());
            //System.out.println("pmmdList size : "+pmmdList.size());
            if(numList.size()!=1){
                for(int i=0;i<pmmdList.size();i++){
                    switch (pmmdList.get(i)){
                        case 0:
                            temp += numList.get(numIdx++);
                            break;
                        case 1:
                            temp -= numList.get(numIdx++);
                            break;
                        case 2:
                        case 3:
                            break;
                    }
                }
            }

            //max min
            if(maxNum<temp)maxNum=temp;
            if(temp<minNum)minNum=temp;
            return;
        }

        for(int i=0;i<4;i++){
            if(0 < pmmd[i]){//able
                pmmd[i]--;
                pmmdList.add(i);

                BTFunction(pmmdList,startIdx+1);

                pmmdList.remove(pmmdList.size()-1);//idx? obj?
                pmmd[i]++;
            }
        }
        return ;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        String [] line = br.readLine().split(" ");
        List<Integer> pmmdList = new ArrayList<Integer>();

        //init
        for(int i=0;i<N;i++){
            arr[i] = Integer.parseInt(line[i]);
        }
        line = br.readLine().split(" ");
        for(int i=0;i<4;i++){
            pmmd[i] = Integer.parseInt(line[i]);
        }

        BTFunction(pmmdList,1);//0?

        System.out.println(maxNum);
        System.out.println(minNum);

    }
}
//40분...
//우선순위 생각을 못해서 다시 풀기 시작했다.. 아....
//2시간 걸림.. 핰ㅋㅋㅋㅋ