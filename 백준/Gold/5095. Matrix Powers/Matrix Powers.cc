#include <iostream>
#include <vector>

using namespace std;
using Mat = vector<vector<int>>;

int N, M, P;
Mat A, ans;

bool init();
void solve();
Mat matrixMul(const Mat& A, const Mat& B);
Mat matrixPow(Mat A, int p);

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    while(init())
        solve();
}

bool init()
{
    cin >> N >> M >> P;
    if(N == 0 and M == 0 and P == 0)
        return false;

    A.assign(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> A[i][j];

    return true;
}

void solve(){
    ans = matrixPow(A, P);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            cout << ans[i][j]<<" ";
        cout << "\n";
    }
    cout << "\n";
}

Mat matrixMul(const Mat& A, const Mat& B)
{
    Mat C(N, vector<int>(N, 0));
    
    for(int i = 0; i < N; i++)
    {
        for(int k = 0; k < N; k++)
        {
            int Aik = A[i][k];
            for(int j = 0; j < N; j++)
                C[i][j] = (C[i][j] + 1LL * Aik * B[k][j]) % M;
        }
    }

    return C;
}

Mat matrixPow(Mat A, int p)
{
    Mat result(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++)
        result[i][i] = 1;

    while(p > 0)
    {
        if(p % 2 == 1)
            result = matrixMul(result, A);
        A = matrixMul(A, A);
        p /= 2;
    }

    return result;
}