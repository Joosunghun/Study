// 문제 2018번 통계학
// 홀수개 N
// 산술평균 : N개의 수들의 합을 N으로 나눈 값
// 중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
// 최빈값 : N개의 수들 중 가장 많이 나타는 값
// 범위 : N개의 수들 중 최댓값과 최솟값의 차이

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
vector<int> arr;
int main() {
    int num, tmp, range, middle = 0, most_val, mean = 0;
    int most = -9999;
    int number[8001] = { 0, };
    bool not_first = false;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
        mean += tmp;
        number[tmp + 4000]++;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < 8001; i++)
    {
        if (number[i] == 0)
            continue;
        if (number[i] == most)
        {
            if (not_first)
            {
                most_val = i - 4000;
                not_first = false;
            }
        }
        if (number[i] > most)
        {
            most = number[i];
            most_val = i - 4000;
            not_first = true;
        }
    }
    middle = arr[arr.size() / 2];
    mean = round((float)mean / num);
    range = arr.back() - arr.front();
    cout << mean << '\n' << middle << '\n' << most_val << '\n' << range;
}