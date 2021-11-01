// 4_3 게임개발
// 캐릭터가 있는 장소 1 X 1 크기의 정사각형으로 이루어진 N X M 크기의 직사각형
// 칸은 육지 or 바다, 캐릭터는 동서남북 중 한곳을 바라봄
// 맵의 각 칸은 (A, B)로 나타냄 A는 북쪽으로부터 떨어진 칸의 개수, B는 서쪽으로 부터 떨어진 칸의 개수
// 현재 위치에서 현재 방향을 기준으로 반시계 방향(왼쪽)부터 차례대로 갈 곳을 정함
// 캐릭터의 바로 왼쪽에 아직 가보지 않은 칸이 존재하면, 왼쪽으로 횐전한 다음 한칸 전진, 가본 칸이라면 왼쪽으로 회전만 한다
// 네 방향 모두 이미 가본 칸이나 바다로 된 경우, 바라보는 방향을 유지한채 한칸 뒤로 가서 1단계 수행, 뒤칸이 바다면 움직임을 멈춤
// 위 과정을 반복 수행 후 캐릭터의 움직임에 이상 있는지 테스트 후, 캐릭터가 방문한 칸의 수를 출력하는 프로그램 작성
// 0 = 북, 1 = 동, 2 = 남, 3 = 서
// 1 = 육지, 0= 바다

#include <iostream>
using namespace std;

int n, m, x, y, direction;
int d[50][50];                                     // 방문한 위치를 저장하기 위한 맵을 생성하여 0으로 초기화
int arr[50][50];                                   // 전체 맵 정보

int dx[] = { -1, 0, 1, 0 };                      // 북, 동, 남, 서 방향 정의
int dy[] = { 0, 1, 0, -1 };

void turn_left() {                                 // 왼쪽으로 회전
    direction -= 1;
    if (direction == -1) direction = 3;
}

int main(void) {
    cin >> n >> m;                                // N, M을 공백을 기준으로 구분하여 입력받기
    cin >> x >> y >> direction;               // 현재 캐릭터의 X 좌표, Y 좌표, 방향을 입력받기
    d[x][y] = 1;                                   // 현재 좌표 방문 처리

    for (int i = 0; i < n; i++) {                  // 전체 맵 정보를 입력 받기
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            arr[i][j] = x;
        }
    }

    int cnt = 1;
    int turn_time = 0;
    while (true) {
        turn_left();                                          // 왼쪽으로 회전
        int nx = x + dx[direction];
        int ny = y + dy[direction];
        if (d[nx][ny] == 0 && arr[nx][ny] == 0) {                           // 회전한 이후 정면에 가보지 않은 칸이 존재하는 경우 이동
            d[nx][ny] = 1;
            x = nx;
            y = ny;
            cnt += 1;
            turn_time = 0;
            continue;
        }
        
        else turn_time += 1;                                                        // 회전한 이후 정면에 가보지 않은 칸이 없거나 바다인 경우

        if (turn_time == 4) {                                                        // 네 방향 모두 갈 수 없는 경우
            nx = x - dx[direction]; 
            ny = y - dy[direction];
           
            if (arr[nx][ny] == 0) {                                               // 뒤로 갈 수 있다면 이동하기
                x = nx;
                y = ny;
            }
          
            else break;                                                              // 뒤가 바다로 막혀있는 경우
            turn_time = 0;
        }
    }

    cout << cnt << '\n';
}