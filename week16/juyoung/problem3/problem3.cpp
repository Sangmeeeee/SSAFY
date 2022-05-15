#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

char op[3] = { '+', '-', '*' }; // 연산자
char prior[3];					// 우선순위대로 연산자를 저장하는 배열
bool check[3];					// 연산자가 조합에 사용되었는지를 저장하는 배열
vector<long long> numbers;		// 피연산자
vector<char> oplist;			// 연산자 목록
long long temp;					// 정답 임시 저장

long long calc() {
	vector<long long> copy_num = numbers;
	vector<char> copy_op = oplist;

	// 우선순위가 큰 것부터 처리한다.
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
	// 3. 모든 연산자의 우선순위가 정해지면 그에 맞게 계산한다.
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

	// 1. 피연산자와 연산자 목록을 벡터로 분리한다.
	string str = "";
	for (int i = 0; i < expression.length(); i++) {
		// 연산자라면
		if (expression[i] < '0' || expression[i] > '9') {
			// 문자열로 된 숫자를 정수로 변환하여 피연산자 목록에 삽입하고
			numbers.push_back(stoi(str));
			str = "";
			// 연산자 목록에 삽입한다.
			oplist.push_back(expression[i]);
			continue;
		}
		str += expression[i];
	}
	numbers.push_back(stoi(str));

	// 2. 연산자에 대한 모든 조합을 만든다.
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