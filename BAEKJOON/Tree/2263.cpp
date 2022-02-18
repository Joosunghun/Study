// ���� 2263�� Ʈ���� ��ȸ
// n���� ������ ���� ���� Ʈ���� ������ 1���� n������ ��ȣ�� �ߺ� ���� �Ű��� �ִ�.
// �̿� ���� ���� Ʈ���� �ο����� ����Ʈ������ �־����� ��, ���������� ���ϴ� ���α׷�

#include <iostream>
#define MAX 100000
using namespace std;

int inorder[MAX];
int postorder[MAX];
int pos[MAX + 1];

void solve(int in_start, int in_end, int post_start, int post_end) {
	if (in_start > in_end || post_start > post_end)
		return;
	int root = postorder[post_end];       // postorder�� root�� �켱������ ���

	cout << root << " ";
	int index = pos[root];
	int length = index - in_start;
	solve(in_start, index - 1, post_start, post_start + length - 1);       // inorder���� root�� �������� left�� right�� ����
	solve(index + 1, in_end, post_start + length, post_end - 1);
}

int main(void) {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> postorder[i];
	}

	for (int i = 0; i < n; i++) {
		pos[inorder[i]] = i;              // pos�迭�� �ش� ���� �� ��°�� ��ġ�ϴ��� 0(1)���� ����
	}

	solve(0, n - 1, 0, n - 1);
	return 0;
}

