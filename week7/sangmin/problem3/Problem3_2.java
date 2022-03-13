package week7.sangmin.problem3;

import java.util.Scanner;

public class Problem3_2 {
    static long length, width, height;
    static long result = 0;
    static long[] ary = new long[21];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        length = sc.nextLong();
        width = sc.nextLong();
        height = sc.nextLong();
        int N = sc.nextInt();
        for(int i = 0; i < N; i++){
            ary[sc.nextInt()] = sc.nextLong();
        }

        long beforeCubes = 0;
        for(int idx = N - 1; idx >= 0; idx--){
            beforeCubes <<= 3;

            long possibleMaxCubeCounts = ( length >> idx ) * ( width >> idx ) * (height >> idx ) - beforeCubes; // 공간을 2^idx의 크기의 큐브로 채울때 넣을 수 있는 cube의 수 - 이전 크기 cube의 개수 * 8
            long possibleCubeCounts = Math.min(ary[idx], possibleMaxCubeCounts ); // 실제로 2^idx의 크기의 큐브를 이용했을 때 들어가는 cube의 수

            result += possibleCubeCounts; // 결과에는 실제로 2^idx의 크기의 큐브를 이용했을 때 들어가는 cube의 수를 더해줘야한다.
            beforeCubes += possibleCubeCounts; // 이전 크기 cube의 개수 * 8 + 실제로 2^idx의 크기의 큐브를 이용했을 때 들어가는 cube의 수
        }

        System.out.println( beforeCubes == length * width * height ? result : -1 );
    }
}
