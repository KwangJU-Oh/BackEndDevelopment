#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//���� 12865�� - ����� �賶
//0-1 Knapsack Problem using Dynamic Programming
int main() {
    int N, K, W, V;

    cin >> N >> K;
    cin.get();

    //(������ ����) �� (����) ���� 2���� �迭
    vector<vector<long long int>>dp(N + 1, vector<long long int>(K + 1, 0));
    vector<pair<int, int>>thing(N + 1); //������ (����,��ġ)�� ���� �迭

    for (int i = 1; i <= N; i++) {
        cin >> W >> V;
        cin.get();

        thing[i] = make_pair(W, V);//������ (����, ��ġ)�� ���ǹ迭�� ����
    }

    for (int n = 1; n <= N; n++) { //2���� dp�迭�� ��ȸ(������ ����)
        for (int w = 1; w <= K; w++) {//���԰� 1���� K���� �����ϸ鼭 dp�迭 ä��
            //������ȹ�� ��ȭ��
            if (thing[n].first > w) {//������ ���԰� ���� for���� ���Ժ��� ���ٸ�
                //���԰� ���繫�Ժ��� �����Ǹ� �ȵǹǷ� ���� ������ �ش� ���Կ� �ش��ϴ�
                //�ְ� ��ġ�� ���� dp�迭�� ����
                dp[n][w] = dp[n - 1][w];
            }
            else {//������ ���԰� ���� for���� ���Ժ��� ���ٸ�

                //���� ������ �ش� for���� ���Կ� �ش��ϴ� �ְ� ��ġ(���԰� ������ �ȵǵ� �׻� ����
                //������ �ش� for���� ���Կ� �ش��ϴ� �ְ� ��ġ�� ���ؾ��Ѵ�) 
                //VERSUS
                //���� ������ ���� for���� ���Կ��� ���� ������ ���Ը� �� ��
                //���� ������ ���Ը� �־��� ���� ��ġ
                //�� �� ū ���� ���� dp�迭�� ä���

                //dp[n-1][w-thing[n].first]+thing[n].second�� ���� ������ ���� for���� ���Կ���
                //���� ������ ���Ը� �� �� ���� ������ �־��� ���� ��ġ�̴�.
                dp[n][w] = max(dp[n - 1][w], dp[n - 1][w - thing[n].first] + thing[n].second);
            }
        }
    }

    cout << dp[N][K];

    return 0;
}