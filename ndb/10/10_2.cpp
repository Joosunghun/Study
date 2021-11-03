// 10_2 팀 결성
// 학생들에게 0번부터 N번까지 번호 부여
// 처음에는 모든 다른 팀, N+1개 팀 존재
// 팀 합치기 = 두 팀을 합치는 연산, 같은 팀 여부 확인 = 특정한 두 학생이 같은 팀에 속하는지 확인하는 연산
// M개의 연산을 수행하고 , 같은 팀 여부 확인 연산에 대한 결과 출력하는 프로그램 작성
// 팀 합치기 연산은 0 a b 형태로 주어지고 a번 학생과 b 번학생이 속한 팀을 합침
// 같은 팀 여부 확인은 1 a b 형태로 주어지고, a와 b가 같은 팀인지를 확인하는 연산
// a,b 는 N 이하 양의 정수
// 같은 팀 여부 확인 연산에 대하여 한줄에 하나씩 YES or NO 출력

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;                                         // 노드의 개수와 연산의 개수
int parent[10001];                            // 부모 테이블 초기화

int findParent(int x) {                       // 루트 노드를 찾을 때가지 재귀 호출
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {          // 두 원소가 속한 집합 합치기
	a = findParent(a);
	b = findParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {             // 부모 테이블에서 부모를 자기 자신으로 초기화
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {             // 연산을 하나씩 확인
		int oper, a, b;
		cin >> oper >> a >> b;
		if (oper == 0) {                       // 0일 경우 합치기 연산
			unionParent(a, b);
		}
		else if (oper == 1) {                // 1일 경우 같은 팀 여부 확인 연산
			if (findParent(a) == findParent(b)) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
}