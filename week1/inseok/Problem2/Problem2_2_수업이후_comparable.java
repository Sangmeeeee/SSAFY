
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
//실패
//https://www.acmicpc.net/problem/17140
public class Problem2_2_수업이후_comparable {
    static class Block implements Comparable<Block> {//freq sort -> num sort //static?
        int num;
        int freq;
        Block(int num, int freq){
            this.num = num;
            this.freq = freq;
        }
        @Override
        public int compareTo(Block other) {//여기 이게 헷갈리네
            if(freq == other.freq){//오름 차순
                Integer.compare(num,other.num);
            }
            return Integer.compare(freq,other.freq);//오름차순
        }
    }
    static int [][] arr = new int [101][101];//1
    static int second =0;
    static int maxRow=0;
    static  int maxCol=0;
    static void findMaxRowCol(){
        maxRow=0;
        maxCol=0;
        //maxRow
        for(int i=1;i<=100;i++){
            for(int j=1;j<=100;j++){
                if(arr[i][j]!=0){
                    maxCol = Math.max(maxCol, j);
                    maxRow = Math.max(maxRow, i);
                }
            }
        }
    }
    static void changeR(){
        System.out.println("do changeR : "+maxRow+" "+maxCol);
        for(int i=1;i<101;i++){
            Map<Integer,Integer> map = new HashMap<>();//num,freq
            for(int j=1;j<101;j++){
                if(arr[i][j]==0)continue;
                else{
                    if (map.containsKey(arr[i][j])) {
                        map.put(arr[i][j], map.get(arr[i][j])+1);
                    } else {
                        map.put(arr[i][j], 1);
                    }
                }
            }
            List<Block> bl = new ArrayList<>();
            map.forEach((key, value)
                    -> bl.add(new Block(key, value)));
            Collections.sort(bl);
            for(int j=1;j<50;j++){
                if(j<=bl.size()){
                    arr[i][2 * j-1] = bl.get(j-1).num;
                    arr[i][2 * j ] = bl.get(j-1).freq;
                }
                else {
                    arr[i][2 * j-1] = 0;
                    arr[i][2 * j ] = 0;
                }
            }
        }
        return ;

    }
    static void changeC(){
        System.out.println("do changeC "+maxRow+" "+maxCol);
        for(int i=1;i< 101;i++) {
            Map<Integer,Integer> map = new HashMap<>();//num,freq
            for (int j = 1; j < 101; j++) {
                if(arr[j][i]==0)continue;
                if (map.containsKey(arr[j][i])) {
                    map.put(arr[j][i], map.get(arr[j][i])+1 );
                } else {
                    map.put(arr[j][i], 1);
                }
            }

            List<Block> bl = new ArrayList<>();
            map.forEach((key, value)
                    -> bl.add(new Block(key, value)));
            Collections.sort(bl);
            for(int j=1;j<50;j++){
                if(j<=bl.size()){
                    arr[2 * j-1][i] = bl.get(j-1).num;
                    arr[2 * j ][i] = bl.get(j-1).freq;
                }
                else {
                    arr[2 * j-1][i] = 0;
                    arr[2 * j ][i] = 0;
                }
            }
        }
        return ;
    }
    public static void main(String[] args) throws IOException {
        //input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] inputLine= br.readLine().split(" ");//firstLine
        int r = Integer.parseInt(inputLine[0]);
        int c = Integer.parseInt(inputLine[1]);
        int k = Integer.parseInt(inputLine[2]);
        for(int i=1;i<=3;i++){
            inputLine = br.readLine().split(" ");
            for(int j=1;j<=3;j++) {
                arr[i][j] = Integer.parseInt(inputLine[j-1]);
            }
        }

        while(second<=100){
            if(arr[r][c]==k) break;
            findMaxRowCol();
            System.out.println("curMaxRow , curMaxCol "+maxRow + " "+maxCol);
            if(maxRow>=maxCol) changeR();
            else{
                changeC();
            }
            System.out.println("second : "+(second+1));
            for(int i=1;i<10;i++){
                for(int j=1;j<10;j++){
                    System.out.printf("%3d",arr[i][j]);
                }
                System.out.println();
            }

            second++;
            System.out.println();
        }
        //output
        if(second<=100){
            System.out.println(second);
        }else{
            System.out.println(-1);
        }
    }
}
