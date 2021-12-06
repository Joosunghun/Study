// 문제 1018 체스판 다시 칠하기
// M x N 크기의 보드
// 거기서 8 x 8 크기의 체스판으로 잘라낸 후 흰색 검은색이 반복되어 나타나도록 다시색칠
// 다시 색칠하는 사각형의 최소 개수를 구하는 프로그램

#include <iostream>
using namespace std;

char arr[51][51];                                        // 임의의 보드를 담기 위한 배열
char white_arr[8][8] = {                              // 흰 색이 먼저 나오는 경우
	'W', 'B','W', 'B','W', 'B','W', 'B',
	'B','W', 'B','W', 'B','W', 'B', 'W',
	'W', 'B','W', 'B','W', 'B','W', 'B',
	'B','W', 'B','W', 'B','W', 'B', 'W',
	'W', 'B','W', 'B','W', 'B','W', 'B',
	'B','W', 'B','W', 'B','W', 'B', 'W',
	'W', 'B','W', 'B','W', 'B','W', 'B',
	'B','W', 'B','W', 'B','W', 'B', 'W',
};

char black_arr[8][8] = {                                // 검은색이 먼저나오는 경우
	'B','W', 'B','W', 'B','W', 'B', 'W',
	'W', 'B','W', 'B','W', 'B','W', 'B',
	'B','W', 'B','W', 'B','W', 'B', 'W',
	'W', 'B','W', 'B','W', 'B','W', 'B',
	'B','W', 'B','W', 'B','W', 'B', 'W',
	'W', 'B','W', 'B','W', 'B','W', 'B',
	'B','W', 'B','W', 'B','W', 'B', 'W',
	'W', 'B','W', 'B','W', 'B','W', 'B',
};

int white_first(int x, int y) {                              // 흰색이 먼저 나온 오는 경우 전체를 비교해서 
	int result = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[x + i][y + j] != white_arr[i][j])     // 결과가 다른 값만 큼 reuslt 값 증가
				result++;
		}
	}
	return result;
}

int black_first(int x, int y) {                               // 흰색과 동일하게 검은색도 같은 처리
	int result = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[x + i][y + j] != black_arr[i][j])
				result++;
		}
	}
	return result;
}

int main(void) {
	int n, m;
	int result = 64;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {                  // 이차원 배열 받아오기
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int t_white, t_black;
	for (int i = 0; i <= n - 8; i++) {            // 모든 8 * 8 크기로 잘라낸 체스판에 대해 다시 칠해야 하는 최소의 수를 계산한다.
		for (int j = 0; j <= m - 8; j++) {
			t_white = white_first(i, j);
			t_black = black_first(i, j);
			if (t_white < t_black) {              // 흰색으로 시작하는 경우와 검은색으로 시작하는 경우 모두 고려
				result = (t_white < result) ? t_white : result;
			}
			else
				result = (t_black < result) ? t_black : result;
		}
	}
	cout << result;
}