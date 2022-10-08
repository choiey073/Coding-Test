#include <bits/stdc++.h>
using namespace std;

// 동적 계획법(DP)

struct Time{
    int st, et, ev;
    Time(int a, int b, int c){
        st = a;
        et = b;
        ev = c;
    }
    bool operator < (const Time &b) const{
        // operator 정렬
        return et<b.et; // 끝나는 시간 기준으로 오름차순 정렬
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
    int n, m, r, a, b, c, answer = INT_MIN;
    cin >> n >> m >> r;
    vector<Time> range;
    vector<int> dy(m+1, 0);
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        range.push_back(Time(a,b,c));   // 구조체 push
    }
    sort(range.begin(), range.end());   // 여기서 구간을 정렬
    
    for(int i=0; i<m;i++){
        dy[i]=range[i].ev;
        for(int j=i-1;j>=0;j--){
            if(range[j].et+r <= range[i].st && dy[j]+range[i].ev > dy[i]){
                dy[i]=dy[j]+range[i].ev;
            }
        }
        answer = max(answer, dy[i]);
    }
    
    cout << answer;

    return 0;
}
