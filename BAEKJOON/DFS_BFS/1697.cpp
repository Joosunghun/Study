// 문제 1697번 숨바꼭질
// 점 N과 K가 주어진다.
// N은 1초후에 n-1, n+1, 혹은 n*2로 이동가능
// N이 K를 찾을 수 있는 가장 빠른 시간을 구하는 프로그램

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

		if (p - 1 >= 0 && visited[p- 1] == 0) {            // -1 가는 경우
			q.push(p - 1);
			visited[p - 1] = visited[p] + 1;
		}

		if (p + 1 <= 100000 && visited[p + 1] == 0) {       // +1 가는 경우
			q.push(p + 1);
			visited[p + 1] = visited[p] + 1;
		}

		if (p * 2 <= 100000 && visited[2 * p] == 0) {       // *2 하는 경우
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