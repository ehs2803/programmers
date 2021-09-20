#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, pair<int, int> > > edges;

int parent[101];

// 특정 원소가 속한 집합을 찾기  
int find_parent(int x) {
    if (parent[x] != x) return find_parent(parent[x]);
    return x;
}

// 두 원소가 속한 집합을 합치기  
void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int solution(int n, vector<vector<int>> costs) {

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < costs.size(); i++) {
        edges.push_back({ costs[i][2],{costs[i][0],costs[i][1]} });
    }

    sort(edges.begin(), edges.end());

    int answer = 0;
    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        // 사이클이 발생하지 않는 경우에만 집합에 포함
        if (find_parent(a) != find_parent(b)) {
            union_parent(a, b);
            answer += cost;
        }
    }

    return answer;
}