#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

vector<pair<int, int>> v;
set<string> answer;
bool visited[200];
string input;
bool check[200] = { false, };

void remove(int idx) {
	for (int i = idx; i < v.size(); i++) {
		if (visited[i]) continue;
		visited[i] = true;
		check[v[i].first] = check[v[i].second] = true;
		string temp = "";
		for (int j = 0; j < input.size(); j++) {
			if (check[j]) continue;
			temp += input[j];
		}
		answer.insert(temp);
		remove(i+1);
		check[v[i].first] = check[v[i].second] = false;
		visited[i] = false;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	stack<int> stack;

	cin >> input;
	for (int i = 0; i < input.length(); i++) {
		// 닫힌 괄호가 나오면 스택의 top과 현재 인덱스를 우선순위 큐에 push하고 스택은 pop
		if (input[i] == ')') {
			v.push_back({ stack.top(), i });
			stack.pop();
			continue;
		} else if (input[i] == '(')
			stack.push(i);
	}

	sort(v.begin(), v.end());
	remove(0);

	for (auto iter = answer.begin(); iter != answer.end(); iter++)
		cout << *iter << "\n";

	return 0;
}