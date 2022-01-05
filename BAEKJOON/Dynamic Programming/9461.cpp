// 문제 9461번 파도반 수열
// 나선 모양으로 놓여져있는 삼각형 존재
// 첫 삼각형은 정삼각형으로 변의 길이가 1
// 나선에서 가장 긴 변의 길이를 k라 했을 때, 그 변의 길이가 k인 정삼각형 추가를 반복
// P(N)은 나선에 있는 정삼각형의 변의 길이
// N이 주어졌을  때, P(N)을 구하는 프로그램 작성

#include <iostream>
using namespace std;
long long dp[101] = {0,1,1,};

long long P(int n) {           
	if (n < 3)
		return dp[n];
	else if (dp[n] == 0)
		dp[n] = P(n - 2) + P(n - 3);       // 파도반 수열에서 찾은 점화식
	return dp[n];
}

int main(void) {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << P(n) << '\n';
	}
}