/*
벨만-포드 알고리즘
개념 - 다익스트라 알고리즘과 비슷한 원리지만, 음의 가중치가 존재할 때 사용
     - 한 정점에서 모든 정점까지의 최단 거리
     - 음수 간선 사이클이 존재한다면 사용할 수 없음(-상수값으로 무한히 줄일 수 있기 때문)
     - 시간복잡도 : 시작노드를 제외한 나머지 노드들의 수 * 모든 간선들의 수, O(V * E)
 */
#include <iostream>
#include <vector>
using namespace std;
//BOJ 11657 - 타임머신

#define INF 50000000000
vector<long long int>dist(501, INF); //결과를 담을 배열
vector<pair<pair<int, int>, long long int>>edge; //간선들의 배열

bool bellmanFord(int start, int n, int m) {
    dist[start] = 0;
    int curNode, nextNode;
    long long int weight;

    for (int i = 0; i < n; i++) { //정점의 수 만큼 반복문 진행
        for (int j = 0; j < m; j++) { //모든 간선에 대해 조사
            curNode = edge[j].first.first;
            nextNode = edge[j].first.second;
            weight = edge[j].second;

            if (dist[nextNode] > dist[curNode] + weight && dist[curNode] != INF) {
                //dist[curNode] != INF -> visited NODE? 와 같은 기능을 한다.
                //시간복잡도 절약
                dist[nextNode] = dist[curNode] + weight;

                if (i == n - 1) { //정점의 수와 동일하다면 음수 간선 사이클이 존재!
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, a, b;
    long long int c;

    cin >> n >> m;
    cin.get();

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        cin.get();

        edge.push_back(make_pair(make_pair(a - 1, b - 1), c)); //모든 간선을 확인하므로 간선을 저장해야함
    }

    if (bellmanFord(0, n, m) == false) { //음수 순환 사이클이 존재한다면
        cout << -1;
    }
    else {
        for (int i = 1; i < n; i++) {
            if (dist[i] == INF) { //정점이 연결되어있지 않다면
                cout << -1 << "\n";
            }
            else {
                cout << dist[i] << "\n";
            }
        }
    }

    return 0;
}













