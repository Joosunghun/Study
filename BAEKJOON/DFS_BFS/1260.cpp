// 문제 1260번 DFS와 BFS
// 그래프를 DFS 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램
// 방문할 수 있는 정점이 여러 개인 경우 번호가 작은 것 부터 방문

#include <iostream>
#include <queue>
using namespace std;

int n, m, v;
int map[1001][1001];        // 인접 행렬 그래프
bool visited[1001];   // 정점 방문 여부
queue<int> q;

void reset() {                // 위치를 초기화 하기 위한 함수
	for (int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
}

void dfs(int v) {
	visited[v] = true;
	cout << v << ' ';

	for (int i = 1; i <= n; i++) {                // 현재 정점과 연결되어 있고 방문하지 않았으면
		if (map[v][i] == 1 && visited[i] == 0)
			dfs(i);
	}
}

void bfs(int v) {
	q.push(v);
	visited[v] = true;
	cout << v << ' ';
	while (!q.empty()) {
		v = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (map[v][i] == 1 && visited[i] == 0) {   // 현재 정점과 연결되어 있고 방문하지 않았으면
				q.push(i);
				visited[i] = true;
				cout << i << ' ';
			}
		}
	}
}

int main(void) {
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	reset();
	dfs(v);

	cout << '\n';

	reset();
	bfs(v);

	return 0;
}