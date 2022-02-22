// 문제 1976번 여행 가자
// 도시가 N개 있고 임의의 두 도시 사이에 길이 있을 수도, 없을 수도 있다.
// 여행 일정이 주어졌을 때, 이 여행경로가 가능한 것인지 알아보는 프로그램
// 같은 도시를 여러번 방문하는 것 가능


#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 200 + 1;

int n, m;
int arr[MAX];

int findParent(int x) {          // 부모를 찾는 연산
	if (arr[x] < 0)
		return x;

	int parent = findParent(arr[x]);
	arr[x] = parent;
	return parent;
}

void unionParent(int a, int b) {           // 집합의 크기가 더 큰쪽으로 합치는 연산
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

	memset(arr, -1, sizeof(arr));               // 모든 원소의 부모가 자기자신으로 초기화

	for (int i = 1; i <= n; i++) {                    // 인접한 도시들끼리 합치기
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

	for (int i = 0; i < m; i++) {                // 주어진 도시들이 모두 같은 집합에 있는지 확인
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

