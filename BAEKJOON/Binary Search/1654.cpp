// 문제 1654 랜선 자르기
// N개의 랜선을 만든다.
// K개의 랜성르 가지고 있는데, 길이가 제각각이다. N개의 같은 길이의 랜선으로 만들고 싶기때문에 K개의 랜선을 잘라서 만든다.
// 이때 N개 이상 만들면서 만들 수 있는 최대 랜선의 길이를 구하는 프로그램

#include <iostream>
#include <algorithm>
using namespace std;


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;          // N개의 랜선 만들기, K개의 랜선 가지고있음
	int arr[10001];
	cin >> k >> n;

	for (int i = 0; i < k; i++) {       // k개 길이 넣기
		cin >> arr[i];
	}

	long long left = 1;
	long long right = *max_element(arr, arr+ k);           // *max_element =구간 안에서 최대 값을 구하는 함수
	int ans = 0;

	while(left <= right) {
		long long mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += (arr[i] / mid);
		}

		if (cnt < n)      // 나온 갯수가 필요한 개수보다 작으면 더 작게 잘라야함
			right = mid - 1;
		else {
			ans = mid;
			left = mid + 1;
		}
	}

	cout << ans << '\n';

	return 0;
}