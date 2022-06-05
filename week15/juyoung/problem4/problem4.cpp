#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isSelected[8];
int permutation[8];
char index[8] = {'A','C','F','J','M','N','R','T'};
int answer = 0;

void makePerm(int cnt, vector<string> data) {
    // 순열을 구하고 나면
    if(cnt == 8) {
        // 해당 순열이 모든 조건을 만족하는지 검사한다.
        for(int i=0; i<data.size(); i++) {
            char f1 = data[i][0]; // 조건을 제시한 프렌즈
            char f2 = data[i][2]; // 상대방
            char cond = data[i][3]; // 조건 (=, <, >)
            int dist = data[i][4] - '0' + 1; // 거리
            
            int idx1 = 0; // f1의 인덱스
            int idx2 = 0; // f2의 인덱스
            
            for(int j=0; j<8; j++) {
                if(index[permutation[j]] == f1) idx1 = j;
                else if(index[permutation[j]] == f2) idx2 = j;
            }
            
            if(cond == '=') {
                if(abs(idx1-idx2) != dist) return;
            } else if(cond == '<') {
                if(abs(idx1-idx2) >= dist) return;
            } else {
                if(abs(idx1-idx2) <= dist) return;
            }
        }
        
        answer++;
        return;
    }
    
    // 순열 구하기
    for(int i=0; i<8; i++) {
        if(isSelected[i]) continue;
        isSelected[i] = true;
        permutation[cnt] = i;
        makePerm(cnt+1, data);
        isSelected[i] = false;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    answer = 0;
    makePerm(0, data);
    return answer;
}