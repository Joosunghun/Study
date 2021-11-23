// 12_5 뱀
// N x N 정사각 보드 위에서 진행, 몇몇 칸에는 사과가 놓여져 있음, 벽 상하좌우엔 벽, 벽 또는 자기 자신의 몸과 부딪히면 게임이 끝남
// 게임 시작 위치는 맨 위 맨 좌측, 뱀의 길이 1, 처음엔 오른쪽을 향함
// 뱀 매 초 이동, 규칙을 따름
// 몸길이 늘려 머리를 다음 칸에 위치
// 이동한 칸에 사과가 있다면, 사과가 없어지고 꼬리안움직임
// 사과가 없다면, 몸길이를줄여 꼬리가 위치한 칸을 비운다, 몸길이는 변하지 않음
// 사과의 위치와 뱀의 이동경로가 주어질 때 게임이 몇초에 끝나는 지 계산하는 프로그램

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k, l;
int arr[101][101];                        // 맵을 담을 배열
vector<pair<int, char>> info;         // 방향 회전 정보

int dx[] = { 0, 1, 0, -1 };               // 처음에는 오른쪽을 보고 있으니, 동, 남, 서, 북
int dy[] = { 1, 0, -1, 0 };

int turn(int direction, char c) {
	if (c == 'L')
		direction = (direction == 0) ? 3 : direction - 1;
	else
		direction = (direction + 1) % 4;
	return direction;
}

int simulate() {
	int x = 1, y = 1;                       // 뱀의 머리 위치
	arr[x][y] = 2;                         // 뱀이 존재하는 위치는 2로 표시
	int direction = 0;                     // 처음에는 동쪽을 보고있음
	int time = 0;                           // 시작한 뒤에 지난 '초' 시간
	int index = 0;                         // 다음에 회전할 정보
	queue<pair<int, int>> q;         // 뱀이 차지하고 있는 위치 정보(꼬리가 앞쪽)
	q.push({ x,y });

	while (true) {
		int nx = x + dx[direction];
		int ny = y + dy[direction];
		if (1 <= nx && nx <= n && 1 <= y && ny <= n && arr[nx][ny] != 2) {          // 맵 범위 안에 있고 ,뱀의 몸통이 없는위치라면
			if (arr[nx][ny] == 0) {                                                                   // 사과가 없다면 이동 후에 꼬리 제거
				arr[nx][ny] = 2;
				q.push({ nx,ny });
				int px = q.front().first;
				int py = q.front().second;
				q.pop();
				arr[px][py] = 0;
			}
			if (arr[nx][ny] == 1) {                                                                  // 사과가 있다면 이동 후에 꼬리 그대로 두기
				arr[nx][ny] = 2;
				q.push({ nx,ny });
			}
		}
		else {                                                                                            // 벽이나 뱀의 몸통 과 부딫혔다면
			time += 1;
			break;
		}
		x = nx;                                                                                           // 다음 위치로 머리를 이동
		y = ny;
		time += 1;
		if (index < 1 && time == info[index].first) {                                          // 회전할 시간인 경우 회전
			direction = turn(direction, info[index].second);
			index += 1;
		}
	}
	return time;
}

int main(void) {
	cin >> n >> k;

	for (int i = 0; i < k; i++) {                      // 맵 정보 (사과가 있는 곳은 1로 표시)
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}

	cin >> l;                                            // 방향 회전 정보 입력
	for (int i = 0; i < l; i++) {
		int x;
		char c;
		cin >> x >> c;
		info.push_back({ x,c });
	}

	cout << simulate() << '\n';                // 시뮬레이션 출력
}