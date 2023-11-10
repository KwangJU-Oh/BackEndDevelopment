#include <iostream>
#include <vector>
using namespace std;

vector<int>col(16, 0);
int cnt = 0;

bool promising(int depth, int n) {
	int k = 1; //depth�� 0�̰ų� 1�̸�, ������ �˻��� ��ġ�� ����(�ݵ�� �Ǿ� �ϴϱ�)
	//����ġ�⸦ �ϸ� �ȵ�.
	//����, k�� ���� �밢���� �ִ� �ٸ� ���� ���� ���� 1���� �����ؾ���!(�࿡ ���� ����)
	bool flag = true;

	while (k < depth && flag) {
		if (col[k] == col[depth] || abs(col[k] - col[depth]) == (depth - k)) {
		//���� ���� ���� �ִٸ� Ȥ�� �밢���� ���� �ִٸ�
			flag = false;
		}
		k = k + 1;
	}

	return flag;
}

//���� - ���� row�� �̹� ��ġ�� �� ���ٰ� �����ϰ� ����, �� ���� �������� �˻�!!
void nQueen(int depth, int n) {  //���� ���� depth�� ���� ��ġ�ϰ� ������ �˻�!!
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