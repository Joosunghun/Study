// 8_5 효율적인 화폐 구성
// N 가지 종류의 화폐, 가치의 합 M
// 화폐 개수를 최소한으로 사용하는 방법
// 경우의 수를 출력 불가능 할 때는 -1 을 출력

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	int n, m;
	vector<int> arr;

	cin >> n >> m;                                        // 정수 n,m 입력 받기
	for (int i = 0; i < n; i++) {                           // 화폐 단위 입력 받기
		int x;
		cin >> x ;
		arr.push_back(x);
	}
	
	vector<int> dp(m + 1, 10001);                    // 계산 결과를 위한 DP 테이블 

	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= m; j++) {
			if (dp[j - arr[i]] != 10001) {                             // (i - k) 원을 만드는 방법이 존재하는 경우
				dp[j] = min(dp[j], dp[j - arr[i]] + 1);           // 최솟값을 저장
			}
		}
	} 
	if (dp[m] == 10001)                                                // m원을 만드는 방법이 없을 경우
		cout << -1 << endl;                                            // -1 출력
	else
		cout << dp[m] << endl;
}