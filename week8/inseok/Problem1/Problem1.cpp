#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*
bool compare(int i, int j){
	return i > j;
}
*/
int main(void) {
	int N,M;
	cin >> N >> M;
	vector<int> A;
	//input
	for (int i = 0; i < N; i++){
		int input;
		cin >> input;
		A.push_back(input);
	}
	//sol
	//inseok : vector sort 할때 저렇게 한다.
	sort(A.begin(), A.end());//반대로 하고 싶으면?
	//sort(A.begin(), A.end(),greater<int>());//반대로 하고 싶으면?
	//sort(A.begin(), A.end(),compare);//이렇게 하는 방법도 있다.
	int lIdx = 0;
	int rIdx = 1;
	int minDist = 2087654321;
	while (rIdx<N && lIdx<=rIdx) {
		//dist 만들기
		int dist = A[rIdx] - A[lIdx];
		//dist 가 M 미만 이면 rIdx++;
		if (dist < M) {
			rIdx++;
		}
		//dist 가 M 이상이면 lIdx++;
		//minDist 갱신
		if (M <= dist) {
			lIdx++;
			minDist = min(dist,minDist);
		}
	}
	cout << minDist;
}