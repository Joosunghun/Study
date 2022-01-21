// 문제 7575번 토마토
// N x M 크기의 상자에 한칸씩 넣어서 보관한다.
// 보관 후 하루가 지나면 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다.
// 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지 최소 일수를 구하는 프로그램
// 다 익을 수 없다면 -1 출력

#include <iostream>
#include <queue>
using namespace std;

int m, n;
int map[1001][1001];

queue<pair<int, int>> q;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void bfs(void) {         // 전체 탐색을 위한 BFS
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx <= 0 || nx > n || ny <= 0 || ny > m)       // 범위 내면 conticne
                continue;
            if (map[nx][ny] == 0) {
                map[nx][ny] = map[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    for (int i = 1; i <= n; i++) {          // 토마토의 상태 삽입
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1)
                q.push(make_pair(i, j));
        }
    }

    bfs();

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] == 0) {
                cout << "-1" << '\n';
                return 0;
            }

            if (cnt < map[i][j])
                cnt = map[i][j];
        }
    }

    cout << cnt - 1 << '\n';

    return 0;

}