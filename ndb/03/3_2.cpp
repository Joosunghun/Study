// 3_1 큰 수의 법칙
// N개 자연수, M번 더하는데 K 만큼만 연속해서 더해질 수 있음

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int i, n, m, k;
	vector<int> arr;
	int result = 0;
	int count = 0;
	cin >> n >> m >> k;

	for (i = 0; i < n; i++) {                                // n 개의 수를 arr에 넣기
		int x;
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());                      // 정렬
	int first = arr[n - 1];                                 // 가장 큰 수
	int second = arr[n - 2];                           // 두 번째로 큰수

	count = (m / (k + 1)) * k;                         // 가장 큰 수가 더해지는 횟수 계산
	count += m % (k + 1);

	result += count * first;                             // 가장 큰 수 더하기
	result += (m - count) * second;               // 두 번째로 큰 수 더하기

	cout << result << endl;
	
}
