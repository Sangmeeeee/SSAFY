#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ans = 10000;
bool visited[50];
vector<string> list;

bool isContain(string target, vector<string> words) {
    for (int i = 0; i < (int)words.size(); i++)
        if (!words[i].compare(target))
            return true;
    return false;
}

void search(int cnt, string cmp, string target) {
    if (!cmp.compare(target)) {
        ans = cnt < ans ? cnt : ans;
        return;
    }

    for (int i = 0; i < (int)list.size(); i++) {
        if (visited[i])
            continue;

        int dif = 0;
        for (int j = 0; j < (int)list[i].size(); j++)
            if (cmp[j] != list[i][j])
                dif++;

        if (dif == 1) {
            visited[i] = true;
            search(cnt + 1, list[i], target);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    for (int i = 0; i < (int)words.size(); i++)
        list.push_back(words[i]);

    if (!isContain(target, words))
        return 0;

    search(0, begin, target);
  
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string begin = "hit";
    string target = "cog";
    vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };

    cout << solution(begin, target, words);

    return 0;
}