// ���� 4386�� ���ڸ� �����
// �ƹ����Գ� �κ귯�� �ִ� n���� ������ �̾ ���ڸ��� �ϳ� ���� ���̴�.
// ���� 1. ���ڸ��� �̷�� ���� ���� �ٸ� �� ���� ���������� ���� ����
// ���� 2. ��� ������ ���ڸ� ���� ���� ���� ���� ��/���������� �̾��� �־�� ��
// ������ 2���� ��� ���� ���� �ִ�. ���� �ϳ� ���� �� ���� �� �� ������ �Ÿ���ŭ ����� ��ٰ� �� ��, ���ڸ��� ����� �ּ� ����� ���ϴ� ���α׷�

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

	if (u == v)           // �θ� ��尡 ������ ����Ŭ�� ����Ƿ� �ǳ� ��
		return false;
	else {             // �θ� ��� ����
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

	star.push_back({ 0,0 });          // ��ǥ �Է�
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		star.push_back({ x,y });
	}

	for (int i = 1; i <= n-1; i++) {         // �Ÿ� ���
		for (int j = i + 1; j <= n; j++) {
			double r = Cal_dist(star[i].first, star[i].second, star[j].first, star[j].second);
			dist.push_back({ r,i,j });
		}
	}

	sort(dist.begin(), dist.end());

	for (int i = 0; i < dist.size(); i++) {        // MST ���
		x = get<1>(dist[i]);
		y = get<2>(dist[i]);
		d = get<0>(dist[i]);
		if (union_node(x, y))
			ans += d;
	}

	printf("%.2f", ans);

}