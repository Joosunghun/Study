// ���� 5639�� ���� �˻� Ʈ��
// ���� �˻� Ʈ���� ���� ��ȸ�� ����� �־����� ��, �� Ʈ���� ���� ��ȸ�� ����� ���ϴ� ���α׷�

#include <iostream>
using namespace std;

int tree[10000];

void postorder(int start, int end) {
	if (start >= end) 
		return;

	if (start == end - 1) {
		cout << tree[start] << '\n';
		return;
	}

	int idx = start + 1;
	while (idx < end) {
		if (tree[start] < tree[idx])
			break;
		idx++;
	}

	postorder(start + 1, idx);
	postorder(idx, end);
	cout << tree[start] << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int num;
	int inputidx = 0;
	while (cin >> num) {
		tree[inputidx++] = num;
	}

	postorder(0, inputidx);

	return 0;
}
