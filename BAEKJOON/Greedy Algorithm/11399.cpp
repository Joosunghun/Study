// 문제 11399번 ATM
// ATM에 N명의 사람들이 줄 서있어
// i번 사람이 돈을 인출하는데 걸리는 시간 Pi분
// 앞에 사람이 돈을 뽑을 때까지 기다려야함
// 각 사람이 돈을 인출하는데 필요한 시간의 합의 최솟값을 구하는 프로그램

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	vector<int> arr;

	cin >> n;
	for (int i = 0; i < n; i++) {                                // 모든 Pi받기
		int x;
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());                            // 오름차순으로 정렬
	int result = 0;
	for (int i = 0; i < n; i++) {                                 // 시간의 합의 최솟값을 구하기위해 arr[i]*(n-i) 만큼 결과값에 더함
		result += arr[i]*(n-i);
	}

	cout << result << '\n';                                   // 결과값 출력
}