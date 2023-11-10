#include <iostream>
#include <vector>
using namespace std;

vector<int>col(16, 0);
int cnt = 0;

bool promising(int depth, int n) {
	int k = 1; //depth가 0이거나 1이면, 유망성 검사할 가치가 없음(반드시 되야 하니까)
	//가지치기를 하면 안됨.
	//또한, k는 열과 대각선에 있는 다른 퀸을 보기 위해 1부터 설정해야함!(행에 대한 변수)
	bool flag = true;

	while (k < depth && flag) {
		if (col[k] == col[depth] || abs(col[k] - col[depth]) == (depth - k)) {
		//같은 열에 퀸이 있다면 혹은 대각선에 퀸이 있다면
			flag = false;
		}
		k = k + 1;
	}

	return flag;
}

//가정 - 같은 row는 이미 배치할 수 없다고 가정하고 진행, 두 가지 유망성만 검사!!
void nQueen(int depth, int n) {  //먼저 다음 depth에 퀸을 배치하고 유망성 검사!!
	if (promising(depth, n) == true){
		if (depth == n) {
			cnt++;
		}
		else {
			for (int i = 1; i <= n; i++) {
				col[depth + 1] = i;
				nQueen(depth + 1, n);
			}
		}
	}
}

int main() {
	int N;

	cin >> N;
	cin.get();

	nQueen(0, N);
	cout << cnt;

	return 0;
}