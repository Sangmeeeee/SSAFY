#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> adjList[52];
bool visited[52];

int dfs(int node, int depth, string target, vector<string> words) {
	int result = 0;
	if (words[node] == target) {
		// 방문한 노드의 데이터가 target과 같다면 depth 반환
		return depth;
	}

	visited[node] = true;
	for (int i = 0; i < (int)adjList[node].size(); i++) {
		int next = adjList[node][i];
		if (visited[next]) continue;
		// depth를 통해 변환한 횟수를 저장
		result = dfs(next, depth + 1, target, words);
		visited[next] = false;
	}
	
	return result;
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	int len = begin.length();
	int cnt = 0;

	// 변환하고자 하는 단어 begin을 words 배열 첫번째에 삽입
	words.insert(words.begin(), begin);

	// begin을 포함한 words 배열의 각 단어를 2개씩 비교
	for (int i = 0; i < (int)words.size() - 1; i++) {
		for (int j = i + 1; j < (int)words.size(); j++) {
			cnt = 0;
			if (i != j) {
				// 두 단어를 앞에서부터 차례로 비교했을 때
				for (int k = 0; k < len; k++)
					// 같은 위치의 알파벳이 다르면 cnt 증가
					if (words[i][k] != words[j][k])
						cnt++;
			}

			// 만약 서로 다른 알파벳이 하나 뿐이라면 인접리스트에 서로 추가
			if (cnt == 1) {
				adjList[i].push_back(j);
				adjList[j].push_back(i);
			}
		}
	}

	// 시작 노드 번호, 변환 횟수, 타켓 단어, words 배열
	answer = dfs(0, 0, target, words);

	return answer;
}

int main() {
	string begin, target;
	int n;
	vector<string> words;

	cin >> begin >> target;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		words.push_back(input);
	}

	cout << solution(begin, target, words);

	return 0;
}

/*
hit cog
6
hot dot dog lot log cog

hit cog
5
hot dot dog lot log
*/