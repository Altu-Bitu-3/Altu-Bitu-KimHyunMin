#include <iostream>

using namespace std;

int findLength(int R, int B)
{
    for (int i = R; i > 0; i--) // i가 큰 수부터 시작하면 무조건 i가 L(큰수)
    {
        for (int j = 1; j <= i; j++) // j 는 어차피 i보다 작거나 같으므로 i까지 돌려준다
        {
            if ((2 * (i + j) == R + 4) && (i * j == R + B))
            {
                return i; // i 가 당연히 더 크다
            }
        }
    }
    return 0;
}

int main()
{
    int R, B, L, W;

    cin >> R >> B;
    // 2*(L+W) = R + 4 , L*W = B+R
    L = findLength(R, B);
    W = (R + B) / L;
    cout << L << " " << W;
    return 0;
}