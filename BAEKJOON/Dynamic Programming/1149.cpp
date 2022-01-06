// ���� 1149�� RGB�Ÿ�
// N���� ��, 1������ N�� ���� ������� ����
// ���� ����, �ʷ�, �Ķ� �� �ϳ��� ������ ĥ�ؾ� ��
// ������ ���� ����, �ʷ�, �Ķ����� ĥ�ϴ� ����� �־����� ��, ��� ���� ĥ�ϴ� ����� �ּڰ��� ���϶�
// ���� : �� ���� ���� ���� �޶����

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	int house[1001][3];       // ���� ĥ���� �� ����� �ּڰ����� ���ϰ� �����ϱ� ���� �迭
	int cost[3];
	int result = 0;

	house[0][0] = 0;
	house[0][1] = 0;
	house[0][2] = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {                                             // house[i]�� �� ������ ĥ������ ���ؼ��� ���� ���� �ٸ� ���̾�� �Ѵ�.
		cin >> cost[0] >> cost[1] >> cost[2];
		house[i][0] = min(house[i - 1][1],house[i - 1][2]) + cost[0];        // i��° ���� ���������� ĥ�� ���� �ּ� ���
		house[i][1] = min(house[i - 1][0], house[i - 1][2]) + cost[1];       // �ʷϻ����� ĥ�� ���� �ּҺ��
		house[i][2] = min(house[i - 1][1], house[i - 1][0]) + cost[2];       // �Ķ������� ĥ�� ���� �ּҺ��
	}

	result = min(house[n][2], min(house[n][0], house[n][1]));         // ����� = n��° ���� ĥ���� �� �������� �ּڰ�
	cout << result << '\n';
}