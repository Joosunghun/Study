// ���� 1152�� �ܾ��� ����
// ���� ��ҹ��ڿ� �������� �̷���� ���ڿ��� �־�����.
// �� ���ڿ��� �־��� �ܾ��� ������ ���ϴ� ���α׷�
// �� �ܾ ���� �� �����ϸ� ������ Ƚ����ŭ ��� ��

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s;
	int cnt = 1;

	getline(cin, s);             // ���⸦ ������ ���ڿ��� ���� ���� cin�� �ƴ� getline���� �޾ƿ´�.

	for (int i = 0; i < s.size(); i++) {       // ���� �ϳ��� +1
		if (s[i] == ' ')
			cnt++;
	}

	if (s[0] == ' ')             // ù���� ����� ������ -1
		cnt--;
	if (s[s.size() - 1] == ' ')       // ������ �ٿ� ���Ⱑ ������ -1
		cnt--;

	cout << cnt  << '\n';
}