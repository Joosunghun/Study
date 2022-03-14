// ���� 11657�� Ÿ�Ӹӽ�
// N���� ����, �� ���ÿ��� ����Ͽ� �ٸ� ���ÿ� �����ϴ� ���� M��
// A�� ���۵���, B�� ��������, C�� ������ Ÿ�� �̵��ϴµ� �ɸ��� �ð�
// C�� ����� �ƴ� ��찡 �ְ�, C = 0�� �����̵�, C < 0�� Ÿ�Ӹӽ����� �ð��� �ǵ��ư��� ���
// 1�� ���ÿ��� ����ؼ� ������ ���÷� ���� ���� ���� �ð��� ���ϴ� ���α׷�

#include <iostream>
#include <vector>

#define INF 2100000000

using namespace std;

int n, m;
int A, B, C;
int a, b;
long long dist[501];
bool cycle;
vector<pair<int, int>> v[501];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> A >> B >> C;
		v[A].push_back({ B,C });
	}

	for (int i = 1; i <= n; i++)
		dist[i] = INF;

	dist[1] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < v[j].size(); k++) {
				int next = v[j][k].first;
				int d = v[j][k].second;

				if (dist[j] != INF && dist[next] > dist[j] + d) {
					dist[next] = dist[j] + d;
					if (i == n)
						cycle = true;
				}
			}
		}
	}
	if (cycle)
		cout << -1 << '\n';
	else {
	for (int i = 2; i <= n; i++)
		cout << (dist[i] != INF ? dist[i] : -1) << '\n';
	}
}