// ���� 1520�� ������ ��
// ���簢�� ��翡 ���� ĭ���� �������� �ִ� ����, �� ĭ�� �� ������ ��Ÿ���µ� �� ĭ���� �� ������ ���̰� ���� ������, �� ���� ������ �̵��� �������� �����¿� �̿��� �������� ����
// ���� ���� �� ĭ���� �����ؼ� ���� ������ �Ʒ�ĭ���� �̵��� �� ���� ������ ���� �����θ� �̵��ϰ��� �Ѵ�.
// ������ �־��� ��, ���� ���� ������ ���� ������ �Ʒ� ���� ���� �׻� ������ ��θ� �̵��ϴ� ����� ������ ���ϴ� ���α׷�

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