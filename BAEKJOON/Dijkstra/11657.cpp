// 문제 11657번 타임머신
// N개의 도시, 한 도시에서 출발하여 다른 도시에 도착하는 버스 M개
// A는 시작도시, B는 도착도시, C는 버스를 타고 이동하는데 걸리는 시간
// C는 양수가 아닌 경우가 있고, C = 0은 순간이동, C < 0은 타임머신으로 시간을 되돌아가는 경우
// 1번 도시에서 출발해서 나머지 도시로 가는 가장 빠른 시간을 구하는 프로그램

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