// ���� 1541 �Ҿ���� ��ȣ
// 0~9 , �׸��� +, - �� �ִ� �Ŀ��� ������ ��ȣ�� �� �� ���� ���� �ּҷ� ����� ���α׷�

#include <iostream>
#include <string>
using namespace std;

string s;
string temp = "";

int main(void) {
	int result = 0;

	cin >> s;

	bool minus = false;
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == '+' || s[i] == '-' || s[i] == '\0') {           // �������� ���
			if (minus)
				result -= stoi(temp);
			else
				result += stoi(temp);
			temp = " ";            // �ʱ�ȭ
			if (s[i] == '-')       // ��ȣ�� ���� ���Ŀ� ġ�� �ּҰ�
				minus = true;
			continue;	
		}
		temp += s[i];           // �ǿ������� ��� temp�� ������
	}
	cout << result << '\n';
}