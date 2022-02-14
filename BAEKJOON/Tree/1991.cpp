// 문제 1991번 트리의 순회
// 이진 트리를 입력받아 전위 순회, 중위 순회, 후위 순회한 결과를 출력하는 프로그램

#include <iostream>
using namespace std;

int a[50][2];

void preorder(int n) {           // 전위 순회
	if (n == -1) 
		return;
	cout << (char)(n + 'A');
	preorder(a[n][0]);
	preorder(a[n][1]);
}

void inorder(int n) {              // 중위 순회
	if (n == -1)
		return;
	inorder(a[n][0]);
	cout << (char)(n + 'A');
	inorder(a[n][1]);
}

void postorder(int n) {              // 후위 순회
	if (n == -1)
		return;
	postorder(a[n][0]);
	postorder(a[n][1]);
	cout << (char)(n + 'A');
}

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char x, y, z;
		cin >> x >> y >> z;            // 알파벳 입력
		x = x - 'A';                     // 문자 -> 숫자 변환
		if (y == '.')                    // 입력이 . 이면 -1로 변환
			a[x][0] = -1;
		else
			a[x][0] = y - 'A';
		if (z == '.')
			a[x][1] = -1;
		else
			a[x][1] = z - 'A';
	}

	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	return 0;

}