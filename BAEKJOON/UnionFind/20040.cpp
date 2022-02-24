// 문제 20040번 사이클 게임
// 사이클 게임은 두 명의 플레이어가 차례대로 돌아가며 진행하는 게임, 선 플레이어가 홀수 번째 차례, 후 플레이어가 짝수 번째 차례를 진행
// 0부터 n-1까지 고유한 번호가 부여된 평면 사의 점 n개가 주어지며, 이 중 어느 세 점도 일직선 위에 놓이지 않음
// 매 차례마다 플레이어는 두 점을 선택해서 이를 연결하는 선분을 긋는데, 이전에 그린 선분을 다시 그을 수는 없지만 이미 그린 다른 선분과 교차는 가능
// 게임을 진행하다가 사이클을 완성하는 순간 게임이 종료
// 선분을 여러 개 그리다보면 사이클이 완성 여부를 판단하기가 어려워 이미 사이클이 완성되었음에도 불구하고 게임을 계속 진행하게 될 수 있다는 것이다.
// 이 문제를 해결하기 위해서 게임의 진행 상황이 주어지면 몇 번째 차례에서 사이클이 완성되었는지, 혹은 아직 게임이 진행 중인지를 판단하는 프로그램
// 입력으로 점의 개수 n과 m번째 차례까지의 게임 진행 상황이 주어지면 사이클이 완성되었는지를 판단하고, 완성되었다면 몇 번째 차례에서 처음으로 사이클이 완성된 것인지를 출력하는 프로그램

#include <iostream>
using namespace std;

int n, m;
int parent[500000];
int ans;

int findParent(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = findParent(parent[x]);
}

bool unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	 
	if (a == b)           // 부모노드가 같으면 사이클이 생김
		return true;
	else {
		parent[a] = b;
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		if (unionParent(a, b)) {
			ans = i;
			break;
		}
	}
	if (ans == 0)
		cout << 0 << '\n';
	else
		cout << ans << '\n';
}