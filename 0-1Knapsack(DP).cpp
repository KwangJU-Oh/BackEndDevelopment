#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//백준 12865번 - 평범한 배낭
//0-1 Knapsack Problem using Dynamic Programming
int main() {
    int N, K, W, V;

    cin >> N >> K;
    cin.get();

    //(물건의 개수) 행 (무게) 열의 2차원 배열
    vector<vector<long long int>>dp(N + 1, vector<long long int>(K + 1, 0));
    vector<pair<int, int>>thing(N + 1); //물건의 (무게,가치)를 담을 배열

    for (int i = 1; i <= N; i++) {
        cin >> W >> V;
        cin.get();

        thing[i] = make_pair(W, V);//물건의 (무게, 가치)를 물건배열에 저장
    }

    for (int n = 1; n <= N; n++) { //2차원 dp배열을 순회(물건의 개수)
        for (int w = 1; w <= K; w++) {//무게가 1부터 K까지 증가하면서 dp배열 채움
            //동적계획법 점화식
            if (thing[n].first > w) {//물건의 무게가 현재 for문의 무게보다 높다면
                //무게가 현재무게보다 오버되면 안되므로 이전 물건의 해당 무게에 해당하는
                //최고 가치를 현재 dp배열에 저장
                dp[n][w] = dp[n - 1][w];
            }
            else {//물건의 무게가 현재 for문의 무게보다 높다면

                //이전 물건의 해당 for문의 무게에 해당하는 최고 가치(무게가 오버가 안되도 항상 이전
                //물건의 해당 for문의 무게에 해당하는 최고 가치를 비교해야한다) 
                //VERSUS
                //이전 물건의 현재 for문의 무게에서 현재 물건의 무게를 뺀 후
                //현재 물건의 무게를 넣었을 때의 가치
                //둘 중 큰 값을 현재 dp배열에 채운다

                //dp[n-1][w-thing[n].first]+thing[n].second는 이전 물건의 현재 for문의 무게에서
                //현재 물건의 무게를 뺀 후 현재 물건을 넣었을 때의 가치이다.
                dp[n][w] = max(dp[n - 1][w], dp[n - 1][w - thing[n].first] + thing[n].second);
            }
        }
    }

    cout << dp[N][K];

    return 0;
}