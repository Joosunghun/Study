// ���� 2675�� ���ڿ� �ݺ�
// ���ڿ� S�� �Է¹��� �Ŀ�, �� ���ڸ� R�� �ݺ��� �� ���ڿ� P�� ���� �� ����ϴ� ���α׷�

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int t, r;
	string s;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> r >> s;
		for (int j = 0; j < s.length(); j++) {          // ���ڿ��� ũ�⸸ŭ �����鼭 �� ���ڸ� R���� �����
			for (int k = 0; k < r; k++) {
				cout << s[j];
			}
		}
		cout << '\n';
	}
}