// ���� 11425�� ���ڿ�����
// �� N���� ���ڿ��� �̷����� ���� S�� �־�����.
// �Է����� �־��� M���� ���ڿ� �߿��� ���� S�� ���ԵǾ� �ִ� ���� �� ����� ���ϴ� ���α׷�

#include <iostream>
#include <map>
using namespace std;

int n, m, ans;
string s;
map<string, bool> str;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s;
		str[s] = true;
	}

	for (int i = 0; i < m; i++) {
		cin >> s;
		if (str[s])
			ans++;
	}

	cout << ans << '\n';
}