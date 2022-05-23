#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	vector<string> cache(cacheSize, "");

	for (int c = 0; c < (int)cities.size(); c++) {
		string city = cities[c];
		for (int i = 0; i < city.length(); i++) {
			if ('A' <= city[i] && city[i] <= 'Z')
				city[i] += 32;
		}

		bool flag = false;

		// 만약 캐시 안에 도시 이름이 있다면
		for (int i = 0; i < cacheSize; i++) {
			if (cache[i] == city) {
				cache.erase(cache.begin() + i);
				cache.push_back(city);
				answer += 1;
				flag = true;
				break;
			}
		}

		// 만약 캐시 안에 도시 이름이 없다면
		if (!flag) {
			if (cacheSize > 0) {
				cache.erase(cache.begin());
				cache.push_back(city);
			}
			answer += 5;
		}
	}

	return answer;
}

int main() {
	int cacheSize;
	int n;
	vector<string> cities;
	string input;
	int answer;

	cin >> cacheSize;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		cities.push_back(input);
	}

	answer = solution(cacheSize, cities);
	cout << answer;

	return 0;
}

/*
3
10
Jeju Pangyo Seoul NewYork LA Jeju Pangyo Seoul NewYork LA

3
9
Jeju Pangyo Seoul Jeju Pangyo Seoul Jeju Pangyo Seoul

2
12
Jeju Pangyo Seoul NewYork LA SanFrancisco Seoul Remo Paris Jeju NewYork Rome

5
12
Jeju Pangyo Seoul NewYork LA SanFrancisco Seoul Rome Paris Jeju NewYork Rome

2
4
Jeju Pangyo NewYork newyork

0
5
Jeju Pangyo Seoul NewYork LA
*/