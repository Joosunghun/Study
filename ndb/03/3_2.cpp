<<<<<<< HEAD
// 3_2 ū ���� ��Ģ
// N�� �ڿ���, M�� ���ϴµ� K ��ŭ�� �����ؼ� ������ �� ����
=======
// 3_1 큰 수의 법칙
// N개 자연수, M번 더하는데 K 만큼만 연속해서 더해질 수 있음
>>>>>>> d91d49590df568eabc8f0a53fffddf02a5b06acf

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int i, n, m, k;
	vector<int> arr;
	int result = 0;
	int count = 0;
	cin >> n >> m >> k;

<<<<<<< HEAD
	for (i = 0; i < n; i++) {                                // n ���� ���� arr�� �ֱ�
=======
	for (i = 0; i < n; i++) {                                // n 개의 수를 arr에 넣기
>>>>>>> d91d49590df568eabc8f0a53fffddf02a5b06acf
		int x;
		cin >> x;
		arr.push_back(x);
	}

<<<<<<< HEAD
	sort(arr.begin(), arr.end());                      // ����
	int first = arr[n - 1];                                 // ���� ū ��
	int second = arr[n - 2];                           // �� ��°�� ū��

	count = (m / (k + 1)) * k;                         // ���� ū ���� �������� Ƚ�� ���
	count += m % (k + 1);

	result += count * first;                             // ���� ū �� ���ϱ�
	result += (m - count) * second;               // �� ��°�� ū �� ���ϱ�
=======
	sort(arr.begin(), arr.end());                      // 정렬
	int first = arr[n - 1];                                 // 가장 큰 수
	int second = arr[n - 2];                           // 두 번째로 큰수

	count = (m / (k + 1)) * k;                         // 가장 큰 수가 더해지는 횟수 계산
	count += m % (k + 1);

	result += count * first;                             // 가장 큰 수 더하기
	result += (m - count) * second;               // 두 번째로 큰 수 더하기
>>>>>>> d91d49590df568eabc8f0a53fffddf02a5b06acf

	cout << result << endl;
	
}
