// ���� 1012�� ����� ����
// �����������̰� �Ѹ����� ������ �� �����̴� ������ �ٸ� ���߷� �̵� ����
// �����������̰� �� ���� �ʿ����� ����ϴ� ���α׷�

#include <iostream>
using namespace std;

int t, n, m, k;
int map[51][51];
bool visited[51][51];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };


void reset() {             // �ѹ� ����� ���� �ʱ�ȭ �ϴ� �Լ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}
}

void dfs(int y, int x) {
	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {      // 4�������� �̵��ϸ� Ž��
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= m || ny >= n)
			continue;

		if (map[ny][nx] == 1 && visited[ny][nx] == false)
			dfs(ny, nx);
	}
}

int main(void) {
	cin >> t;
	
	while(t--) {
		cin >> m >> n >> k;

		reset();

		while(k--) {        // ���߸� ���� �ڸ��� 1 �ֱ�
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {          // ���� ���� dfs ����
			for (int j = 0; j < m; j++) {
				if (visited[i][j] == false && map[i][j] == 1) {
					dfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';
	}

}