// 문제 2667번 반디번호붙이기
// 정사각형 모양의 지도, 1은 집이 있는곳, 0은 집이 없는 곳
// 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙인다.
// 대각선상에 있는 집은 연결된 것이 아님
// 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
int map[26][26];
bool visited[26][26];
vector<int> v;
int cnt = 0;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void dfs(int x, int y) {
	visited[x][y] = true;
	cnt++;
	map[x][y] = 1;
	for (int i = 0; i < 4; i++) {      // 4방향으로 이동하며 탐색
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n)
			continue;

		if (map[nx][ny] == 1 && visited[nx][ny] == false)
			dfs(nx, ny);
	}
}

int main(void) {	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;            // 정사각형의 크기

	for (int i = 0; i < n; i++) {            // 맵에 1, 0넣기
		string input;
		cin >> input;

		for (int j = 0; j < n; j++) {
			map[i][j] = input.at(j) - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == false && map[i][j] == 1) {
				dfs(i, j);
				v.push_back(cnt);         // 연결되어있는 아파트 push
				cnt = 0;
			}
		}
	}

	cout << v.size() << '\n';          // 단지의 개수
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
	return 0;
}