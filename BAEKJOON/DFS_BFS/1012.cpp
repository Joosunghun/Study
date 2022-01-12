// 문제 1012번 유기농 배추
// 배추흰지렁이가 한마리라도 있으면 이 지렁이는 인접한 다른 배추로 이동 가능
// 배추흰지렁이가 몇 마리 필요한지 출력하는 프로그램

#include <iostream>
using namespace std;

int t, n, m, k;
int map[51][51];
bool visited[51][51];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };


void reset() {             // 한번 사용한 맵을 초기화 하는 함수
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

	for (int i = 0; i < 4; i++) {      // 4방향으로 이동하며 탐색
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

		while(k--) {        // 배추를 심을 자리에 1 넣기
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {          // 맵을 돌며 dfs 실행
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