#include <bits/stdc++.h>
using namespace std;
// 최소 스패닝 트리

//union and find 하기 위한 배열
int unf[1001];  

// 간선 정보
struct edge{
    int v1, v2;
    double dis;

    edge(int a, int b, double c) {
        v1 = a;
        v2 = b;
        dis = c;
    }
    bool operator < (const edge& e)const {
        return dis < e.dis; // 내림차순 정렬
    }
};

// union and find
// 한 집합으로 묶기
int Find(int v) {
    if (v == unf[v])   return v;
    else return unf[v] = Find(unf[v]);
}
void Union(int a, int b) {  // 같은 집합인지 확인
    a = Find(a);
    b = Find(b);
    if (a != b) unf[a] = b;
}

int main() {

    freopen("input.txt", "rt", stdin);

    int n, m;
    double res = 0;
    scanf("%d %d", &n, &m);

    vector <edge> ed;
    vector <double> x, y;

    for(int i =0;i<n;i++){
        int a, b;
        // 소수점을 control 할때는 scanf와 printf가 훨씬 정확함.
        scanf("%d %d", &a, &b);
        x.push_back(a);
        y.push_back(b);
        unf[i] = i; // 각 노드의 집합은 처음에는 자기의 집합
    }
    
    // 각각의 호텔을 연결하여 거리를 구하는 모든 경우의 수 : nC2
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dist = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            ed.push_back(edge(i, j, dist));
        }
    }

    // 이어진 노드의 정보 입력
    for (int i = 0; i < m; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        Union(v1 - 1, v2 - 1);  // 같은 집합으로 묶어줌
    }
    sort(ed.begin(), ed.end()); // 거리에 의한 오름차순 정렬

    for (int i = 0; i < ed.size(); i++) {

        // 간선의 개수만큼 보면서 호텔 두개가 한 집합인지 확인하기
        int fa = Find(ed[i].v1);
        int fb = Find(ed[i].v2);

        if (fa != fb) { // 두개의 호텔이 한 집합이 아니라면,
            res += ed[i].dis;   // 가장 잛은 도로를 선택.
            unf[fa] = fb;
        }
    }
    printf("%0.2f", res);

    return 0;
}