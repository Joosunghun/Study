// ���� 4195�� ģ�� ��Ʈ��ũ
// � ����Ʈ�� ģ�� ���谡 ���� ������� �־����� ��, �� ����� ģ�� ��Ʈ��ũ�� �� ���� �ִ��� ���ϴ� ���α׷�

#include <iostream>
#include <map>
using namespace std;

int parent[200001];
int counter[200001];

int findParent(int x) {          // �θ��带 ã�� �Լ�
	if (x == parent[x])
		return x;
	return parent[x] = findParent(parent[x]);
}

int unionParent(int a, int b) {         // �� ������ ��ġ�� �Լ�
	a = findParent(a);
	b = findParent(b);
	if (a != b) {
		parent[b] = a;
		counter[a] += counter[b];
		counter[b] = 1;
	}
	return counter[a];
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int f;
		cin >> f;

		for (int j = 1; j <= 2*f; j++) {
			parent[j] = j;
			counter[j] = 1;
		}

		map<string, int> index;                // key���� value ���� pair�� �̷���ִ� map
		string a, b;
		int idx1, idx2;
		int num = 1;
		for (int j = 0; j < f; j++) {
			cin >> a >> b;
			if (index.count(a) == 0)             // a�� num�� ���� ����ȣ�� �ο�
				index[a] = num++;
			idx1 = index[a];                       // a�� �ش��ϴ� value�� idx1�� ����
			if (index.count(b) == 0)             // b�� num�� ���� ����ȣ�� �ο�
				index[b] = num++;
			idx2 = index[b];                      // b�� �ش��ϴ� value�� idx2�� ����
			cout << unionParent(idx1, idx2) << '\n';
		}
	}
	return 0;
}