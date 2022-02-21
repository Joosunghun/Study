// 문제 1717 집합의 표현
// 초기에 {0},{1},...{n}이 각각 n+1개의 집합을 이루고 있다. 
// 여기에 합집합 연산과, 두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산을 수행
// 집합을 표현하는 프로그램을 작성

#include <iostream>
#define MAX 1000001
using namespace std;

int n, m;
int parent[MAX];

int findParent(int x) {               // 루트노드 찾기
	if (x == parent[x])
		return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {             // 두 원소가 속한 집합 합치기
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
	for (int i = 1; i <= n; i++) {               // 부모 테이블에서 부모를 자기 자신으로 초기화
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {               // 연산을 하나씩 확인
		int oper, a, b;
		cin >> oper >> a >> b;
		if (oper == 0)                           // 0 이면 합치기
			unionParent(a, b);
		else if (oper == 1) {                  // 1일경우 같은 집합 여부 확인
			if (findParent(a) == findParent(b))
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
	}
}