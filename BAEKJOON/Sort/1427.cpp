// ���� 1427�� ��Ʈ�λ��̵�
// ���� �־����� �� ���� �� �ڸ����� ������������ �����ϱ�

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> num;

bool compare(int a, int b) {                                     // ������������ ����� ���� �Լ�
	return a > b;
}

int main(void) {
	cin >> n;
	while (n != 0) {                                                  // n�� 0�� �ƴ� ������ num�� ���ڸ��� �ְ� 10���� ������ ��
		int x;
		x = n % 10;
		num.push_back(x);
		n /= 10;
	}

	sort(num.begin(), num.end(),compare);                // ������������ ����
	 
	for (int i = 0; i < num.size(); i++) {                        // num�� �����ŭ ���ĵ� �� ���
		cout << num[i];
	}
}