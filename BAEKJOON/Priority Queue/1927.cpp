// 문제 1927번 최소 힙
// 최소 힙을 이용하여 다음과 같은 연산을 지원하는 프로그램
// 1. 배열에 자연수 x를 넣는다. 2. 배열에서 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다.

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	
	priority_queue<int, vector<int>, greater<int>> pq;        // greater : 우선순위 큐를 오름차순으로 정렬
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (pq.empty()) {
			if (x == 0)
				cout << 0 << '\n';
			else
				pq.push(x);
		}
		else {
			if (x == 0) {
				cout << pq.top() << '\n';
				pq.pop();
			}
			else
				pq.push(x);
		}
	}
	return 0;
}
	int n;