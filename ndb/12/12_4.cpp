// 12_4 자물쇠와 열쇠
// 잠겨있는 자물쇠, 격자의 크기가 1x1, NxN 크기의 정사각 격자 형태이고 특이한 모양의 열쇠는 MxM 크기인 정사각 격자 형태
// 자물쇠에는 홈이 파여 있고, 열쇠 또한 홈과 돌기가 있다.
// 열쇠는 회전과 이동이 가능하며 열쇠의 돌기 부분을 자물소의 홈 부분에 딱 맞게만 채우면 자물쇠가 열리게 되는 구조
// 자물쇠 영역을 벗어난 부분에 있는 열쇠의 홈과 돌기는 영향을 주지 않지만, 자물쇠 영역 내에서는 열쇠의 돌기부분과 자물쇠의 홈 부분이 정확히 일치해야 함
// 열쇠의 돌기와 자물쇠의 돌기가 만나선 안됨, 자물쇠의 모든 홈이 채워져야 함
// 열쇠를 나타내는 2차원 배열 key와 자물쇠를 나타내는 2차원 배열 lock이 매개변수로 주어질 때, 열쇠로 자물쇠를 열수 있으면 true, 없으면 false를 return 하도록 solution 함수 구현

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> rotateMaxtrixBy90Degree(vector<vector<int>> a) {                 // 2차원 리스트 90도 회전하기
	int n = a.size();                  // 행 길이 계산
	int m = a[0].size();             // 열 길이 계산
	vector<vector<int>> result(n, vector<int>(m));              // 결과 리스트
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			result[j][n - i - 1] = a[i][j];
		}
	}
	return result;
}

bool check(vector<vector<int>> newLock) {                      // 자물쇠의 중간 부분이 모두 1인지 확인
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
		vector<vector<int>> newLock(n * 3, vector<int>(n * 3));                     // 자물쇠의 크기를 기존의 3배로 반환

		for (int i = 0; i < n; i++) {                                    // 새로운 자물소의 중앙 부분에 기존의 자물쇠 넣기
			for (int j = 0; j < n; j++) {
				newLock[i + n][j + n] = lock[i][j];
			}
		}

		for (int rotation = 0; rotation < 4; rotation++) {       // 4가지 방향에 대해서 확인
			key = rotateMaxtrixBy90Degree(key);              // 열쇠회전
			for (int x = 0; x < n * 2; x++) {
				for (int y = 0; y < n * 2; y++) {
					for (int i = 0; i < m; i++) {                      // 자물쇠에 열쇠를 넣기
						for (int j = 0; j < m; j++) {
							newLock[x + i][y + j] += key[i][j];
						}
					}
					if (check(newLock))                           // 새로운 자물쇠에 열쇠가 정화기 들어 맞는지 검사
						return true;
					for (int i = 0; i < m; i++) {                      // 자물쇠 다시 뺴기
						for (int j = 0; j < m; j++) {
							newLock[x + i][y + j] -= key[i][j];
						}
					}
				}
			}
		}
		return false;
	}