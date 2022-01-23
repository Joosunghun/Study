// ���� 1697�� ���ٲ���
// �� N�� K�� �־�����.
// N�� 1���Ŀ� n-1, n+1, Ȥ�� n*2�� �̵�����
// N�� K�� ã�� �� �ִ� ���� ���� �ð��� ���ϴ� ���α׷�

#include <iostream>
#include <queue>
using namespace std;

int n, k;
queue<int> q;
int visited[100001];

int bfs() {
	q.push(n);            
	visited[n] = 1;

	while (q.empty()) {
		int p = q.front();
		q.pop();
		if (p == k)
			return visited[p] - 1;

		if (p - 1 >= 0 && visited[p- 1] == 0) {            // -1 ���� ���
			q.push(p - 1);
			visited[p - 1] = visited[p] + 1;
		}

		if (p + 1 <= 100000 && visited[p + 1] == 0) {       // +1 ���� ���
			q.push(p + 1);
			visited[p + 1] = visited[p] + 1;
		}

		if (p * 2 <= 100000 && visited[2 * p] == 0) {       // *2 �ϴ� ���
			q.push(p * 2);
			visited[p * 2] = visited[p] + 1;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	cout << bfs();
}