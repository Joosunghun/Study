// ���� 4344�� ����� �Ѱ���
// ù° �ٿ� �׽�Ʈ ���̽��� ���� C
// ��° �ٺ��� �� ���̽����� �л� ��, N���� ����
// �� ���̽����� �� �پ� ����� �Ѵ� �л����� ������ �ݿø��Ͽ� �Ҽ� ��° �ڸ����� ���

#include <iostream>
using namespace std;

int main(void) {
	int c, n, num, avg;
	int score[1000] = { 0 };
	double result;
	cin >> c;

	for (int i = 0; i < c; i++) {
		avg = 0;
		num = 0;
		cin >> n;

		for (int j = 0; j < n; j++) {            // ����� ���ϱ� ���� ��ü �� ���ϱ�
			cin >> score[j];
			avg += score[j];
		}
		avg /= n;                                  // ��ü �տ� ��� ���� ���� ��� ���ϱ�
		
		for (int j = 0; j < n; j++) {             // ��պ��� ���� ����� �� ���ϱ�
			if (score[j] > avg)
				num++;
		}
		result = (double)num / n * 100;

		cout << fixed;             // fixed = �Ҽ����� �������� ǥ��
		cout.precision(3);        // �Ҽ��� 3�ڸ� ���� ǥ��
		cout << result << '%' << '\n';
	}
}