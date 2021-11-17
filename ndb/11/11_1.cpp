// 11_1 ���谡 ���
// N���� ���谡 ������ ����
// �������� x �� ���谡�� �ݵ�� x �� �̻����� ��Ƽ�� �ٷ�����
// N���� ���谡�� ���� ������ �־������� ������ ���� �� �ִ� �׷� ���� �ִ��� ���

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	vector<int> character;

	cin >> n;
	for (int i = 0; i < n; i++) {                               // ���谡�� ���� �޾ƿ���
		int x;
		cin >> x;
		character.push_back(x);
	}

	sort(character.begin(), character.end());       // �������� ���� ������ ����

	int result = 0;                                               // �� �׷��� ��
	int count = 0;                                               // ���� �׷쿡 ���Ե� ���谡 ��

	for (int i = 0; i < n; i++) {                                // �������� ���� �ͺ��� �ϳ��� Ȯ���ϸ�
		count += 1;                                              // ���� �׷쿡 ���谡 �Ѹ� �߰�
		if (count >= character[i]) {                        // �׷쳻 ���谡 ���� ������ ������ �̻��̸�
			result += 1;                                          // �� �׷�� �ϳ� �߰�
			count = 0;                                            // ���谡 �� �ʱ�ȭ
		}
	}
	cout << result << '\n';                                  // �� �׷� �� ���
}