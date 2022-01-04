// 문제 1904번 01타일
// 0 또는 1로만 이루어진 타일
// 1 하나만 있는 1타일과 0 두개있는 00 타일만 존재한다
// N이 주어졌을 때 만들 수 있는 총 가짓수를 구하는 프로그램

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> dp = {0,1,2};      // 답을 저장하기 위한 벡터
	int tmp = 0;

	for (int i = 3; i <= n; i++) {
		tmp = (dp[i - 1] + dp[i - 2]) % 15746;          // 점화식을 세워보니 0, 1, 2, 3, 5, 8, 13 ... 순으로 피보나치 수열
		dp.push_back(tmp);
	}

	cout << dp[n] << '\n';
	return 0;
}