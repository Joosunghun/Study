// 문제 2263번 트리의 순회
// n개의 정점을 가진 이진 트리의 정점에 1부터 n까지의 번호가 중복 없이 매겨져 있다.
// 이와 같은 이진 트리의 인오더와 포스트오더가 주어졌을 때, 프리오더를 구하는 프로그램

#include <iostream>
#define MAX 100000
using namespace std;

int inorder[MAX];
int postorder[MAX];
int pos[MAX + 1];

void solve(int in_start, int in_end, int post_start, int post_end) {
	if (in_start > in_end || post_start > post_end)
		return;
	int root = postorder[post_end];       // postorder는 root를 우선적으로 출력

	cout << root << " ";
	int index = pos[root];
	int length = index - in_start;
	solve(in_start, index - 1, post_start, post_start + length - 1);       // inorder에서 root를 기준으로 left와 right로 나뉨
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
		pos[inorder[i]] = i;              // pos배열은 해당 값이 몇 번째에 위치하는지 0(1)만에 구함
	}

	solve(0, n - 1, 0, n - 1);
	return 0;
}

