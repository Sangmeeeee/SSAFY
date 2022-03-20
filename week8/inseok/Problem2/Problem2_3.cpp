#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int N;
	//input firstLine
	cin >> N;
	vector<int> A;//-~+
	int neg = 0;
	//input secondLine
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		A.push_back(input);
		if (input < 0)neg++;
	}
	//sol
	sort(A.begin(), A.end());
	int l = neg - 1, r = neg;
	int minAbsDiff = 2087654321;
	pair<int, int> combi;
	//젤 첨부터 다 양수면 
	if (A[0] > 0) {
		combi.first = A[0];
		combi.second = A[1];
	}
	//젤 끝까지 다 음수면
	else if (A[A.size() - 1] < 0) {
		combi.first = A[A.size() - 2];
		combi.second = A[A.size() - 1];
	}
	else {
		//-- min check
		if (0 <= neg - 2) {
			int diff = A[neg-2] + A[neg-1];
			if (abs(diff) < minAbsDiff) {
				minAbsDiff = abs(diff);
				combi.first = A[neg-2];
				combi.second = A[neg-1];
			}
		}
		
		//++ min check
		if (neg+1<A.size()) {
			int diff = A[neg] + A[neg+1];
			if (abs(diff) < minAbsDiff) {
				minAbsDiff = abs(diff);
				combi.first = A[neg];
				combi.second = A[neg+1];
			}
		}
		
		//-+ min check
		while (r < A.size() && 0 <= l) {
			int diff = A[l] + A[r];
			if (abs(diff) < minAbsDiff) {
				minAbsDiff = abs(diff);
				combi.first = A[l];
				combi.second = A[r];
			}
			//diff 가 0 보다 작을땐 acid UP
			if (diff < 0) {
				r++;
			}
			else if (diff == 0) {
				minAbsDiff = 0;
				combi.first = A[l];
				combi.second = A[r];
				break;
			}
			// 0보다 클땐 base Up
			else if (0 < diff) {
				l--;
			}
		}//End While
	}
	cout << combi.first << " " << combi.second;

}
//https://www.acmicpc.net/problem/2470
//두용액

/*
5
-2 50 -99 -1 -98
*/

/*
	원래 Acid시작, Base 시작 에서 부터 하나하나 올리면서 찾으려 했는데 저런 상황에서 문제가 생기더라.
*/
//인후 방법 충격... 하