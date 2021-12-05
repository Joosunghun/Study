// 문제 2164 카드2
// 1부터 N까지의 카드
// 카드가 한장 남을때가지 같은 동작 반복
// 제일 위의 카드를 버린다. 그다음 제일 위의 카드를 제일 아래로 옮긴다 반복
// N이 주어졌을 떄, 제일 마지막으로 남게 되는 카드를 구하는 프로그램

#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (q.size() > 1) {
		q.pop();

		q.push(q.front());
		q.pop();
	}

	cout << q.front() << '\n';

}