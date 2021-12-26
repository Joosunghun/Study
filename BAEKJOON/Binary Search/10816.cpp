// 문제 10816 숫자 카드 2
// N개의 숫자카드
// M개의 정수가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 몇 개 가지고 있는지 구하는 프로그램

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int n, m;
	vector<int> arr;

	cin >> n;
	for (int i = 0; i < n; i++) {        // n개의 숫자카드 입력
		int x;
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());   // 숫자카드 오름차순으로 정렬

	cin >> m;
	for (int i = 0; i < m; i++) {        // m개의 정수 입력 후
		int x;
		cin >> x;
		auto upper = upper_bound(arr.begin(), arr.end(), x);       // x 값보다 이상값이 처음 나타나는 위치, auto = 타입추론, 변수의 형식이 자동으로 결정됨
		auto lower = lower_bound(arr.begin(), arr.end(), x);       // x 값보다 초과값이 처음 나타나는 위치

		cout << upper - lower << ' ';         // 두 위치를 빼주면 x값의 개수
	}

	return 0;
}