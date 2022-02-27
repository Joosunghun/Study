// 문제 14888번 연산자 끼워넣기
// N개의 수로 이루어진 수열이 주어진다. 또, 수와 수 사이에 끼워넣을 수 있는 n-1개의 연산자가 주어진다. 연산자는 덧셈,뺄셈,곱셈,나눗셈으로만 이루어져 있다.
// 수와 수 사이에 연산자를 하나씩 넣어서, 수식을 하나 만들 수 있다. 이때, 주어진 수의 순서를 바꾸면 안된다.
// n개의 수와 n-1개의 연산자가 주어졌을 때, 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는  프로그램

#include <iostream>
using namespace std;

int n;
int a[12];
int b[4];
int max_num, min_num;
int chk[11];

void Calc() {
	int tmp = a[0];
	for (int i = 1; i < n; i++) {
		switch (chk[i]) {
		case 0: tmp += a[i]; break;
		case 1: tmp -= a[i]; break;
		case 2: tmp *= a[i]; break;
		case 3: tmp /= a[i]; break;
		}
	}
	if (tmp > max_num)
		max_num = tmp;
	if (tmp < min_num)
		min_num = tmp;
}

void dfs(int x) {
	if (x == n) {
		Calc();
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (b[i] == 0)
			continue;
		chk[x] = i;
		b[i]--;
		dfs(x + 1);
		b[i]++;
		chk[x] = 0;
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> b[i];
	}

	max_num = -0x7fffffff;
	min_num = 0x7fffffff;

	dfs(1);

	cout << max_num << '\n';
	cout << min_num << '\n';
}