문제 : [파일 합치기 3] ([url](https://www.acmicpc.net/problem/13975))

알고리즘 종류 : 우선순위큐(힙)

참조 url : ([url](https://hi-spring-night.tistory.com/15))

# 1. 알고리즘 설명(로직위주)

## 문제 이해

week3Problem1 이랑 문제 같던데? 문제 자체는 쉬웠다. 근데 Long 을 써야 할 상황이 생길거라고는 상상치도 못했다.... 진짜.. 

야 진짜.. 이런 상황은 문제 풀기 전에 고려를 해야하려나..?

## 로직

일단 받아올때 부터 PriorityQueue<Long>priorityQueue 로 생성해준다. 이를 입력받는 숫자를 모두 add해주어 힙상태를 만들어준다. 

이하 내용은 같기 떄문에 생략

# 2. 새로 배운 내용(코드위주)

## StringTokenizer 클래스

### 간단한 예제...(사용법은 주석보고 이해)

```java
import java.io.BufferedReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));//"h e l l o"
				StringTokenizer st  = new StringTokenizer(br.readLine());//자동으로 delimeter : space. 뒤에다가 delimeter를 넣을 수도 있다.
				while(st.hasMoreTokens()){
					System.out.println(st.nextToken()+","+st.countTokens());
				}
				//h 4
				//e 3
				//l 2
				//l 1
				//o 0(아마도?)
    }
}
```

### StringToknizer Vs. String.split()

<StringTokenizer>

String 클래스 자체에서 split 을 제공 해주기는 하는데 index마다 어쩌고 저쩌고 해줘야하는 귀찮음이 있다. StringTokenizer는 그냥 token이 있는지 없는 지를 보면 되기 때문에 이득.
또한 StringTokenizer 가 정규표현식으로 이를 찾기 때문에 String.split 보다 빠르다고 한다(정규표현식을 잘 모르지만 이를 쓰니깐 빠르다네.)

<String.split()>

따로 StringTokenizer를 안써도 된다지만 나같으면 쓸듯

대신 여러개의 Delimeter를 써야 하는 경우에는 StringTokenizer에선 제공하지 않기때문에 Split() 을 알아 둘 필요는 있다.