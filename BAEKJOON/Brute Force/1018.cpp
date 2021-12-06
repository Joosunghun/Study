// ���� 1018 ü���� �ٽ� ĥ�ϱ�
// M x N ũ���� ����
// �ű⼭ 8 x 8 ũ���� ü�������� �߶� �� ��� �������� �ݺ��Ǿ� ��Ÿ������ �ٽû�ĥ
// �ٽ� ��ĥ�ϴ� �簢���� �ּ� ������ ���ϴ� ���α׷�

#include <iostream>
using namespace std;

char arr[51][51];                                        // ������ ���带 ��� ���� �迭
char white_arr[8][8] = {                              // �� ���� ���� ������ ���
	'W', 'B','W', 'B','W', 'B','W', 'B',
	'B','W', 'B','W', 'B','W', 'B', 'W',
	'W', 'B','W', 'B','W', 'B','W', 'B',
	'B','W', 'B','W', 'B','W', 'B', 'W',
	'W', 'B','W', 'B','W', 'B','W', 'B',
	'B','W', 'B','W', 'B','W', 'B', 'W',
	'W', 'B','W', 'B','W', 'B','W', 'B',
	'B','W', 'B','W', 'B','W', 'B', 'W',
};

char black_arr[8][8] = {                                // �������� ���������� ���
	'B','W', 'B','W', 'B','W', 'B', 'W',
	'W', 'B','W', 'B','W', 'B','W', 'B',
	'B','W', 'B','W', 'B','W', 'B', 'W',
	'W', 'B','W', 'B','W', 'B','W', 'B',
	'B','W', 'B','W', 'B','W', 'B', 'W',
	'W', 'B','W', 'B','W', 'B','W', 'B',
	'B','W', 'B','W', 'B','W', 'B', 'W',
	'W', 'B','W', 'B','W', 'B','W', 'B',
};

int white_first(int x, int y) {                              // ����� ���� ���� ���� ��� ��ü�� ���ؼ� 
	int result = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[x + i][y + j] != white_arr[i][j])     // ����� �ٸ� ���� ŭ reuslt �� ����
				result++;
		}
	}
	return result;
}

int black_first(int x, int y) {                               // ����� �����ϰ� �������� ���� ó��
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
	for (int i = 0; i < n; i++) {                  // ������ �迭 �޾ƿ���
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int t_white, t_black;
	for (int i = 0; i <= n - 8; i++) {            // ��� 8 * 8 ũ��� �߶� ü���ǿ� ���� �ٽ� ĥ�ؾ� �ϴ� �ּ��� ���� ����Ѵ�.
		for (int j = 0; j <= m - 8; j++) {
			t_white = white_first(i, j);
			t_black = black_first(i, j);
			if (t_white < t_black) {              // ������� �����ϴ� ���� ���������� �����ϴ� ��� ��� ���
				result = (t_white < result) ? t_white : result;
			}
			else
				result = (t_black < result) ? t_black : result;
		}
	}
	cout << result;
}