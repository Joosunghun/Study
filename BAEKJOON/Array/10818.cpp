// 문제 10818번 최소, 최대
// N개의 정수가 주어진다. 이때, 최솟값과 최댓값을 구하는 프로그램

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	vector<int> arr;

	cin >> n;

	for (int i = 0; i < n; i++) {        // 벡터에 n개수만큼 숫자 넣기
		int x;
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());      // 오름차순으로 정렬

	int max = arr[n-1];          
	int min = arr[0];

	cout << min << ' ' << max << '\n';
}