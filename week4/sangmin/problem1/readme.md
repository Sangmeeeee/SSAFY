문제 : [개똥벌레](https://www.acmicpc.net/problem/3020)

알고리즘 종류 : 누적합, 이분 탐색

참조 url : https://lotuslee.tistory.com/108

# 1. 알고리즘 설명

일단 이 문제에서 길이는 그렇게 중요하지 않다. 문제는 높이인데

![image](https://user-images.githubusercontent.com/24482602/153853145-ffa43c66-370f-4465-b4c1-112290c054e5.png)

높이가 6인 위와같은 동굴이 있을때, 석순과 종유석을 담을 배열을 동굴의 높이만큼 생성한다. 해당 배열에는 석순과 종유석이 각각 끝나는 부분의 개수를 증가시켜 준다.

석순과 종유석은 반드시 동굴 천장이나 바닥과 이어져 있기 때문에 끝나는 높이가 몇개인지만 세어주면 된다.

위 그림의 석순과 종유석의 배열을 보자면
    
    석순[0] = 0   종유석[0] = 0 
    석순[1] = 1   종유석[1] = 2
    석순[2] = 1   종유석[2] = 1
    석순[3] = 1   종유석[3] = 1
    석순[4] = 2   종유석[4] = 1
    석순[5] = 1   종유석[5] = 1
    석순[6] = 0   종유석[6] = 0

해당 정보는 idx에서 끝나는 석순/종유석의 개수가 저장되어있기 때문에 해당 idx 구간에서 존재하는 석순/종유석의 개수를 얻기 위해선

석순은 반드시 동굴 아래에서 부터 뿌리가 이어져있으니 석순의 경우 H에서 부터 1로 석순[idx] = 석순[idx] + 석순[idx-1]을 통해 누적합을 구해주고

종유석도 현재로는 idx가 0인 부분을 동굴 천장으로 지정해뒀기 때문에 H에서 1까지 종유석[idx] = 종유석[idx] + 종유석[idx-1]으로 누적합을 구해준다.

해당 작업을 완료하면

    석순[0] = 0   종유석[0] = 0 
    석순[1] = 6   종유석[1] = 6
    석순[2] = 5   종유석[2] = 4
    석순[3] = 4   종유석[3] = 3
    석순[4] = 3   종유석[4] = 2
    석순[5] = 1   종유석[5] = 1
    석순[6] = 0   종유석[6] = 0

이 된다.

종유석[1]이 6이라는 뜻은 천장으로부터 1의 구간에 존재하는 종유석의 개수가 6개이다.

석순[4]가 3이라는 뜻은 바닥으로부터 4의 구간에 존재하는 석순의 개수가 3개이다.

이제 모든 구간을 돌면서 합이 가장 낮을 경우 답이 된다.

여기서 주의할 점은 석순이 1일경우 종유석은 위에서 부터 H - 1 + 1이 된다.

따라서 석순[idx] + 종유석[H - idx + 1]가 해당 구간의 장애물 개수가 된다.

# 2. 새로 배운 내용

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] firstLine = br.readLine().split(" ");
		int N = Integer.parseInt(firstLine[0]);
		int H = Integer.parseInt(firstLine[1]);
		int[] count = new int[H + 1];

		for (int i = 0; i < N; i++) {
			int num = Integer.parseInt(br.readLine());
			if (i % 2 == 0) { // 석순
				for (int j = 1; j <= num; j++) {
					count[j]++;
				}
			} else { // 종유석
				for (int j = H; j > H - num; j--) {
					count[j]++;
				}
			}

		}
		int min = Integer.MAX_VALUE;
		for (int j = 1; j <= H; j++) {
			min = Math.min(min, count[j]);
		}
		int minCount = 0;

		for (int i = H; i >= 1; i--) {
			if (min == count[i]) {
				minCount++;
			}
		}

		System.out.println(min + " " + minCount);
	}
}
```

원래 작성했던 코드인데 종유석이나 석순을 받을 때 마다 for문을 돌려줘서 시간 초과가 났다.

생각해보면 N * H = 200,000 * 500,000 = 100,000,000,000이라 당연히 시간 초과가 나서 다른 방법으로 접근했어야했는데

생각없이 문제 푸는 습관을 고쳐야 겠다.