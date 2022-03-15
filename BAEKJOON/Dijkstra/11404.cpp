// ���� 11404�� �÷��̵�
// n���� ���ð� �ִ�. �� ���ÿ��� ����Ͽ� �ٸ� ���ÿ� �����ϴ� m���� ������ �ִ�.
// ��� ������ �� (A, B)�� ���ؼ� ���� A���� B�� ���µ� �ʿ��� ����� �ּڰ��� ���ϴ� ���α׷�

#include <iostream>
#include <algorithm>

#define INF 987654321
#define ARR_SIZE 100+1

using namespace std;

int v, e;
int arr[ARR_SIZE][ARR_SIZE];
int from, to, weight;

void floyd() {
	for (int i = 1; i <= v; i++) {                     // i vertex�� ��ġ�� ���
		for (int j = 1; j <= v; j++) {                 // from vertex�� ��ġ�� ���
			for (int k = 1; k <= v; k++) {           // to vertex�� ��ġ�� ���
				if (arr[j][i] != INF && arr[i][k] != INF)
					arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
			}
		}
	}
}

int main() {
	cin >> v >> e;
	for (int i = 1; i <= v; i++) {                    // vertex table �ʱ�ȭ
		for (int j = 1; j <= v; j++) {                  
			arr[i][j] = INF;
		}
	}
	for (int i = 0; i < e; i++) {                     // from vertex���� to vertex�Է�, ����ġ �Է�
		cin >> from >> to >> weight;
		if (arr[from][to] > weight)
			arr[from][to] = weight;
	}

	floyd();
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j || arr[i][j] == INF)
				cout << 0 << " ";
			else
				cout << arr[i][j] << " ";

		}
		cout << '\n';
	}
	return 0;
}