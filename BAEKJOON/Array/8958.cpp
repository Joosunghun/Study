// ���� 8958�� OX ����
// O�� �°� X�� Ʋ�� ��, ������ ���� ���, �� ������ ������ �� �������� ���ӵ� O�� ����
// OX ������ ����� �־����� ��, ������ ���ϴ� ���α׷�

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n;
	string s;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		int sum = 0, cnt = 0;
		for(int j = 0; j < s.length(); j++){
			if (s[j] == 'O')           // ������ ���߸� ī��Ʈ �Ѱ��� ����
				cnt++;
			else
				cnt = 0;
			sum += cnt;               // ���� ī��Ʈ�� ��� �����ֱ�
		}

		cout << sum << '\n';

	}

}