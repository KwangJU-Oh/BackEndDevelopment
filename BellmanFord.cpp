/*
����-���� �˰���
���� - ���ͽ�Ʈ�� �˰���� ����� ��������, ���� ����ġ�� ������ �� ���
     - �� �������� ��� ���������� �ִ� �Ÿ�
     - ���� ���� ����Ŭ�� �����Ѵٸ� ����� �� ����(-��������� ������ ���� �� �ֱ� ����)
     - �ð����⵵ : ���۳�带 ������ ������ ������ �� * ��� �������� ��, O(V * E)
 */
#include <iostream>
#include <vector>
using namespace std;
//BOJ 11657 - Ÿ�Ӹӽ�

#define INF 50000000000
vector<long long int>dist(501, INF); //����� ���� �迭
vector<pair<pair<int, int>, long long int>>edge; //�������� �迭

bool bellmanFord(int start, int n, int m) {
    dist[start] = 0;
    int curNode, nextNode;
    long long int weight;

    for (int i = 0; i < n; i++) { //������ �� ��ŭ �ݺ��� ����
        for (int j = 0; j < m; j++) { //��� ������ ���� ����
            curNode = edge[j].first.first;
            nextNode = edge[j].first.second;
            weight = edge[j].second;

            if (dist[nextNode] > dist[curNode] + weight && dist[curNode] != INF) {
                //dist[curNode] != INF -> visited NODE? �� ���� ����� �Ѵ�.
                //�ð����⵵ ����
                dist[nextNode] = dist[curNode] + weight;

                if (i == n - 1) { //������ ���� �����ϴٸ� ���� ���� ����Ŭ�� ����!
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

        edge.push_back(make_pair(make_pair(a - 1, b - 1), c)); //��� ������ Ȯ���ϹǷ� ������ �����ؾ���
    }

    if (bellmanFord(0, n, m) == false) { //���� ��ȯ ����Ŭ�� �����Ѵٸ�
        cout << -1;
    }
    else {
        for (int i = 1; i < n; i++) {
            if (dist[i] == INF) { //������ ����Ǿ����� �ʴٸ�
                cout << -1 << "\n";
            }
            else {
                cout << dist[i] << "\n";
            }
        }
    }

    return 0;
}













