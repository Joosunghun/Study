// ���� 7569�� �丶��
// ���� 7656���� 3���� ����

#include <iostream>
#include <queue>
using namespace std;

struct tomato {           // 3���� ť�� ����� ���� ����ü
	int x, y, z;
};

int m, n, h;
int map[101][101][101];
int dx[] = {-1,1,0,0,0,0};
int dy[] = { 0,0,-1,1,0,0 };
int dz[] = { 0,0,0,0,-1,1 };
queue<tomato> q;
int cnt = 0;

void bfs() {                //	��ü Ž���� ���� bfs
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;

		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (nx < 0 || nx >= h || ny < 0 || ny >= n || nz < 0 || nz >= m)          // ���� ������ bfs ����
				continue;
			if (map[nx][ny][nz]) 
				continue;
			map[nx][ny][nz] = map[x][y][z] + 1;
			q.push({ nx,ny, nz });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {          // ��� �� �ֱ�
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1) {
					q.push({ i,j,k });
				}
			}
		}
	}

	bfs();
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (map[i][j][k] == 0) {               // ������ �丶�䰡 ������ ��� -1 ���
					cout << -1 << '\n';
					return 0;
				}
				if (cnt < map[i][j][k])
					cnt = map[i][j][k];
			}
		}
	}
	cout << cnt - 1 << '\n';
	return 0;
}