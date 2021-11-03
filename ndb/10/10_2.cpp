// 10_2 �� �Ἲ
// �л��鿡�� 0������ N������ ��ȣ �ο�
// ó������ ��� �ٸ� ��, N+1�� �� ����
// �� ��ġ�� = �� ���� ��ġ�� ����, ���� �� ���� Ȯ�� = Ư���� �� �л��� ���� ���� ���ϴ��� Ȯ���ϴ� ����
// M���� ������ �����ϰ� , ���� �� ���� Ȯ�� ���꿡 ���� ��� ����ϴ� ���α׷� �ۼ�
// �� ��ġ�� ������ 0 a b ���·� �־����� a�� �л��� b ���л��� ���� ���� ��ħ
// ���� �� ���� Ȯ���� 1 a b ���·� �־�����, a�� b�� ���� �������� Ȯ���ϴ� ����
// a,b �� N ���� ���� ����
// ���� �� ���� Ȯ�� ���꿡 ���Ͽ� ���ٿ� �ϳ��� YES or NO ���

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;                                         // ����� ������ ������ ����
int parent[10001];                            // �θ� ���̺� �ʱ�ȭ

int findParent(int x) {                       // ��Ʈ ��带 ã�� ������ ��� ȣ��
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {          // �� ���Ұ� ���� ���� ��ġ��
	a = findParent(a);
	b = findParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {             // �θ� ���̺��� �θ� �ڱ� �ڽ����� �ʱ�ȭ
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {             // ������ �ϳ��� Ȯ��
		int oper, a, b;
		cin >> oper >> a >> b;
		if (oper == 0) {                       // 0�� ��� ��ġ�� ����
			unionParent(a, b);
		}
		else if (oper == 1) {                // 1�� ��� ���� �� ���� Ȯ�� ����
			if (findParent(a) == findParent(b)) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
}