// ���� 7562�� ����Ʈ�� �̵�
// ü���� ���� �� ����Ʈ�� ������ �ִ�. ����Ʈ�� �� ���� �̵��� �� �ִ� ĭ�� �ֵ�.
// ����Ʈ�� �̵��Ϸ��� ĭ�� �־�����. ����Ʈ�� �� ĭ�� �����ϱ� ���� ������ Ƚ���� ���ϴ� ���α׷�

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int arr[301][301];
bool visited[301][301];

int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };

int l;
queue<pair<int, int>> q;
int srcX, srcY, dstX, dstY;

void bfs(int a, int b) {
	q.push(make_pair(a, b));
	visited[a][b] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == dstX && y == dstY) {
			cout << arr[x][y] << '\n';

			while (!q.empty())
				q.pop();
			break;
		}

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < l && ny >= 0 && ny < l) {
				if (visited[nx][ny] == false) {
					visited[nx][ny] = true;
					arr[nx][ny] = arr[x][y] + 1;
					q.push(make_pair(nx, ny));

				}
			}
		}
	}
}

int main(void) {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> l;
		cin >> srcX >> srcY >> dstX >> dstY;
		bfs(srcX, srcY);
		memset(arr, 0, sizeof(arr));
		memset(visited, false, sizeof(visited));
	}

	return 0;
}