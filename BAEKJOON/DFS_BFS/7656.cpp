// ���� 7575�� �丶��
// N x M ũ���� ���ڿ� ��ĭ�� �־ �����Ѵ�.
// ���� �� �Ϸ簡 ������ ���� ���� �丶����� ���� �丶���� ������ �޾� �Ͱ� �ȴ�.
// â�� ������ �丶����� ��ĥ�� ������ �� �Ͱ� �Ǵ��� �ּ� �ϼ��� ���ϴ� ���α׷�
// �� ���� �� ���ٸ� -1 ���

#include <iostream>
#include <queue>
using namespace std;

int m, n;
int map[1001][1001];

queue<pair<int, int>> q;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void bfs(void) {         // ��ü Ž���� ���� BFS
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx <= 0 || nx > n || ny <= 0 || ny > m)       // ���� ���� conticne
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
    for (int i = 1; i <= n; i++) {          // �丶���� ���� ����
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