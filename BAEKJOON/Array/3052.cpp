// ���� 3052�� ������
// �� �ڿ��� A�� B�� ���� ��, A % B�� A�� B�� ���� �������̴�.
// �� 10���� �Է¹��� ��, �̸� 42�� ���� �������� ���Ѵ�. �� ���� ���� �ٸ� ���� �� �� �ִ��� ����ϴ� ���α׷�

#include <iostream>
using namespace std;

int main(void) {
	int num;
	int rm[42] = { 0 };
	int cnt = 0;

	for (int i = 0; i < 10; i++) {
		cin >> num;
		rm[num % 42]++;
	}

	for (int i = 0; i < 42; i++) {
		if (rm[i] != 0)
			cnt++;
	}

	cout << cnt << '\n';
}