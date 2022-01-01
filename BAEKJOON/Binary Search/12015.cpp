// 문제 12015번 가장 긴 증가하는 부분 수열 2
// 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	vector<int> arr;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		auto it = lower_bound(arr.begin(), arr.end(), x);            // lower_bound 함수는 어떤 수보다 크거나 같은 가장 작은 정수를 이분탐색으로 찾음
		if (it != arr.end())       // 찾은 값이 끝 값이 아니라면 it에 x값을 넣는다
			*it = x;
		else                        // 가장 마지막 값이라면 arr 벡터에 push
			arr.push_back(x);
	}
	
	cout << arr.size() << '\n';     // 벡터의 크기를 출력
}