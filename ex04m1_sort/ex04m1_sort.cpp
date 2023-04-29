#include <iostream>
#include <vector>

using namespace std;

vector<int> seq;
vector<int> cnt(4);
vector<vector<int>> mis(4, vector<int>(4) );

int calculate( int i, int j, int k ){
    int oper1, oper2;
    oper1 = min( mis[i][j], mis[j][i] );
    mis[i][i] += oper1;
    mis[i][j] -= oper1;
    mis[j][i] -= oper1;
    mis[j][j] += oper1;

    oper2 = min( mis[i][j], mis[k][i] );
    mis[i][i] += oper2;
    mis[i][j] -= oper2;
    mis[k][i] -= oper2;
    mis[k][j] += oper2;

    return oper1 + oper2;
}

int main(){

    int n, ans = 0;
    int oper;

    cin >> n;

    seq.resize(n);

    for( int i = 0 ; i < n ; i++ ){
        cin >> seq[i];

        cnt[ seq[i] ]++;
    }

    for( int i = 1 ; i <= 3 ; i++ )
        cnt[i] += cnt[i-1];

    int j = 1;

    for( int i = 0 ; i < n ; i++ ){
        if( i >= cnt[j] ) j++;
        mis[j][ seq[i] ]++;
    }

    //place number in properplace
    ans += calculate( 1, 2, 3 );
    ans += calculate( 1, 3, 2 );
    ans += calculate( 2, 1, 3 );
    ans += calculate( 2, 3, 1 );
    ans += calculate( 3, 1, 2 );
    ans += calculate( 3, 2, 1 );

    cout << ans;


}
