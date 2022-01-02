// 문제 1003 피보나치 함수
// 피보나치 함수에서 0과 1이 각각 몇번 추력되는지 구하는 프로그램
// BUTTOM-UP  방식 사용

#include <iostream>
using namespace std;

int main(void) {
	int T, N;
	int dp[41] = {0,1};          // 횟수에 대한 값을 저장하는 dp

	cin >> T;
	
	for (int n = 2; n <= 40; n++) {         // 피보나치 수열 생성
		dp[n] = dp[n - 1] + dp[n - 2];
	}

	for (int i = 0; i < T; i++) {         // 표를 만들어서 확인하면 0이 나오는 값과 1이 나오는 값은 각각 피보나치 수열 n-1과 n과 같음
		cin >> N;
		if (N == 0)
			cout << "1 0\n";
		else
			cout << dp[N - 1] << ' ' << dp[N] << '\n';
	}
	return 0;
}