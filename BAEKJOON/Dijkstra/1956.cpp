// ���� 1956�� �
// V���� ������ E���� ���η� �����Ǿ� �ִ� ����, �Ϲ����� ����
// 1������ V������ ��ȣ�� �Ű�������
// ��� �ϱ� ���� ��θ� ã����, ������ ������ ���� ���� ���� ����Ŭ�� ã�� ���α׷�

#include <iostream>
#define MAX 401
using namespace std;

const int INF = 987654321;
int v, e, result = INF;
int arr[MAX][MAX];

int main(void) {
	cin >> v >> e;

	for (int i = 1; i <= v; i++) {            // �� ����
		for (int j = 1; j <= v; j++) 
			arr[i][j] = INF;
	}

	for (int i = 0; i < e; i++) {              // �� ����
		int x, y, z;
		cin >> x >> y >> z;
		arr[x][y] = z;
	}

	for (int k = 1; k <= v; k++) {         // �÷��̵� ���� �˰��� , k = ���İ��� ���
		for (int i = 1; i <= v; i++) {         // i = ��߳��
			for (int j = 1; j <= v; j++) {       // j = ���� ���
				if (arr[i][j] > arr[i][k] + arr[k][j])         // �� ª�� �� Ž��
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}

	for (int i = 1; i <= v; i++)                // �ٽ� ���������� ���ƿ� ���� ���� ª�� �� ����
		result = min(result, arr[i][i]);

	cout << ((result == INF) ? -1 : result);
}

