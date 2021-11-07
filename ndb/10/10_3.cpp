// 10_3 ���� ���� ��ȹ
// N���� ���� M���� ��, ���� �����ϴ� ������, ���� ���⼺ x
// ������ 2���� ���� �Ϸ��� ��, �������� �� �ϳ��� ���� �־���ϰ�, ���� �ȿ� �ִ� �� �� ���̿� ��ΰ� �׻� �����ؾ� ��
// ��ġ�� ���� ��� ���ְ� ������ ���� ������ �ּҷ� �ϰ� ����
// ���� ���� N, ���� ���� M
// A, B, C -> A�� B�� �����ϴ� ���� ������
// ������ ���� �ּڰ� ���

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;                                                 // ���� ������ ���� ����
int parent[100001];                                  // �θ� ���̺� �ʱ�ȭ
vector<pair<int, pair<int, int>>> edge;        // ��� ������ ���� ����Ʈ
int result = 0;                                          // ���� ����� ���� ����

int findParent(int x) {                               // ��Ʈ ��尡 �ƴ϶��, ��Ʈ ��带 ã�� �� ���� ��� 
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int n, int m) {                 // �� ���Ұ� ���� ���� ��ġ��
	n = findParent(n);
	m = findParent(m);
	if (n < m) parent[m] = n;
	else parent[n] = m;
}

int main(void) {
	cin >> n >> m;                                   // ���� ������, ���� ����

	for (int i = 0; i < n; i++) {                      //  �θ� ���̺�󿡼�, �θ� �ڱ� �ڽ����� �ʱ�ȭ
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {                      // ��� �濡 ���� ���� �Է� �ޱ�
		int a, b, cost;
		cin >> a >> b >> cost;
		edge.push_back({ cost,{a,b} });      // ��� ������ �����ϱ� ���� Ʃ���� ù ��° ���Ҹ� ������� ����
	}

	sort(edge.begin(), edge.end());            // ��� ������ ����
	int last = 0;                                          // �ּ� ���� Ʈ���� �l���Ǵ� ���� �� ����� ���� ū ����

	for (int i = 0; i < edge.size(); i++) {         // ������ �ϳ��� Ȯ��
		int cost = edge[i].first;
		int n = edge[i].second.first;
		int m = edge[i].second.second;
		if (findParent(n) != findParent(m)) {     // ����Ŭ�� �߻����� ������ ���տ� ����
			unionParent(n, m);
			result += cost;
			last = cost;
		}
	}

	cout << result - last << endl;
}