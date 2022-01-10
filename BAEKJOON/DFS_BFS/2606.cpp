// 문제 2606번 바이러스
// 웜 바이러스는 네트워크를 통해 전파된다. 한 컴퓨터가 바이러스에 걸리면 그 컴퓨터와 네트워크 상에 연결된 모든 컴퓨터는 웜 바이러스에 걸리게 된다.
// 1번 컴퓨터가 웜 바이러스에 걸리고, 컴퓨터 수와 네트워크 상에서 서로 연결되어 있는 정보가 주어질 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게되는 컴퓨터의 수를 출력하는 프로그램

#include <iostream>
using namespace std;

int n, m;               // 컴퓨터의 수, 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수
bool visited[101];          // 정점 방문 여부
int map[101][101];        // 인접 행렬 그래프
int cnt = 0;

void dfs(int v) {                   // dfs를 사용해 방문한 횟수를 재기 위해 안에 cnt를 넣음
	visited[v] = true;
	cnt++;

	for (int i = 1; i <= n; i++) {
		if (map[v][i] == 1 && visited[i] == 0)
			dfs(i);
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	 
	dfs(1);                           // 1을 시작으로 dfs 진행
	cnt--;                            // 처음 1도 cnt에 포함되었으므로 첫 cnt 값 빼기 
	cout << cnt << '\n';

	return 0;
}