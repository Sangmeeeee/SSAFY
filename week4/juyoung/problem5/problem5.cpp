#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> adjList[52];
bool visited[52];

int dfs(int node, int depth, string target, vector<string> words) {
	int result = 0;
	if (words[node] == target) {
		// �湮�� ����� �����Ͱ� target�� ���ٸ� depth ��ȯ
		return depth;
	}

	visited[node] = true;
	for (int i = 0; i < (int)adjList[node].size(); i++) {
		int next = adjList[node][i];
		if (visited[next]) continue;
		// depth�� ���� ��ȯ�� Ƚ���� ����
		result = dfs(next, depth + 1, target, words);
		visited[next] = false;
	}
	
	return result;
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	int len = begin.length();
	int cnt = 0;

	// ��ȯ�ϰ��� �ϴ� �ܾ� begin�� words �迭 ù��°�� ����
	words.insert(words.begin(), begin);

	// begin�� ������ words �迭�� �� �ܾ 2���� ��
	for (int i = 0; i < (int)words.size() - 1; i++) {
		for (int j = i + 1; j < (int)words.size(); j++) {
			cnt = 0;
			if (i != j) {
				// �� �ܾ �տ������� ���ʷ� ������ ��
				for (int k = 0; k < len; k++)
					// ���� ��ġ�� ���ĺ��� �ٸ��� cnt ����
					if (words[i][k] != words[j][k])
						cnt++;
			}

			// ���� ���� �ٸ� ���ĺ��� �ϳ� ���̶�� ��������Ʈ�� ���� �߰�
			if (cnt == 1) {
				adjList[i].push_back(j);
				adjList[j].push_back(i);
			}
		}
	}

	// ���� ��� ��ȣ, ��ȯ Ƚ��, Ÿ�� �ܾ�, words �迭
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