// 4_2 왕실의 나이트
// 8 X 8 좌표 평면
// 나이트는 L자 의형태로만 이동가능, 좌표 평면 밖으로는 나갈 수 없음
// 2가지 경우로 이동, 수평으로 두 칸 이동 후 수직으로 한 칸 || 수직으로 두 칸 이동 후 수평으로 한 칸
// 특정한 위치에서 이동할 수 있는 경우의 수 구하기

#include <iostream>
using namespace std;

string inputData;

int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };                   // 나이트가 이동할 수 있는 방향 8방향
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

int main(void) {
	cin >> inputData;                                           // 나이트의 위치 입력
	int row = inputData[1] - '0';                            // 나이트의 행 위치 숫자로 변환
	int col = inputData[0] - 'a' + 1;                        // 나이트의 열 위치 숫자로 변환

	int result = 0;
	for (int i = 0; i < 8; i++) {
		int nextRow = row + dx[i];                          // 다음 위치 확인
		int nextCol = col + dy[i];

		if ((nextRow >= 1 && nextRow <= 8) && (nextCol >= 1 && nextCol <= 8))  // 해당 위치가 좌표 평면 안이라면 결과 증가
			result += 1;
	}
	cout << result << endl;
}