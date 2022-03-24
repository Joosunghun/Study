// 문제 11066번 파일 합치ㅣ기
// 소설을 여러장으로 나누어 쓰는데, 각 장은 다른 파일에 저장하곤 한다.
// 소설의 모든 장을 쓰고 나서는 각 장이 쓰여진 파일을 합쳐서 최종적으로 소설의 완성본이 들어잇는 한 개의 파일을 만든다.
// 이 과정에서 두 개의 파일을 합쳐서 하나의 임시파일을 만들고, 이 임시파일이나 원래의 파일을 계속 두 개씩 합쳐서 소설의 여러 장들이 연속되도록 파일을 합쳐나가고, 최종적으로는 하나의 파일로 합친다.
// 두 개의 파일을 합칠 떄 필요한 비용이 두 파일 크기의 합이라고 가정할 때, 최종적인 한 개의 파일을 완성하는데 필요한 비용의 총 합의 최솟값을 계산하는 프로그램

#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1000000000
using namespace std;

int t, k;
int sum[501], file[501], dp[501][501];

int main() {
	cin >> t;

	while (t--) {
		cin >> k;
		for (int i = 1; i <= k; i++) {
			cin >> file[i];
			sum[i] = sum[i - 1] + file[i];
		}

		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= k - i; j++) {
				dp[j][i + j] = INF;
				for (int k = j; k < i + j; k++) {
					dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + sum[i + j] - sum[j - 1]);
				}
			}
		}
		cout << dp[1][k] << '\n';
	}
}