// 문제 4195번 친구 네트워크
// 어떤 사이트의 친구 관계가 생긴 순서대로 주어졌을 때, 두 사람의 친구 네트워크에 몇 명이 있는지 구하는 프로그램

#include <iostream>
#include <map>
using namespace std;

int parent[200001];
int counter[200001];

int findParent(int x) {          // 부모노드를 찾는 함수
	if (x == parent[x])
		return x;
	return parent[x] = findParent(parent[x]);
}

int unionParent(int a, int b) {         // 두 집합을 합치는 함수
	a = findParent(a);
	b = findParent(b);
	if (a != b) {
		parent[b] = a;
		counter[a] += counter[b];
		counter[b] = 1;
	}
	return counter[a];
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int f;
		cin >> f;

		for (int j = 1; j <= 2*f; j++) {
			parent[j] = j;
			counter[j] = 1;
		}

		map<string, int> index;                // key값과 value 값이 pair를 이루고있는 map
		string a, b;
		int idx1, idx2;
		int num = 1;
		for (int j = 0; j < f; j++) {
			cin >> a >> b;
			if (index.count(a) == 0)             // a에 num을 통해 노드번호를 부여
				index[a] = num++;
			idx1 = index[a];                       // a에 해당하는 value를 idx1에 저장
			if (index.count(b) == 0)             // b에 num을 통해 노드번호를 부여
				index[b] = num++;
			idx2 = index[b];                      // b에 해당하는 value를 idx2에 저장
			cout << unionParent(idx1, idx2) << '\n';
		}
	}
	return 0;
}