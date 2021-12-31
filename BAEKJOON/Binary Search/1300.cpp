// 문제 1330번 K번째 수
// 크기가 N X N 인 배열 A, 배열에 들어있는 수 A[i][j] = i x j 이다.
// 이 수를 일차원 배열 B에 넣으면 B의 크기는 N x N 이된다.
// B를 오름차순 정렬 했을 때, B[k]를 구하는 프로그램

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, k;
	cin >> n >> k;

	int start = 1;
	int end = k;
	int result = 0;
	while (start <= end) {
		int cnt = 0;
		int mid = (start + end) / 2;
		for (int i = 1; i <= n; i++) {
			cnt += min(mid / i, n);        // mid보다 작은 j의 수 (i + j <= mid)
		}
		if (cnt < k)
			start = mid + 1;
		else {
			result = mid;
			end = mid - 1;
		}
	}
	cout << result << '\n';
}