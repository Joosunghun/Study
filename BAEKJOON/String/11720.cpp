// ���� 11720�� ������ ��
// N���� ���ڰ� ���� ���� �����ִ�. �� ���ڸ� ��� ���ؼ� ����ϴ� ���α׷�

#include <iostream>
#include <string>
using namespace std;


int main(void) {
	int n;
	string s;
	int result = 0;

	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {       // ���ڿ��� ���ڷ� �޾ƿͼ� �� ���ϱ�
		int num;
		num = s[i] - '0';

		result += num;
	}

	cout << result << '\n';
}