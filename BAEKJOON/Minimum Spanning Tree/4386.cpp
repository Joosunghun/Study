// 문제 4386번 별자리 만들기
// 아무렇게나 널브러져 있는 n개의 별들을 이어서 별자리를 하나 만들 것이다.
// 조건 1. 별자리를 이루는 선은 서로 다른 두 별을 일직선으로 이은 형태
// 조건 2. 모든 별들은 별자리 위의 선을 통해 서로 직/간접적으로 이어져 있어야 함
// 별들이 2차원 평면 위에 놓여 있다. 선을 하나 이을 때 마다 두 별 사이의 거리만큼 비용이 든다고 할 때, 별자리를 만드는 최소 비용을 구하는 프로그램

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;

int n, m;
double u, v, x, y;
int parent[101];
double d, ans;
vector<pair<double, double>> star;
vector<tuple<double, int, int>> dist;

int find(int u) {
	if (parent[u] == u)
		return u;
	else
		return parent[u] = find(parent[u]);
}

bool union_node(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v)           // 부모 노드가 같으면 싸이클이 생기므로 건너 뜀
		return false;
	else {             // 부모 노드 지정
		parent[u] = v;
		return true;
	}
}

double Cal_dist(double x1, double y1, double x2, double y2) {
	double x_dist = pow(x1 - x2, 2);
	double y_dist = pow(y1 - y2, 2);

	return sqrt(x_dist + y_dist);
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	star.push_back({ 0,0 });          // 좌표 입력
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		star.push_back({ x,y });
	}

	for (int i = 1; i <= n-1; i++) {         // 거리 계산
		for (int j = i + 1; j <= n; j++) {
			double r = Cal_dist(star[i].first, star[i].second, star[j].first, star[j].second);
			dist.push_back({ r,i,j });
		}
	}

	sort(dist.begin(), dist.end());

	for (int i = 0; i < dist.size(); i++) {        // MST 계산
		x = get<1>(dist[i]);
		y = get<2>(dist[i]);
		d = get<0>(dist[i]);
		if (union_node(x, y))
			ans += d;
	}

	printf("%.2f", ans);

}