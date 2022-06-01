#include <string>
#include <vector>
#include <cmath>

using namespace std;

int shootInfo[11]; // 라이언이 쏜 화살 정보 (0: 10점, 1: 9점, ..., 10: 0점)
int maxDiff = 0;   // 최대 점수 차이를 저장
int result[11];    // 정답을 임시로 저장하는 배열

void shoot(vector<int> info, int idx, int la) {
    if(la == 0) {
        // 라이언이 쏠 수 있는 화살을 다 쐈다면 점수 계산
        int lion = 0;
        int apeach = 0;
        
        // 라이언과 어피치 각각의 점수 구하기
        for(int i=0; i<=10; i++) {
            if(info[i] == 0 && shootInfo[i] == 0)
                continue;
            if(info[i] < shootInfo[i]) 
                lion += (10-i);
            else
                apeach += (10-i);
        }
        
        if(maxDiff<lion-apeach) {
            // 최대 점수 차이보다 크다면 정답 및 최대 점수 차이 업데이트
            for(int i=0; i<=10; i++)
                result[i] = shootInfo[i];
            maxDiff = lion - apeach;
        } else if(maxDiff == lion-apeach) {
            // 최대 점수 차이와 같다면 가장 낮은 점수를 더 많이 맞힌 경우를 선택한다.
            // flag: 현재 정답으로 저장되어 있는 것이 가장 낮은 점수를 더 많이 맞힌 경우라면 false
            //       현재 라이언이 쏜 것이 가장 낮은 점수를 더 많이 맞힌 경우라면 true
            bool flag = false;
            for(int i=10; i>=0; i--) {
                if(result[i] < shootInfo[i]) {
                    flag = true;
                    break;
                } else if (result[i] > shootInfo[i])
                    break;
            }
            if(flag) {
                for(int i=0; i<=10; i++)
                    result[i] = shootInfo[i];
            }
        }
        
        return;
    }
    
    // 10점부터 차례로 어피치가 쏜 화살의 개수와 비교한다.
    for(int i=idx; i<=10; i++) {
        int temp = 0;
        
        if(i == 10) {
            shootInfo[10] = la;
            temp = la;
        } else {
            // 어피치가 (10-i)점에 쏜 화살의 개수+1 <= 라이언이 가진 화살의 개수
            if(info[i]+1 <= la) {
                // 어피치보다 1개 더 많이 쏜다.
                temp = info[i]+1; 
                shootInfo[i] = temp; 
            } else // 라이언이 가진 화살의 개수가 더 적다면 화살 낭비하지 않고 넘긴다.
                continue;
        }
        
        shoot(info, idx+1, la-temp);
        shootInfo[i] = 0; // 원상복구
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    
    shoot(info, 0, n);
    if(maxDiff > 0) {
        for(int i=0; i<=10; i++)
            answer.push_back(result[i]);
    } else
        answer.push_back(-1);
    
    return answer;
}