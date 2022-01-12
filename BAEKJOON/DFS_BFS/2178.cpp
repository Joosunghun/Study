// ���� 2178�� �̷�Ž��
// N x M ũ���� �迭�� ǥ���Ǵ� �̷�
// 1�� �̵��� �� �ִ� ĭ, 0 �� �̵��� �� ���� ĭ
// (1,1)���� (N,M)���� �̵��� �� ������ �ϴ� �ּ� ĭ ���� ���ϴ� ���α׷�

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

			if (0 <= nx && nx < n && 0 <= ny && ny < m && dist[nx][ny] == 0 && map[nx][ny] == '1') {         // ���� ������ ������ �����ϸ� ť�� ������ �� 1 ���ϱ�
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

	cout << dist[n-1][m-1] << '\n';           // ������ 0,0, �̾����Ƿ� 1�� ���־����
		
}