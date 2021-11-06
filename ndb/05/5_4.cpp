// 5_4 미로 탈출
// N X M 크기의 미로 
// 현재 위치 (1,1), 출구는 (N,M), 한 번에 한 칸 이동 가능
// 괴물이 있는 부분 0, 괴물이 없는 부분 1
// 탈출하기 위해 움직여야 하는 최소 칸의 개수
// 최단경로를 찾기 위해서는 BFS 사용하기

#include <iostream>
#include <queue>
using namespace std;

int n, m;
int graph[201][201];

int dx[] = { -1,1,0,0 };                                           // 이동할 4가지 방향 정의 (상, 하, 좌, 우)
int dy[] = { 0,0,-1,1 };

int bfs(int x, int y) {                                               // BFS 구현
	queue<pair<int, int>> q;                                     // 큐 구현
	q.push({ x, y });
	
	while (!q.empty()) {                                           // 큐가 빌때까지 반복하기
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {                                 // 현재 위치에서 4가지 방향으로의 위치 확인
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;       // 공간을 벗어나면 무시
			if (graph[nx][ny] == 0) continue;                                 // 벽인 경우 무시
			if (graph[nx][ny] == 1) {                                            // 해당 노드를 처음 방문하면 최단거리 기록
				graph[nx][ny] = graph[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
	return graph[n - 1][m - 1];                                // 가장 오른쪽 아래까지의 최단거리 반환
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &graph[i][j]);
		}
	}
	cout << bfs(0, 0) << endl;                                 // (0, 0) 에서 출발 했을때 BFS를 수행한 결과 출력
	return 0;
}