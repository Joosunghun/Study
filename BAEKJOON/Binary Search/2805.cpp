// 문제 2805번 나무 자르기
// 나무 M 미터가 필요. 절단기의 높이 H, H보다 높이가 큰 나무는 윗 부분이 잘림
// 딱 필요만 한큼만 나무를 자르려고 할 때, 절단기에 설정할수 있는 최댓값을 구하는 프로그램

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n, m;           // 나무의 수 와, 필요한 나무의 길이
	vector<int> h;      // 나무의 높이를 담기 위한 벡터

	cin >> n >> m;
	for (int i = 0; i < n; i++) {       // 나무 높이 받아오기
		int x;
		cin >> x;
		h.push_back(x);
	}

	int result = 0;
	int start = 0;       // 시작 값
	int end = *max_element(h.begin(), h.end());       // 끝 값은 나무 길이중 가장 긴 나무 

	while (start <= end) {        // 이진탐색으로
		long long int total = 0;
		int mid = (start + end) / 2;
		for (int i = 0; i < n; i++) {         // 필요한 나무의 합 
			if(h[i] > mid)
				total += h[i] - mid;
		}
		if (total < m)            // 필요한 나무의 길이가 적다면 절단기 높이 줄이기
			end = mid - 1;
		else {                    // 많거나 같다면 절단기 높이 늘리고 토탈이 최솟값일 때 출력
			result = mid;
			start = mid + 1;
		}
	}
	cout << result << '\n';
}