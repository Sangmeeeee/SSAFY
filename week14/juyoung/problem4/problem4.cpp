#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	string s;
	map<string, double> m;
	double cnt = 0; // ��ü ����

	// ���̻� �Է��� ���� ������(EOF����)
	while (getline(cin, s)) {
		m[s]++;
		cnt++;
	}

	//�Ҽ��� ������ �ڸ������� �ٷ� �� �ְ� �����Ѵ�.
	cout << fixed; 
	// ���� �� fixed ������ ������ ������ �Ҽ��� ���ļ� 4�ڸ��� ��Ÿ����.
	// ������ fixed ������ �������Ƿ� �Ҽ��� �Ʒ� 4�ڸ��� ��Ÿ���ش�.
	cout.precision(4);

	// map�� ��ȸ�ϸ� ����Ѵ�.
	auto iter = m.begin();
	while (iter != m.end()) {
		double p = (iter->second / cnt) * 100;
		cout << iter->first << " " << p << "\n";
		iter++;
	}

	return 0;
}