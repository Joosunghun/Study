// ���� 2577�� ������ ����
// �� ���� �ڿ��� A, B, C�� �־��� ��, A x B x C�� ����� ����� 0���� 9���� ������ ���ڰ� �� ���� �������� ���ϴ� ���α׷�

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int a, b, c;
	int arr[10] = { 0 };

	cin >> a >> b >> c;

	int result = a * b * c;

	while (result != 0) {                 // 1�� �ڸ��� �޾ƿ���
		arr[result % 10] += 1;
		result /= 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << '\n';
	}
}
