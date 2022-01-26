#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

// set: 중복 제거, 사전순
set<string> s;
vector<pair<int, int>> v;
string str;
bool nop[200];

void del(int depth) {
	if (depth == v.size()) {
		string tmp;
		for (int i = 0; i < str.size(); i++)
			if (nop[i] != true)
				tmp += str[i];
		if(str.compare(tmp))
			s.insert(tmp);
		return;
	}

	nop[v[depth].first] = true;
	nop[v[depth].second] = true;
	del(depth + 1);
	nop[v[depth].first] = false;
	nop[v[depth].second] = false;
	del(depth + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// 입력받고 괄호 위치 저장
	int idx = 0;
	stack<int> st;
	while (1) {
		char c; cin.get(c);
		if (c == '\n') break;
		str += c;

		if (str[idx] == '(') 
			st.push(idx);
		if (str[idx] == ')') { 
			v.push_back({ st.top(), idx }); 
			st.pop(); 
		}

		idx++;
	}

	del(0);

	for (auto i : s)
		cout << i << '\n';

	return 0;
}