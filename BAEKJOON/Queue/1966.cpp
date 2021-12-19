// ���� 1966�� ������ ť
// ���ǿ� ���� �μ��ϴ� �����ͱ�
// 1. ���� ť�� ���� �տ� �ִ� ������ �߿䵵�� Ȯ���Ѵ�.
// 2. ������ ������ �� ���� �������� �߿䵵�� ���� ������ �ϳ��� ������, �� ������ �μ����� �ʰ� ť�� �� �ڿ� ���ġ, ���� ���ٸ� �μ�
// ù ��° �ٿ��� ������ ����, �� ��°�� �μ�Ǿ����� �ñ��� ������ ���� ť�� �� ��°�� �����ִ����� Ÿ������ ����, �� ������ 0��°
// �� ��° �ٿ��� N���� ������ �߿䵵�� ���ʴ�� �־�����.

#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	int count = 0;
	int test_case;      // ��ȸ �ݺ��� ����
	int n, m, ipt;        // ������ ����, �ʿ��� ������ ��ġ, �߿䵵
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		count = 0;
		cin >> n >> m;
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		for (int j = 0; j < n; j++) {
			cin >> ipt;
			q.push({ j,ipt });             // ť�� �ʿ��� ������ ��ġ��, �߿䵵 �ֱ�
			pq.push(ipt);                  // �켱���� ť�� �߿䵵 �ֱ�
		}
		while (!q.empty()) {
			int index = q.front().first;         // �ε��� ���� �ʿ��� ������ ��ġ
			int value = q.front().second;    // value���� �߿䵵
			q.pop();                            // ù���� ť�� ����
			if (pq.top() == value) {          // �켱���� ť�� top ���� �߿䵵�� ������
				pq.pop();                        // pop�� �� ī��Ʈ ����
				count++;
				if (index == m) {             // �ε����� ã�� ���̶�� 
					cout << count << '\n';      // ī��Ʈ ���
					break;
				}
			}
			else                                     // �켱���� ť�� top ���� �߿䵵�� �ٸ���
				q.push({ index,value });            // ť�� �ǵڿ� ����
		}
	}
}