// 문제 11279번 최대 힙
// 최대 힙을 이용하여 다음과 같은 연산을 지원하는 프로그램
// 1. 배열에 자연수 x를 넣는다. 2. 배열에서 가장 큰 값을 출력하고, 그 값을 배열에서 제거한다.

#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);        // 시간을 줄이기 위함
	cin.tie(0);
	cout.tie(0);

	int n;
	priority_queue<int> pq;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (pq.empty()) {              // 큐가 비었을 떄
			if (x == 0) {                 // x == 0 이면 0 출력
				cout << 0 << '\n';
			}
			else                          // 0 이 아니면 push
				pq.push(x);
		}
		else {                           // 큐가 비지 않았을 때
			if (x == 0) {                // x == 0 이면 제일 큰 값 출력 후 pop
				cout << pq.top() << '\n';
				pq.pop();
			}
			else                        // 0이 아니면 push
				pq.push(x);
		}

	}
}