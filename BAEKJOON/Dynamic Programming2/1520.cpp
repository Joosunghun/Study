// 문제 1520번 내리막 길
// 직사각형 모양에 여러 칸으로 나뉘어져 있는 지도, 한 칸은 한 지점을 나타내는데 각 칸에는 그 지점의 높이가 쓰여 있으며, 각 지점 사이의 이동은 지도에서 상하좌우 이웃한 곳끼리만 가능
// 제일 왼쪽 위 칸에서 시작해서 제일 오른쪽 아래칸으로 이동할 때 높은 곳에서 낮은 곳으로만 이동하고자 한다.
// 지도가 주어질 때, 제일 왼쪽 위에서 제일 오른쪽 아래 지점 까지 항상 내리막 길로만 이동하는 경로의 개수를 구하는 프로그램

#include <iostream>
using namespace std;

int map[501][501];
int dp[501][501];
bool visited[501][501];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

int n, m;

int dfs(int y, int x) {
	if (y == m && x == n)
		return 1;

	if (visited[y][x])
		return dp[y][x];
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny > 0 && ny <= m && nx > 0 && nx <= n) {
			if (map[y][x] > map[ny][nx])
				dp[y][x] += dfs(ny, nx);
		}
	}

	return dp[y][x];
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	cout << dfs(1, 1) << '\n';

	return 0;
}