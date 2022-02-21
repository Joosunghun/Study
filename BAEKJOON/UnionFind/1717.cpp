// ���� 1717 ������ ǥ��
// �ʱ⿡ {0},{1},...{n}�� ���� n+1���� ������ �̷�� �ִ�. 
// ���⿡ ������ �����, �� ���Ұ� ���� ���տ� ���ԵǾ� �ִ����� Ȯ���ϴ� ������ ����
// ������ ǥ���ϴ� ���α׷��� �ۼ�

#include <iostream>
#define MAX 1000001
using namespace std;

int n, m;
int parent[MAX];

int findParent(int x) {               // ��Ʈ��� ã��
	if (x == parent[x])
		return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {             // �� ���Ұ� ���� ���� ��ġ��
	a = findParent(a);
	b = findParent(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {               // �θ� ���̺��� �θ� �ڱ� �ڽ����� �ʱ�ȭ
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {               // ������ �ϳ��� Ȯ��
		int oper, a, b;
		cin >> oper >> a >> b;
		if (oper == 0)                           // 0 �̸� ��ġ��
			unionParent(a, b);
		else if (oper == 1) {                  // 1�ϰ�� ���� ���� ���� Ȯ��
			if (findParent(a) == findParent(b))
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
	}
}