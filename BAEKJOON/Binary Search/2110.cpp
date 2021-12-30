// 문제 2110번 공유기 설치
// 집 N개가 수직선 위에 있다. 집 여러개가 같은 좌표를 가지는 일은 없다.
// 집에 공유기 C개를 설치하려고한다. 한 집에는 하나의 공유기 설치 가능, 가장 인접한 두 공유기 사이의 거리를 가능한 크게 하여 설치하려고 한다.
// C개의 공유기를 N개의 집에 적당히 설치해서, 가장 인접한 두 공유기 사이의 거리를 최대로 하는 프로그램

#include <iostream>
#include <vector>
#include  <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, c;
	vector<int> arr;

	cin >> n >> c;
	for (int i = 0; i < n; i++) {    // 공유기에 값 넣기
		int x;
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());     // 정렬

	int start = 0;
	int end = arr.back();       
	int ans = 0;

	while (start <= end) {
		long long mid = (start + end) / 2;
		int before_set_idx = 0;
		int set_num = 1;

		for (int i = 1; i < n; i++) {        // 공유기의 값이 현재 값의 mid 이상인 경우에만 설치 가능
			if (arr[i] - arr[before_set_idx] >= mid) {      // 현재 위치와 직전 설치한 위치의 간격이 mid 보다 크다면
				before_set_idx = i;               // 현재 위치 넣기
				set_num++;
			}
		}

		if (set_num >= c) {             // 입력받은 갯수가 C보다 크면 현재의 최댓값, start를 변경하여 더 큰 값 탐색
			ans = mid;
			start = mid + 1;
		}           
		
		else                              // 반대의 경우 end를 변경하여 더 작은 값 탐색
			end = mid - 1;

	}
	cout << ans << '\n';
	return 0;

}