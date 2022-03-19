//  ���� 4354�� ���ڿ� ����
// ���ĺ� �ҹ��ڷ� �̷���� �� ���ڿ� a�� b�� �־����� ��, a*b�� �� ���ڿ��� �̾���̴� ���� ����
// �̷��� �̾� ���̴�  ���� �������� �����Ѵٸ�, ���� �ƴ� ������ ������ ������ �� �ִ�.
// ���ڿ� s�� �־����� ��, � ���ڿ� a�� ���ؼ� s=a^n�� �����ϴ� ���� ū n�� ã�� ���α׷�

#include <iostream>
#include <cstring>
using namespace std;

int fail[1000000];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	int slen;

	while (1) {
		cin >> s;
		if (s == ".") break;
		slen = s.size();
		memset(fail, 0, sizeof(fail));

		for (int i = 1, j = 0; i < slen; ++i) {
			while (j && s[i] != s[j]) j = fail[j - 1];
			if (s[i] == s[j]) fail[i] = ++j;
		}

		if(slen % (slen- fail[slen-1]))
			cout << 1 << '\n';
		else
			cout << slen/(slen-fail[slen-1]) << '\n';
	}

	return 0;
}