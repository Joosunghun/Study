// 12_4 �ڹ���� ����
// ����ִ� �ڹ���, ������ ũ�Ⱑ 1x1, NxN ũ���� ���簢 ���� �����̰� Ư���� ����� ����� MxM ũ���� ���簢 ���� ����
// �ڹ��迡�� Ȩ�� �Ŀ� �ְ�, ���� ���� Ȩ�� ���Ⱑ �ִ�.
// ����� ȸ���� �̵��� �����ϸ� ������ ���� �κ��� �ڹ����� Ȩ �κп� �� �°Ը� ä��� �ڹ��谡 ������ �Ǵ� ����
// �ڹ��� ������ ��� �κп� �ִ� ������ Ȩ�� ����� ������ ���� ������, �ڹ��� ���� �������� ������ ����κа� �ڹ����� Ȩ �κ��� ��Ȯ�� ��ġ�ؾ� ��
// ������ ����� �ڹ����� ���Ⱑ ������ �ȵ�, �ڹ����� ��� Ȩ�� ä������ ��
// ���踦 ��Ÿ���� 2���� �迭 key�� �ڹ��踦 ��Ÿ���� 2���� �迭 lock�� �Ű������� �־��� ��, ����� �ڹ��踦 ���� ������ true, ������ false�� return �ϵ��� solution �Լ� ����

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> rotateMaxtrixBy90Degree(vector<vector<int>> a) {                 // 2���� ����Ʈ 90�� ȸ���ϱ�
	int n = a.size();                  // �� ���� ���
	int m = a[0].size();             // �� ���� ���
	vector<vector<int>> result(n, vector<int>(m));              // ��� ����Ʈ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			result[j][n - i - 1] = a[i][j];
		}
	}
	return result;
}

bool check(vector<vector<int>> newLock) {                      // �ڹ����� �߰� �κ��� ��� 1���� Ȯ��
	int lockLength = newLock.size() / 3;
	for (int i = lockLength; i < lockLength * 2; i++) {
		for (int j = lockLength; j < lockLength * 2; j++){
			if (newLock[i][j] != 1) {
				return false;
			}
		}
	}
}

	bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
		int n = lock.size();
		int m = key.size();
		vector<vector<int>> newLock(n * 3, vector<int>(n * 3));                     // �ڹ����� ũ�⸦ ������ 3��� ��ȯ

		for (int i = 0; i < n; i++) {                                    // ���ο� �ڹ����� �߾� �κп� ������ �ڹ��� �ֱ�
			for (int j = 0; j < n; j++) {
				newLock[i + n][j + n] = lock[i][j];
			}
		}

		for (int rotation = 0; rotation < 4; rotation++) {       // 4���� ���⿡ ���ؼ� Ȯ��
			key = rotateMaxtrixBy90Degree(key);              // ����ȸ��
			for (int x = 0; x < n * 2; x++) {
				for (int y = 0; y < n * 2; y++) {
					for (int i = 0; i < m; i++) {                      // �ڹ��迡 ���踦 �ֱ�
						for (int j = 0; j < m; j++) {
							newLock[x + i][y + j] += key[i][j];
						}
					}
					if (check(newLock))                           // ���ο� �ڹ��迡 ���谡 ��ȭ�� ��� �´��� �˻�
						return true;
					for (int i = 0; i < m; i++) {                      // �ڹ��� �ٽ� ����
						for (int j = 0; j < m; j++) {
							newLock[x + i][y + j] -= key[i][j];
						}
					}
				}
			}
		}
		return false;
	}