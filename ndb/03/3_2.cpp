<<<<<<< HEAD
// 3_2 큰 수의 법칙
// N개 자연수, M번 더하는데 K 만큼만 연속해서 더해질 수 있음
=======
// 3_1 �겙 �닔�쓽 踰뺤튃
// N媛� �옄�뿰�닔, M踰� �뜑�븯�뒗�뜲 K 留뚰겮留� �뿰�냽�빐�꽌 �뜑�빐吏� �닔 �엳�쓬
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
	for (i = 0; i < n; i++) {                                // n 개의 수를 arr에 넣기
=======
	for (i = 0; i < n; i++) {                                // n 媛쒖쓽 �닔瑜� arr�뿉 �꽔湲�
>>>>>>> d91d49590df568eabc8f0a53fffddf02a5b06acf
		int x;
		cin >> x;
		arr.push_back(x);
	}

<<<<<<< HEAD
	sort(arr.begin(), arr.end());                      // 정렬
	int first = arr[n - 1];                                 // 가장 큰 수
	int second = arr[n - 2];                           // 두 번째로 큰수

	count = (m / (k + 1)) * k;                         // 가장 큰 수가 더해지는 횟수 계산
	count += m % (k + 1);

	result += count * first;                             // 가장 큰 수 더하기
	result += (m - count) * second;               // 두 번째로 큰 수 더하기
=======
	sort(arr.begin(), arr.end());                      // �젙�젹
	int first = arr[n - 1];                                 // 媛��옣 �겙 �닔
	int second = arr[n - 2];                           // �몢 踰덉㎏濡� �겙�닔

	count = (m / (k + 1)) * k;                         // 媛��옣 �겙 �닔媛� �뜑�빐吏��뒗 �슏�닔 怨꾩궛
	count += m % (k + 1);

	result += count * first;                             // 媛��옣 �겙 �닔 �뜑�븯湲�
	result += (m - count) * second;               // �몢 踰덉㎏濡� �겙 �닔 �뜑�븯湲�
>>>>>>> d91d49590df568eabc8f0a53fffddf02a5b06acf

	cout << result << endl;
	
}
