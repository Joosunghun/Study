// 문제 5639번 이진 검색 트리
// 이진 검색 트리를 전위 순회한 결과가 주어졌을 때, 이 트리를 후위 순회한 결과를 구하는 프로그램

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
