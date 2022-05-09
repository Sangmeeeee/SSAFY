#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

map<string, string> nickname;

vector<string> split(string input, char delimeter) {
    vector<string> token;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimeter)) {
        token.push_back(temp);
    }

    return token;
}

vector<string> solution(vector<string> record) {
    vector<vector<string>> tokens;
    vector<string> answer;
    
    for (string s : record) {
        vector<string> token = split(s, ' ');
        tokens.push_back(token);
        if (token[0].compare("Enter") == 0 || 
            token[0].compare("Change") == 0) {
            nickname[token[1]] = token[2];
        }
    }

    for (auto token : tokens) {
        if (token[0].compare("Enter") == 0) {
            answer.push_back(nickname[token[1]] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
        }
        else if (token[0].compare("Leave") == 0) {
            answer.push_back(nickname[token[1]] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<string> record = {
        "Enter uid1234 Muzi",
        "Enter uid4567 Prodo",
        "Leave uid1234",
        "Enter uid1234 Prodo",
        "Change uid4567 Ryan"
    };

    vector<string> answer = solution(record);
    for (string s : answer) {
        cout << s << '\n';
    }
    return 0;
}