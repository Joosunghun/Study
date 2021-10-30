// 8_5 효율적인 화폐 구성
// N 가지 종류의 화폐, 가치의 합 M
// 화폐 개수를 최소한으로 사용하는 방법
// 경우의 수를 출력 불가능 할 때는 -1 을 출력

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n, m;
	int dp[101];
	vector<int> arr;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x ;
		arr.push_back(x);
	}


}