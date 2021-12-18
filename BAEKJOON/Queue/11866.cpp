// 문제 11866번 요세푸스 문제 0
// N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K가 주어진다.
// 한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다.
// N명이 모두 제거될떄 까지 계속 된다.
// 제거 되는 순서는 (N,K) - 요세푸스 순열이라고 한다.

#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	int n, k;          // N명이 원으로 앉고, K번 제거
	queue<int> q;       // 앉아있는 사람들의 큐

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {       // 1~N 입력
		q.push(i);
	}

	cout << "<";
	
	while (!q.empty()) {            // 큐가 비기전까지 반복
		for (int i = 1; i <= k - 1; i++) {       // front에서 k-1개 만큼 back에 추가하고, front에서 뺀 후 삭제
			q.push(q.front());            // front의 값을 맨 뒤로
			q.pop();                         // 그 값 삭제
		}
		cout << q.front();           // k 번째 숫자 출력
		q.pop();                      // k 번째 숫자 삭제

		if (!q.empty()) {
			cout << ", ";               // 큐가 비어있으면 출력 x
		}
	}
	cout << ">" << '\n';
	return 0;
}