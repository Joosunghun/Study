// ���� 1316�� �׷� �ܾ� üĿ
// �׷� �ܾ�� �ܾ �����ϴ� ��� ���ڿ� ���ؼ�, �� ���ڰ� �����ؼ� ��Ÿ���� ��츸�� ���Ѵ�.
// �ܾ� N���� �Է¹޾� �׷� �ܾ��� ������ ����ϴ� ���α׷�

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	int cnt = 0;
	string s;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int size = s.length();
		bool flag = true;

		for (int j = 0; j < size; j++) {
			for (int k = 0; k < j; k++) {
				if (s[j] != s[j - 1] && s[j] == s[k]) {
					flag = false;
					break;
				}
			}
		}
		if (flag)
			cnt++;
	}
	cout << cnt;

	return 0;

}