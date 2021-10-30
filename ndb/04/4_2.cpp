// 4_2 �ս��� ����Ʈ
// 8 X 8 ��ǥ ���
// ����Ʈ�� L�� �����·θ� �̵�����, ��ǥ ��� �����δ� ���� �� ����
// 2���� ���� �̵�, �������� �� ĭ �̵� �� �������� �� ĭ || �������� �� ĭ �̵� �� �������� �� ĭ
// Ư���� ��ġ���� �̵��� �� �ִ� ����� �� ���ϱ�

#include <iostream>
using namespace std;

string inputData;

int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };                   // ����Ʈ�� �̵��� �� �ִ� ���� 8����
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

int main(void) {
	cin >> inputData;                                           // ����Ʈ�� ��ġ �Է�
	int row = inputData[1] - '0';                            // ����Ʈ�� �� ��ġ ���ڷ� ��ȯ
	int col = inputData[0] - 'a' + 1;                        // ����Ʈ�� �� ��ġ ���ڷ� ��ȯ

	int result = 0;
	for (int i = 0; i < 8; i++) {
		int nextRow = row + dx[i];                          // ���� ��ġ Ȯ��
		int nextCol = col + dy[i];

		if ((nextRow >= 1 && nextRow <= 8) && (nextCol >= 1 && nextCol <= 8))  // �ش� ��ġ�� ��ǥ ��� ���̶�� ��� ����
			result += 1;
	}
	cout << result << endl;
}