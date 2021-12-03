// ���� 9012 ��ȣ
// ù��°�ٿ� T���� �׽�Ʈ ������
// ��ȣ�� VPS�� YES, VPS�� �ƴϸ� NO�� ����ϴ� �Լ�

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool check(string s) {
	stack<char> str;          // char Ÿ���� �޴� stack ����

	for (int i = 0; i < s.size(); i++) {        // ���ڿ� ���̸�ŭ �ݺ�
		if (s[i] == '(') {                          // ���ڰ� ���� ��ȣ��
			str.push(s[i]);                       // ���ÿ� push
		}
		else {                                       // �ݴ� ��ȣ��
			if (!str.empty())                       // ������ ���� �ʾҴٸ�
				str.pop();                          // pop
			else
				return false;                        // ��������� false
		}
	}
	return str.empty();                            // �ݺ����� ������ ���ÿ� ��ȣ�� ���������� false
}

int main(void) {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		
		if (check(s))
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}