// ���� 2597�� ��� ������
// ��� �Ʒ� ���������� ��� ����⿡ ��ġ�� ���������� ���� ����.
// ��ܿ��� ������ ������ ���� �ִµ� ����� ������ �� ��ܿ� ���� �ִ� ������ ��� ��
// ��Ģ : 1. �� ���� �� ��ܾ� �Ǵ� �� ��ܾ� ���� �� �ִ�. 2. ���ӵ� �� ����� ��� ��Ƽ��� �� �ȴ�. 3. ������ ���� ����� �ݵ�� ��ƾ� �Ѵ�.
// ��ܿ��� ���� �� �ִ� �� ������ �ִ��� ���ϴ� ���α׷�

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[301];
int dp[301];

int main(void) {

	cin >> n;
	for (auto i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];
	dp[1] = max(arr[1], arr[0] + arr[1]);
	dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
	for (auto i = 3; i < n; i++) {
		dp[i] += max(arr[i] + dp[i-2],arr[i]+arr[i-1]+dp[i-3]);
	}
	int result = 0;
	result = dp[n - 1];

	cout << result << '\n';

}