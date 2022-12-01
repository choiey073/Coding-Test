#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);

    int n;
    cin >> n;
    vector <int> stone(n, 0), dy(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> stone[i];
    }

    dy[0] = stone[0];
    dy[1] = stone[1];

    for (int i = 2; i < n; i++) {
        dy[i] = min(dy[i - 2], dy[i - 1]) + stone[i];
    }
    cout << min(dy[n - 1], dy[n - 2]);

    return 0;
}