package week6.sangmin.problem2;

import java.util.Arrays;
import java.util.Scanner;

public class Problem2 {

    static class Gear{
        char E,W,S,N;
        char EN, ES, WS, WN;

        public Gear(char n, char EN, char e, char ES, char s, char WS, char w, char WN) {
            E = e;W = w;S = s;N = n;this.EN = EN;this.ES = ES;this.WS = WS;this.WN = WN;
        }

        void rotateLeft(){
            char temp = N;
            N = EN;EN = E;E = ES;ES = S;S = WS;WS = W;W = WN;WN = temp;
        }

        void rotateRight(){
            char temp = N;
            N = WN;WN = W;W = WS;WS = S;S = ES;ES = E;E = EN;EN = temp;
        }
    }

    public static void main(String[] args) {
        Gear[] gears = new Gear[4];
        Scanner sc = new Scanner(System.in);
        for(int i = 0; i < gears.length; i++){
            String line = sc.nextLine();
            gears[i] = new Gear(line.charAt(0), line.charAt(1), line.charAt(2), line.charAt(3),
                    line.charAt(4), line.charAt(5), line.charAt(6), line.charAt(7));
        }
        int M = sc.nextInt();
        int[] rotate = new int[4];
        for(int i = 0; i < M; i++){
            int idx = sc.nextInt() - 1;
            Arrays.fill(rotate, 0);
            rotate[idx] = sc.nextInt();

            for(int j = idx - 1; j >= 0; j--){
                if(gears[j + 1].W != gears[j].E){
                    rotate[j] = -1 * rotate[j + 1];
                }else break;
            }
            for(int j = idx + 1; j < gears.length; j++){
                if(gears[j - 1].E != gears[j].W){
                    rotate[j] = -1 * rotate[j - 1];
                }else break;
            }
            for(int j = 0; j < gears.length; j++){
                if(rotate[j] == 1){
                    gears[j].rotateRight();
                }else if(rotate[j] == -1){
                    gears[j].rotateLeft();
                }
            }
        }
        int result = 0;
        if(gears[0].N == '1') result += 1;if(gears[1].N == '1') result += 2;if(gears[2].N == '1') result += 4;if(gears[3].N == '1') result += 8;
        System.out.println(result);
    }
}
