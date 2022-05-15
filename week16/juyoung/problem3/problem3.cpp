#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

char op[3] = { '+', '-', '*' }; // ������
char prior[3];					// �켱������� �����ڸ� �����ϴ� �迭
bool check[3];					// �����ڰ� ���տ� ���Ǿ������� �����ϴ� �迭
vector<long long> numbers;		// �ǿ�����
vector<char> oplist;			// ������ ���
long long temp;					// ���� �ӽ� ����

long long calc() {
	vector<long long> copy_num = numbers;
	vector<char> copy_op = oplist;

	// �켱������ ū �ͺ��� ó���Ѵ�.
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < (int)copy_op.size(); j++) {
			if (prior[i] == copy_op[j]) {
				if (prior[i] == '+')
					copy_num[j] = copy_num[j] + copy_num[j + 1];
				else if (prior[i] == '-')
					copy_num[j] = copy_num[j] - copy_num[j + 1];
				else
					copy_num[j] = copy_num[j] * copy_num[j + 1];

				copy_num.erase(copy_num.begin() + j + 1);
				copy_op.erase(copy_op.begin() + j);
				j--;
			}
		}
	}

	return copy_num[0];
}

void makePerm(int cnt) {
	// 3. ��� �������� �켱������ �������� �׿� �°� ����Ѵ�.
	if (cnt == 3) {
		long long result = calc();
		if (result < 0) result *= -1;
		temp = max(temp, result);
	}

	for (int i = 0; i < 3; i++) {
		if (check[i]) continue;
		check[i] = true;
		prior[cnt] = op[i];
		makePerm(cnt + 1);
		check[i] = false;
	}
}

long long solution(string expression) {
	long long answer = 0;

	// 1. �ǿ����ڿ� ������ ����� ���ͷ� �и��Ѵ�.
	string str = "";
	for (int i = 0; i < expression.length(); i++) {
		// �����ڶ��
		if (expression[i] < '0' || expression[i] > '9') {
			// ���ڿ��� �� ���ڸ� ������ ��ȯ�Ͽ� �ǿ����� ��Ͽ� �����ϰ�
			numbers.push_back(stoi(str));
			str = "";
			// ������ ��Ͽ� �����Ѵ�.
			oplist.push_back(expression[i]);
			continue;
		}
		str += expression[i];
	}
	numbers.push_back(stoi(str));

	// 2. �����ڿ� ���� ��� ������ �����.
	temp = 0;
	makePerm(0);

	answer = temp;
	return answer;
}

int main() {
	string expression;
	long long answer;

	cin >> expression;
	answer = solution(expression);
	cout << answer;
	return 0;
}