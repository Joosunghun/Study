// ���� 10773 ����
// ù ���� �ٿ� ���� K
// K�� �ٿ� ������ 1���� �־����µ�, ������ 0�� ��� ���� �ֱٿ� �� ���� �����, �ƴ� ��� �ش� ���� ����.
// ��� ���� �޾� ���� �� �� ���� �� ���ϱ�

#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	int k;
	stack<int> num;         // ���ڸ� �����ϱ� ���� ����

	cin >> k;
	for (int i = 0; i < k; i++) {       // ���ڸ� �ϳ��� �Է¹����鼭
		int x;
		cin >> x;
		if (x == 0) {                     // x�� 0�̸� pop
			num.pop();
		}
		else                              // �׷��� �ʴٸ� push
			num.push(x);
	}

	int sum = 0;                       // �� ���� �����ϱ� ���� ����
	while (!num.empty()) {       // ������ �������� ���鼭
		sum += num.top();         // ���� ���� ���� �����ְ�
		num.pop();                   // pop
	}

	cout << sum << '\n';        // ��� ���
}

