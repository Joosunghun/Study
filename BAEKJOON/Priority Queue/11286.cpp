// 문제 11286번 절댓값 힙
// 다음 조건을 만족하는 자료구조
// 1. 배열에 정수 x 를 넣는다. 2. 배열엣 절댓값이 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다. 절댓값이 가장 작은 값이 여러 개일때는, 가장 작은 수를 출력

#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;            // 오름차순 정렬

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			if (!pq.empty()) {
				cout << pq.top().second << '\n';
				pq.pop();
			}
			else
				cout << 0 << '\n';
		}
		else
			pq.push({ abs(x),x });           // priority_queue의 첫번째 값에는 절댓값 두번째 값에는 실제 값을 넣음
	}
	return 0;
}