#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);

    int n;
    cin >> n;

    vector <int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)     cin >> a[i];
    for (int i = 0; i < n; i++)     cin >> b[i];
    for (int i = 0; i < n; i++)     cin >> c[i];

    sort(a.begin(), a.end(), greater<int>());   // 내림차순 정렬
    sort(b.begin(), b.end(), greater<int>());   // 내림차순 정렬
    sort(c.rbegin(), c.rend());                 // 내림차순 정렬

    int p1, p2, p3;
    p1 = p2 = p3 = 0;

    while (p1 < n && p2 < n && p3 < n) {    // p1, p2, p3가 n이 되는 경우는 공통 원소를 발견하지 못한것.
        int maxN = max(a[p1], max(b[p2], c[p3]));

        if (maxN == a[p1] && maxN == b[p2] && maxN == c[p3]) {  // 최대 공통 원소를 찾았다면
            cout << maxN;
            return 0;
        }
        else {  // 같지 않다면 포인터 이동
            if (maxN == a[p1]) p1++;
            if (maxN == b[p2]) p2++;
            if (maxN == c[p3]) p3++;
        }
    }

    cout << -1;//공통 원소를 찾지 못한 경우
    return 0;
}