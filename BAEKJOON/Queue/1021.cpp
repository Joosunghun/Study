// ���� 1021�� ȸ���ϴ� ť
// N���� ���Ҹ� �����ϰ� �ִ� ����� ��ȯ ť
// ť���� �� ���� ���Ҹ� �̾Ƴ�
// 3���� ���� ����, 1. ù ��° ���� �̾Ƴ�. 2. �������� ��ĭ �̵� 3. ���������� ��ĭ �̵�
// ť�� ó���� ���ԵǾ��ִ� �� N�� �־�����, �̾� ������ �ϴ� ������ ��ġ�� �־�����. 
// �� ���Ҹ� �־��� ������� �̾Ƴ��µ� ��� 2��, 3�� ������ �ּڰ��� ����ϴ� ���α׷�

#include <iostream>
#include <deque>
using namespace std;

int main(void) {
	int n,m;        // ť�� ũ��, ã�����ϴ� ����
	deque<int> dq;
	int cnt = 0;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {        // dq�� 1���� N���� ������� �ֱ�
		dq.push_back(i);
	}

	for (int i = 0; i < m; i++) {          // m�� ��ŭ ȸ��
		int x;
		cin >> x;
		int index;
		for (int i = 0; i < dq.size(); i++) {
			if (dq[i] == x) {
				index = i;            // �ε����� ã������ �ϴ� �� ����
				break;
			}
		}
		if (index < dq.size() - index) {          // �ε��� ���� deque ũ���� ���� ���� �Ʒ���
			while (true) {
				if (dq.front() == x) {                  // ã�� ���̶�� �� ���� �� pop
					dq.pop_front();
					break;
				}
				cnt++;                                     // �ƴ϶�� ī��Ʈ ������Ű��
				dq.push_back(dq.front());         // �� �տ� �� �� �ڿ� ����
				dq.pop_front();                        // �� �տ� �� pop
			}
		}
		else                                              // �ε��� ���� deque ũ���� ���� ���� ũ��
			while (true) {
				if (dq.front() == x) {                 // ã�� ���̶�� �� ���� �� pop
					dq.pop_front();
					break;
				}
				cnt++;                                    // �ƴ϶�� ī��Ʈ ������Ű��
				dq.push_front(dq.back());        // �� ���� �� �� �տ� ����
				dq.pop_back();                       // �� ���� �� pop
			}
	}
	cout << cnt << '\n';                           // ī��Ʈ ���
}