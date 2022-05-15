#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool compare(vector<int> v1, vector<int> v2) {
    return v1.size() < v2.size();
}

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

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> splitted = split(s);
    unordered_set<int> us;
    for (vector<int> v : splitted) {
        for (int n : v) {
            if (us.find(n) == us.end()) {
                us.insert(n);
                answer.push_back(n);
            }              
        }
    }
    return answer;
}

int main() {
    string s1 = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
    string s2 = "{{1,2,3},{2,1},{1,2,4,3},{2}}";
    string s3 = "{{20,111},{111}}";
    string s4 = "{{123}}";
    string s5 = "{{4,2,3},{3},{2,3,4,1},{2,3}}";
    vector<int> answer = solution(s5);
    for (auto i : answer) {
        cout << i << '\n';
    }
    return 0;
}