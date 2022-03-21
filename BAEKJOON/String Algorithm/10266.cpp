// 문제 10266번 시계 사진들
// n개의 동일한 길이와 목적을 가진 시계 바늘이 있는 시계 사진 두장
// 시계의 숫자들은 희미해져 각 시계 바늘들의 위치만 구분 할 수 있음
// 두 사진의 시계가 같은 시각을 나타낼 수 있는지 궁금해져 각 사진을 서로 다른 각도로 돌려보려고 한다.
// 두 사진에 대한 묘사가 주어질 떄, 두 사진의 시계가 같은 시각을 나타내는지 결정하는 프로그램
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

vector<int> Fail(string Pattern) {
    vector<int> Pi(Pattern.length());
    for (int i = 1, j = 0; i < Pattern.length(); i++) {
        while (j > 0 && Pattern[i] != Pattern[j]) j = Pi[j - 1];
        if (Pattern[i] == Pattern[j]) Pi[i] = ++j;
    }
    return Pi;
}

bool KMP(string Str, string Pattern) {
    vector<int> Pi = Fail(Pattern), Pos;
    for (int i = 0, j = 0; i < Str.length(); i++) {
        while (j > 0 && Str[i] != Pattern[j]) j = Pi[j - 1];
        if (Str[i] == Pattern[j]) {
            if (j == Pattern.length() - 1) return true;
            else j++;
        }
    }
    return false;
}

int main() {
    int N, Value;
    scanf("%d", &N);
    string A, B;
    for (int i = 0; i < 360000; i++) A += '0', B += '0';
    for (int i = 0; i < N; i++) {
        scanf("%d", &Value);
        A[Value] = '1';
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &Value);
        B[Value] = '1';
    }
    if (KMP(A + A, B)) printf("possible");
    else printf("impossible");
}