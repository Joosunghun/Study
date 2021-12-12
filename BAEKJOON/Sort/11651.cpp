// ���� 11651�� ��ǥ �����ϱ�2
// 2���� ��� ���� �� N���� �־�����. ��ǥ�� y�� �����ϴ� ������, y��ǥ�� ������ x��ǥ�� �����ϴ� ������ �����Ѵ��� ����ϴ� ���α׷� �ۼ�

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<pair<int, int>> com;             // ��ǥ�� ��� ���� ����

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;                          // x���� y�� �Է�
		com.push_back({ y,x });           // y �� ũ������� �����ϱ� ���� y�� ���� ��´�
	}

	sort(com.begin(), com.end());       // ������������ ����

	for (int i = 0; i < n; i++) {
		cout << com[i].second << ' ' << com[i].first << '\n';           // second�� x�� first�� y�̹Ƿ� second ���� ��� �� first ���
	}
}