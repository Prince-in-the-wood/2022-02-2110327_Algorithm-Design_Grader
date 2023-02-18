#include <iostream>

using namespace std;

int sum[1010][1010];

int main(){

    int n, m;
    int k;

    int r1, c1, r2, c2;
    int ans;

    cin >> n >> m;
    cin >> k;

    //input and compute prefix sum
    for( int i = 0 ; i < n ; i++ ){

        for( int j = 0 ; j < m ; j++ ){

            cin >> sum[i][j];

            if( i - 1 >= 0 && j - 1 >= 0 )
                sum[i][j] = sum[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            else if( i - 1 < 0 )
                sum[i][j] = sum[i][j] + sum[i][j-1];
            else
                sum[i][j] = sum[i][j] + sum[i-1][j];

        }

    }

    for( int i = 0 ; i < k ; i++ ){

        cin >> r1 >> c1 >> r2 >> c2;

        if( r1 - 1 >= 0 && c1 - 1 >= 0 )
            ans = sum[r2][c2] - sum[r2][c1-1] - sum[r1-1][c2] + sum[r1-1][c1-1];
        else if( r1 - 1 < 0 )
            ans = sum[r2][c2] - sum[r2][c1-1];
        else
            ans = sum[r2][c2] - sum[r1-1][c2];

        cout << ans << "\n";
    }


}
