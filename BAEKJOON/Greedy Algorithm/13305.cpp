// 문제 13305번 주유소
// N개의 도시, 일직선 도로위, 제일 왼쪽 도시에서 제일 오른쪽 도시로 자동차를 이용하여 이동
// 처음 출발할 때 자동차에는 기름이 없음, 기름을 넣어야함, 기름양 무제한
// 1km마다 1리터 기름, 각 도시에는 하나의 주요, 도시마다 주유소의 리터당 가격은 다를 수 있다.
// 각 도시에 있는 주유소의 기름 가격과, 도시를 연결하는 도로 길이를 입력 받아 제일 왼쪽 도시에서 오른쪽 도시로 이동하는 최소 비용을 계산하는 프로그램 작성

#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 1000000000 // 10억

long long dist[100001];            // 도시간 거리
long long price[100001];          // 기름 가격
long long N, sum;
long long greedy;

int main()
{
	cin >> N;

	for (int i = 1; i <= N - 1; i++)      // 도시간 거리 받아오기
		cin >> dist[i];

	for (int i = 1; i <= N; i++)           // 주유소 가격 받아오기
		cin >> price[i];

	greedy = MAX;

	for (int i = 1; i <= N - 1; i++)
	{
		if (price[i] < greedy)         // 그리디 보다 가격이 작으면
			greedy = price[i];         // 그리디에 가격을 넣고
		sum += greedy * dist[i];    // 거리만큼 곱한 후 더해준다
	}

	cout << sum;

}