// ���� 1157�� �ܾ� ����
// ���ĺ� ��ҹ��ڷ� �� �ܾ �־�����, �� �ܾ�� ���� ���� ���� ���ĺ��� �������� �˾Ƴ��� ���α׷�
// �빮�ڿ� �ҹ��ڴ� �������� ����

#include <iostream>
#include <string>
using namespace std;

int alpha[26], cnt = 0;
string input;
// �ƽ�Ű �ڵ� : �빮�� 65~90, �ҹ��� 97~122

int main(void) {

	cin >> input;

	for (int i = 0; i < input.size(); i++) {         // �󵵼� üũ
		if (input[i] < 97)           // �빮��
			alpha[input[i] - 65]++;
		else                           // �ҹ���
			alpha[input[i] - 97]++;
	}

	int max = 0, max_indx = 0;

	for (int i = 0; i < 26; i++) {
		if (max < alpha[i]) {
			max = alpha[i];
			max_indx = i;
		}
	}

	for (int i = 0; i < 26; i++) {            // ���� ���� ���� ���ĺ��� ���������� Ȯ��
		if (max == alpha[i])
			cnt++;
	}

	if (cnt > 1)             // ��������� ? ��� �ƴ϶�� �빮�ڷ� ���
		cout << '?' << '\n';
	else
		cout << (char)(max_indx + 65) << '\n';
}