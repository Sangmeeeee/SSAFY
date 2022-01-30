문제 : [문자열 폭발](https://www.acmicpc.net/problem/9935)

알고리즘 종류 : 문자열

참조 url :

# 1. 알고리즘 설명

stack을 이용해서 bomb 문자열이 완성되면 문자열을 stack에서 삭제시켜준다.

매번 문자가 들어올때마다 stack을 (top - 문자열의 크기)에서 부터 탐색해서 시간이 오래 걸릴것 같지만

bomb 문자열의 크기가 최대 36이기 때문에 시간이 적게 걸릴것이라고 판단했다.

앞서 말한것처럼 bomb 문자열과 stack의 문자열을 비교해서 만약 bomb 문자열이라면 stack에서 bomb 문자열의 크기만큼 pop() 해준다.

그리고 만약 최종적으로 stack의 크기가 0이라면 남은 문자열이 존재하지 않은것이기 때문에 FRULA를 출력해주고

stack에 문자가 남아있다면 이는 폭탄으로 제거된 문자가 아니기 때문에 문자열로 변환해준다. 

# 2. 새로 배운 내용(코드위주)

처음에는 Matcher와 String의 replaceAll() 메소드를 이용해서 해결하려 했으나 메모리 초과가 나버려서 stack으로 바꾸었다.

아래는 처음에 짠 코드인데 다시 작성하는거라 정확하지는 않을 수 있다.

```java
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Problem1 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        String regex = br.readLine();
        Pattern pattern = Pattern.compile(regex); // regex를 패턴으로 하는 Pattern 객체를 리턴해줌
        Matcher matcher = pattern.matcher(str);
        
        while(matcher.find()){ // matcher.find()로 str과 regex가 str에 포함되어있는지 판단
            str = str.replaceAll(regex, ""); // 만약 포함되어있다면 replaceAll로 날려줌
            matcher = pattern.matcher(str);
        }
        
        if(str.equals("")){
            System.out.println("FRULA");
        }else{
            System.out.println(str);
        }
    }
}
```