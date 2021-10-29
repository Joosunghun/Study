// 큰 수의 법칙

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

	for (i = 0; i < n; i++) {
		cin >> arr[i];                        // n 수만큼 배열에 숫자 넣기
	}

	sort(arr.begin(), arr.end());                      // 정렬
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";

	for (i = 0; i < m; i++) {
		if (count == k) {
			result += arr[n - 2];
			count = 0;
			continue;
		}

		count += 1;
		result += arr[n-1];

		cout << result << endl;
	}
	
}
