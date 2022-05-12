# Info

  

문제 : [튜플](https://programmers.co.kr/learn/courses/30/lessons/64065)

알고리즘 종류 : set

참조 url :

  

# 알고리즘 설명
집합의 원소 갯수가 적은 순서대로 튜플 내 원소 순서가 정해진다.  
예를 들어, {1,2,3}, {2,1}, {1,2,4,3}, {2}와 같이 주어진다면 {2}, {2, 1}, {1, 2, 3}, {1, 2, 4, 3}과 같은 순서이므로 (2, 1, 3, 4)를 나타내게 된다.  
먼저 string에 있는 각 튜플에서 숫자만 따로 저장해야 한다.
```c++
vector<vector<int>> split(string s) {
    string temp;
    vector<vector<int>> splitted;
    vector<int> numset;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            temp += s[i];
            if (s[i + 1] == ',' || s[i + 1] == '}') {
                numset.push_back(stoi(temp));
                temp = "";
                if (s[i + 1] == '}') {
                    splitted.push_back(numset);
                    numset.clear();
                }
            }
        }
    }
    sort(splitted.begin(), splitted.end(), compare);
    return splitted;
}
```
이 후에 각 집합의 원소 갯수를 오름차순으로 정렬한다.
```c++
bool compare(vector<int> v1, vector<int> v2) {
    return v1.size() < v2.size();
}
```
splitted의 벡터 요소들이 set에 있는지 검사해서 없으면 set에 넣고 answer에도 넣어준다.
```c++
unordered_set<int> us;
for (vector<int> v : splitted) {
    for (int n : v) {
        if (us.find(n) == us.end()) {
            us.insert(n);
            answer.push_back(n);
        }              
    }
}
```
set에 들어가는 요소를 정렬할 필요가 없기 때문에 unordered_set을 쓴다.

- unordered_set을 쓴 경우  
<img src="https://user-images.githubusercontent.com/55791128/168124302-129c1152-8687-4fd1-ab3a-74b32ff5a5e8.png">
- set을 쓴 경우  
<img src="https://user-images.githubusercontent.com/55791128/168124974-47a2244c-59bb-4a85-9e5c-b8de80ef738d.png">  

실제로 두 자료형의 시간 차이가 제법 난다.  
원소 수가 적고 순서를 따질 필요가 없을 때는 unordered_set을 쓰는 것이 낫다.

# 새로 배운 내용
