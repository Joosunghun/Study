// ���� 1976�� ���� ����
// ���ð� N�� �ְ� ������ �� ���� ���̿� ���� ���� ����, ���� ���� �ִ�.
// ���� ������ �־����� ��, �� �����ΰ� ������ ������ �˾ƺ��� ���α׷�
// ���� ���ø� ������ �湮�ϴ� �� ����


#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 200 + 1;

int n, m;
int arr[MAX];

int findParent(int x) {          // �θ� ã�� ����
	if (arr[x] < 0)
		return x;

	int parent = findParent(arr[x]);
	arr[x] = parent;
	return parent;
}

void unionParent(int a, int b) {           // ������ ũ�Ⱑ �� ū������ ��ġ�� ����
	if (abs(a) >= abs(b)) {
		arr[a] += arr[b];
		arr[b] = a;
	}
	else {
		arr[b] += arr[a];
		arr[a] = b;
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	memset(arr, -1, sizeof(arr));               // ��� ������ �θ� �ڱ��ڽ����� �ʱ�ȭ

	for (int i = 1; i <= n; i++) {                    // ������ ���õ鳢�� ��ġ��
		for (int j = 1; j <= n; j++) {
			int connected;
			cin >> connected;

			if (connected) {
				int a = findParent(i);
				int b = findParent(j);
				if (a == b)
					continue;
				unionParent(a, b);
			}
		}
	}
	int root;
	bool possible = true;

	for (int i = 0; i < m; i++) {                // �־��� ���õ��� ��� ���� ���տ� �ִ��� Ȯ��
		int city;
		cin >> city;

		if (i == 0)
			root = findParent(city);
		else {
			if (root != findParent(city)) {
				possible = false;
				break;
			}
		}
	}

	if (possible)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
	return 0;
}

