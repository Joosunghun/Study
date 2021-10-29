// 7-3 떡볶이 떡 만들기
// 떡 개수 N. 떡의 길이 M
// 절단기로 떡을 자른 만큼 손님이 가져감 
// 손님이 M 요청한 만큼 가져가려면 그 때 절단기 높이

#include <iostream>;
#include <vector>;
#include <algorithm>;
using namespace std;

int main(void) {
	int n, m;
	vector<int> arr;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {                    // 떡의 개수 만큼 길이 넣기
		int x;
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());
	int start = 0;
	int end = arr[n-1];
	int result = 0;
	while (start <= end) {
		long long int total = 0;
		int mid = (start + end) / 2;           // 중간 값 ( 절단기 값)
		for (int i = 0; i < n; i++) {             // 잘랐을 때 떡의 양 계산하기
			if (arr[i] > mid)  total = total + arr[i] - mid;
		}
		if (total < m)                      // 토탈 값이 m 보다 작으면 왼쪽으로 한칸 이동
			end = mid - 1;
		else
			result = mid;                 // 최대한 적게 잘랐을 때 이므로 result 기록
			start = mid + 1;              // 토탈 값이 m 보다 크면 오른쪽으로 한칸 이동
	}
	cout << result;
}

// MAX 함수 만들어서 end  값에 저장하고 돌려보기