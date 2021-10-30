// 8_3 개미 전사
// 일직선 상에 창고, 한 칸 이상 떨어진 식량창고를 약탈해야 함
// 최대로 약탈할 수 있는 경우의 수

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> arr;
	int dp[100];

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	dp[0] = arr[0];                                  // 첫 번쨰 dp에 첫 번째 식량값 저장
	dp[1] = max(arr[0], arr[1]);                // dp1에는 앞의 식량 중에 더 많은 식량 구하기
	for (int i = 2; i < n; i++) {
		dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);              
	}

	cout << dp[n - 1] << endl;
}
