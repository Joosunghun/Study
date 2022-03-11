// 문제 7562번 나이트의 이동
// 체스판 위에 한 나이트가 놓여져 있다. 나이트가 한 번에 이동할 수 있는 칸이 있따.
// 나이트가 이동하려는 칸이 주어진다. 나이트가 그 칸에 도달하기 위해 움직인 횟수를 구하는 프로그램

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