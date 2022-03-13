// ���� 9370�� ��Ȯ�� ������
// �� ���� ����� ������ �ĺ��� �� �ϳ��� �������� �ִܰŸ��� �̵��Ѵ�.
// �� �� ���� ����� ���� �������� ���ϴ� ���α׷�

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

#define INF 2100000000

using namespace std;


int T;
int n, m, t, s, g, h, a, b, d, x;
int scent, crossroad1, crossroad2;
int result_1[50001], result_2[50001];
vector<int> ans;
vector<pair<int, int>> road[50001];

void dijkstra(int start, int* result) {
	queue<int> q;
	for (int i = 1; i <= n; i++)
		result[i] = INF;

	result[start] = 0;
	q.push(start);

	while (!q.empty()) {
		int node = q.front();
		int dist = result[node];
		q.pop();

		for (int i = 0; i < road[node].size(); i++) {
			int next_node = road[node][i].first;
			int next_dist = road[node][i].second;

			if (result[next_node] > dist + next_dist) {
				result[next_node] = dist + next_dist;
				q.push(next_node);
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	while (T--) {
		ans.clear();        // ����, ���ͽ�Ʈ�� �����, ������ �Ÿ����� �ʱ�ȭ
		memset(result_1, 0, sizeof(result_1));
		memset(result_2, 0, sizeof(result_2));

		for (int i = 0; i < 50001; i++)
			road[i].clear();

		cin >> n >> m >> t;      // ������, ����, ������ ��
		cin >> s >> g >> h;     // �����, �İ�1, �İ�2

		for (int i = 0; i < m; i++) {        // ������ ���� �Ÿ� �Է�
			cin >> a >> b >> d;

			road[a].push_back({ b,d });
			road[b].push_back({ a,d });

			if ((a == g && b == h) || (a == h && b == g))
				scent = d;
		}

		dijkstra(s, result_1);        // ��������� ���ͽ�Ʈ��

		if (result_1[g] > result_1[h]) {       // �İ����� Ž���� ���ο����� ���ͽ�Ʈ��
			crossroad1 = h;
			crossroad2 = g;
		}
		else {
			crossroad1 = g;
			crossroad2 = h;
		}

		dijkstra(crossroad2, result_2);

		for (int i = 0; i < t; i++) {       // ������ �ĺ� �˻�
			cin >> x;
			if (result_1[x] == result_1[crossroad1] + scent + result_2[x])        // �ִܰŸ�
				ans.push_back(x);
		}

		sort(ans.begin(), ans.end());

		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << '\n';

	}
}