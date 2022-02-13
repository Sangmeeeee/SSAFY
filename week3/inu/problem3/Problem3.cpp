#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> um;
int cnt[11]; // 길이가 i인 메뉴의 최대 등장 횟수 저장
vector<string> maxFreq[11]; // 길이가 i이고 최대 등장 횟수를 가진 문자열

void makeMenu(string origin, int idx, string s) {
    if (s.size() >= 2) {
        um[s]++;
        if (cnt[s.size()] == um[s]) {
            maxFreq[s.size()].push_back(s);
        }
        else if (cnt[s.size()] < um[s]) {
            maxFreq[s.size()].clear();
            maxFreq[s.size()].push_back(s);
            cnt[s.size()] = um[s];
        }
    }

    for (int i = idx + 1; i < origin.size(); i++) {
        s.push_back(origin[i]);
        makeMenu(origin, i, s);
        s.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (string& s : orders) {
        sort(s.begin(), s.end());
        makeMenu(s, -1, "");
    }

    for (int i : course)
        if (cnt[i] >= 2)
            for (string s : maxFreq[i])
                answer.push_back(s);

    sort(answer.begin(), answer.end());

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<string> orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    vector<int> course = { 2, 3, 4 };
    vector<string> answer = solution(orders, course);

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << ' ';

    return 0;
}