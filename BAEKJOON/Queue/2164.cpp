// ���� 2164 ī��2
// 1���� N������ ī��
// ī�尡 ���� ���������� ���� ���� �ݺ�
// ���� ���� ī�带 ������. �״��� ���� ���� ī�带 ���� �Ʒ��� �ű�� �ݺ�
// N�� �־����� ��, ���� ���������� ���� �Ǵ� ī�带 ���ϴ� ���α׷�

#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (q.size() > 1) {
		q.pop();

		q.push(q.front());
		q.pop();
	}

	cout << q.front() << '\n';

}