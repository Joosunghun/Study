// ���� 2231�� ������
// � �ڿ��� N, �������� N�� N�� �̷�� �� �ڸ��� ��
// M�� �������� N�ΰ��, M�� N�� �����ڶ� ��
// �ڿ��� N�� �־����� ��, N�� ���� ���� �����ڸ� ���س��� ���α׷� �ۼ�

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n;
	cin >> n;

	int sum = 0;
	int part = 0;
	for (int i = 0; i < n; i++) {                    // n���� ���� ��� �ڿ����� ���ذ���
		sum = i;
		part = i;

		while (part) {                                // part ���� �ݺ�
			sum += part % 10;                      // �տ��ٰ� 10���� ���� �������� ����
			part /= 10;                                 // part�� 10�� ����
		}

		if (n == sum) {                               // while ���� ������ n�� sum�� ���ٸ�
			cout << i << '\n';                      // i ���
			return 0;
		}
	}
	cout << "0" << '\n';                           // ���� ���ٸ� 0 ���
}