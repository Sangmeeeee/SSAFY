#include <iostream>
using namespace std;

struct TRIE {
	bool finish;	// 문자열이 끝난 지점에서 true로 체크
	TRIE *node[10]; // 각 숫자 노드를 가리키는 포인터 배열
	TRIE() {
		finish = false;
		for (int i = 0; i < 10; i++) node[i] = NULL;
	}
	~TRIE() {
		for (int i = 0; i < 10; i++) delete node[i];
	}

	// 삽입하는 함수
	void insert(char *str) {
		// 만약 문자열의 끝이라면 finish를 true로 체크
		if (*str == NULL) {
			finish = true;
			return;
		}

		// 현재 숫자에 대해 노드가 존재하는지 체크하고 없으면 생성
		int curr = *str - '0';
		if (node[curr] == NULL) node[curr] = new TRIE();
		// 다음 글자를 삽입한다.
		node[curr]->insert(str + 1);
	}

	// 문자열을 찾는 함수
	bool find(char *str) {
		// 마지막 문자에 도달한다면 일관성 O
		if (*str == NULL) return true;
		// 공유하는 노드 중 문자열의 끝을 나타내는 노드가 있으면 일관성 X
		if (finish) return false;

		int curr = *str - '0';
		// 다음 문자를 찾는다.
		return node[curr]->find(str + 1);
	}
};


int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;

		// 트라이 생성
		TRIE *root = new TRIE();
		char numbers[10001][11];

		// 트라이에 문자열 삽입
		for (int i = 0; i < N; i++) {
			cin >> numbers[i];
			root->insert(numbers[i]);
		}

		// 트라이에서 문자열 찾기
		bool answer = true;
		for (int i = 0; i < N; i++) {
			// false 반환 -> 일관성이 없다는 의미
			if (!root->find(numbers[i])) {
				answer = false;
				break;
			}
		}

		if (answer) cout << "YES\n";
		else cout << "NO\n";

		delete root;
	}
	
	return 0;
}