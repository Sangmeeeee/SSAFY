# Info

  

문제 : [방금그곡](https://programmers.co.kr/learn/courses/30/lessons/17683)

알고리즘 종류 : 문자열

참조 url : [여기](https://velog.io/@hyunjkluz/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A417683-3%EC%B0%A8-%EB%B0%A9%EA%B8%88%EA%B7%B8%EA%B3%A1-Java)

  

# 알고리즘 설명
가장 핵심이 되는 아이디어는 #이 붙은 음을 다른 것으로 치환하는 것이다.  
- C#BCC#BEA# => cBCcBEa와 같이 #이 붙은 것은 소문자로 치환한다.

```c++
char low[] = { 'a','b','c','d','e','f','g' };

string replaceAkbo(string akbo) {
    string akbo_replace = "";

    for (char c : akbo) {
        if (c == '#') {
            char lowercase = low[akbo_replace.back() - 'A'];
            akbo_replace.pop_back();
            akbo_replace.push_back(lowercase);
        }
        else
            akbo_replace += c;
    }

    return akbo_replace;
}
```
대문자에 대한 소문자를 저장하는 low 배열을 만들어두었다.  
악보 문자열의 문자를 하나씩 넣다가 #이 나오면 이전에 넣었던 문자를 pop하고 소문자로 바꿔서 넣어준다.

```c++
string getAllAkbo(string akbo, int playtime) {
    string allAkbo = "";
    string akbo_replace = replaceAkbo(akbo);
    int akboLength = (int)akbo_replace.size();

    int iter = playtime / akboLength;
    if (iter == 0) {
        allAkbo = akbo_replace.substr(0, playtime);
    }
    else {
        for(int i = 0; i < iter; i++)
            allAkbo += akbo_replace;

        int remain = playtime % akboLength;
        allAkbo += akbo_replace.substr(0, remain);
    }

    return allAkbo;
}
```
replaceAkbo로 치환한 악보를 통해 재생 시간에 맞게 전체 악보를 구한다.  
두 가지 경우로 나뉘는데
- 재생 시간보다 악보가 더 긴 경우: 재생 시간에 맞게 악보를 잘라준다.
- 악보보다 재생 시간이 더 긴 경우: (재생 시간 / 악보 길이)만큼 반복해주고 나머지만큼 악보를 잘라서 전체 악보에 붙여준다.

네오가 기억하는 멜로디도 replaceAkbo로 치환해준 다음에 전체 악보에 있는지 검사한다.  
전체 악보에 멜로디가 포함되어 있으면 재생 시간이 더 긴 것을 정답으로 한다.
# 새로 배운 내용
치환하는 것을 생각 못하고 들이박았다가 혼쭐이 났다  
그리고 카카오는 참 문자열을 좋아하는 것 같다~