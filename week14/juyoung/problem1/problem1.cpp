#include <iostream>
using namespace std;

struct TRIE {
	bool finish;	// ���ڿ��� ���� �������� true�� üũ
	TRIE *node[10]; // �� ���� ��带 ����Ű�� ������ �迭
	TRIE() {
		finish = false;
		for (int i = 0; i < 10; i++) node[i] = NULL;
	}
	~TRIE() {
		for (int i = 0; i < 10; i++) delete node[i];
	}

	// �����ϴ� �Լ�
	void insert(char *str) {
		// ���� ���ڿ��� ���̶�� finish�� true�� üũ
		if (*str == NULL) {
			finish = true;
			return;
		}

		// ���� ���ڿ� ���� ��尡 �����ϴ��� üũ�ϰ� ������ ����
		int curr = *str - '0';
		if (node[curr] == NULL) node[curr] = new TRIE();
		// ���� ���ڸ� �����Ѵ�.
		node[curr]->insert(str + 1);
	}

	// ���ڿ��� ã�� �Լ�
	bool find(char *str) {
		// ������ ���ڿ� �����Ѵٸ� �ϰ��� O
		if (*str == NULL) return true;
		// �����ϴ� ��� �� ���ڿ��� ���� ��Ÿ���� ��尡 ������ �ϰ��� X
		if (finish) return false;

		int curr = *str - '0';
		// ���� ���ڸ� ã�´�.
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

		// Ʈ���� ����
		TRIE *root = new TRIE();
		char numbers[10001][11];

		// Ʈ���̿� ���ڿ� ����
		for (int i = 0; i < N; i++) {
			cin >> numbers[i];
			root->insert(numbers[i]);
		}

		// Ʈ���̿��� ���ڿ� ã��
		bool answer = true;
		for (int i = 0; i < N; i++) {
			// false ��ȯ -> �ϰ����� ���ٴ� �ǹ�
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