// 문제 2178번 미로탐색
// N x M 크기의 배열로 표현되는 미로
// 1은 이동할 수 있는 칸, 0 은 이동할 수 없는 칸
// (1,1)에서 (N,M)으로 이동할 때 지나야 하는 최소 칸 수를 구하는 프로그램

#include <iostream>
#include <queue>
using namespace std;

int n, m;
string map[101];
int dist[101][101];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

queue<pair<int, int>> q;

void bfs(int x, int y) {             
	q.push(make_pair(x,y));
	dist[x][y] = 1;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m && dist[nx][ny] == 0 && map[nx][ny] == '1') {         // 범위 내에서 조건을 만족하면 큐에 저장후 값 1 더하기
				q.push(make_pair(nx, ny));
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
}

int main(void) {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {       
		cin >> map[i];
	}

	bfs(0, 0);

	cout << dist[n-1][m-1] << '\n';           // 시작이 0,0, 이었으므로 1씩 빼주어야함
		
}