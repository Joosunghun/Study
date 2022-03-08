// 문제 2565번 전깃줄
// 두 전봇대 A와 B 사이에 전깃줄을 추가하다 보니 전깃줄이 서로 교차하는 경우가 발생
// 합선의 위험이 있어 이들 중 몇 개의 전깃줄을 없애 전깃줄이 교차하지 않도록 만들려고 한다.
// 전깃줄이 전봇대에 연결되는 위치는 전봇대 위에서부터 차례대로 번호가 매겨진다.
// 전깃줄의 개수와 전깃줄들이 두 전봇대에 연결되는 위치의 번호가 주어질 때, 남아 있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수를 구하는 프로그램

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[102];

int main(void) {
	int n, a, b;
	int result = 0;
	cin >> n;
	
	vector<pair<int, int>> v;
	v.emplace_back(0, 0);       // emplace_back : vector의 요소 끝에 원소를 추가하는 함수, 직접 객체를 생성하여 삽입
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.emplace_back(a, b);
	}
	sort(v.begin(), v.end());

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i].second > v[j].second) {
				if (dp[j] >= dp[i])
					dp[i] = dp[j] + 1;
			}
		}
		result = max(result, dp[i]);
	}

	cout << n - result << '\n';
	return 0;
}