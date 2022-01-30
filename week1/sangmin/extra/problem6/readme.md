문제 : [Contact](https://www.acmicpc.net/problem/1013)

알고리즘 종류 : 문자열

참조 url :

# 1. 알고리즘 설명(로직위주)

Pattern 클래스 연습하기 좋은 문제인것 같아 넣어보았다.

정규 표현식에 맞는 문자열인지 아닌지 판단하는 문제이기 때문에 Pattern 클래스가 가장 어울린다고 생각했다.

아래는 cpp로 예전에 짠 코드이다.

컴파일러처럼 동작하게 했는데 각 stmt가 현재 문자열의 상태를 나타내고 문자 하나가 들어올때마다 stmt case를 나누어 정규 표현식을 검증하도록 하였다. 

java로는 이보다 더 간결하게 Pattern 클래스를 사용했다.

```c
#include <iostream>
using namespace std;

int N;

enum {
    start, err, s1, s2, s3, s4, s5, s6, s7, s8
};

int main(){
    cin >> N;
    while(N--){
        string str;
        cin >> str;
        int stmt = start;
        const char * line = str.c_str();
        for(int i = 0; i<str.length(); i++){
            switch(stmt){
                case start :
                    line[i] == '1' ? stmt=s1 : stmt=s2;
                    break;
                case s1 : // 1
                    line[i] == '1' ? stmt=err : stmt=s3;
                    break;
                case s2 : // 0
                    line[i] == '1' ? stmt=s4 : stmt=err;
                    break;
                case s3 : // 10
                    line[i] == '1' ? stmt=err : stmt=s5;
                    break;
                case s4 : // 01
                    line[i] == '1' ? stmt=s1 : stmt=s2;
                    break;
                case s5 : // 100
                    line[i] == '1' ? stmt=s6 : stmt=s5;
                    break;
                case s6: // 100+1
                    line[i] == '1' ? stmt=s7 : stmt=s2;
                    break;
                case s7 : // 100+1+
                    line[i] == '1' ? stmt=s7 : stmt=s8;
                    break;
                case s8 : // 100+1+10
                    line[i] == '1' ? stmt=start : stmt=s5;
                    break;
            }
            if(stmt == err) break;
        }
        if(err <= stmt && stmt <= s3 || stmt == s8 || stmt == s5) 
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}

```

# 2. 새로 배운 내용(코드위주)