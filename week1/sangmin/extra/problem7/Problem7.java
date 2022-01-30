package week1.sangmin.extra.problem7;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Problem7 {
    public static void main(String[] args) throws Exception{
        StringBuilder sb = new StringBuilder();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int T = Integer.parseInt(br.readLine());
        int count = 0;

        char[] input = new char[T];
        for(int i = 0; i < T; i++){
            input[i] = br.readLine().charAt(0);
        }

            String str = new String(input);
            int firstIdx = 0;
            int lastIdx = str.length() - 1;

            while (firstIdx <= lastIdx) {
                char firstChar = str.charAt(firstIdx);
                char lastChar = str.charAt(lastIdx);

                if(firstChar < lastChar){
                    sb.append(firstChar);
                    firstIdx++;
                }else if(firstChar > lastChar){
                    sb.append(lastChar);
                    lastIdx--;
                }else{
                    int start = firstIdx+1;
                    int end = lastIdx-1;
                    boolean isSame = true;
                    while(start < end){
                        if(str.charAt(start) < str.charAt(end)){
                            sb.append(firstChar);
                            firstIdx++;
                            isSame = false;
                            break;
                        }else if(str.charAt(start) > str.charAt(end)){
                            sb.append(lastChar);
                            lastIdx--;
                            isSame = false;
                            break;
                        }else {
                            start++;
                            end--;
                        }
                    }
                    if(isSame){
                        sb.append(firstChar);
                        firstIdx++;
                    }
                }
                if(++count % 80 == 0){
                    sb.append('\n');
                }
            }
        bw.write(sb.toString());
        bw.flush();
    }
}


/*
6
A
C
D
B
C
B
 */