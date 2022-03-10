// 문제 2206번 벽 부수고 이동하기
// N x M의 행렬로 표현되는 맵
// 맵에서 0은 이동할 수 있는 곳, 1은 벽이 있는곳
// (1,1)에서 (N,M)까지 이동하려 하는데 최단경로로 이동하려함
// 벽을 한개까지 부수고 이동해도 됨
// 맵이 주어졌을 때, 최단 경로를 구하는 프로그램

#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[1001][1001];
int visited[1001][1001][2];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1, -1, 0, 0 };

int bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ { 0,0 }, 1 });          
	visited[0][0][1] = 1;

	while (!q.empty()) {
		pair<pair<int, int>, int> p = q.front();
		q.pop();
		if (p.first.first == n - 1 && p.first.second == m - 1)
			return visited[n - 1][m - 1][p.second];
		for (int i = 0; i < 4; i++) {
			int ny = p.first.first + dy[i];
			int nx = p.first.second + dx[i];
			int power = p.second;          // 벽을 부술수 있는 지 여부

			if (nx < 0 || ny < 0 || ny >= n || nx >= m || visited[ny][nx][power])
				continue;
			else {
				if (power && arr[ny][nx] == 1) {
					q.push({ {ny, nx}, power - 1 });
					visited[ny][nx][power - 1] = visited[p.first.first][p.first.second][power] + 1;
				}
				if (arr[ny][nx] == 0) {
					q.push({ {ny,nx},power });
					visited[ny][nx][power] = visited[p.first.first][p.first.second][power] + 1;
				}
			}
		}
	}
	return -1;
}

int main() {
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	cout << bfs() << '\n';
}