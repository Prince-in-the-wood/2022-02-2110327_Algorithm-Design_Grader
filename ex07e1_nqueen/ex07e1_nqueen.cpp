#include <iostream>
#include <vector>

using namespace std;

vector<int> board;// at row i queen is on column board[i]

bool valid( int nw ){

    for( int i = 0 ; i < nw ; i++ ){
        if( board[i] == board[nw] || abs( i - nw ) == abs( board[i] - board[nw] ) ) return false;
    }

    return true;
}

int nqueen(int nw, int n ){
    if( nw == n ) return 1;

    int ans = 0;

    for( int i = 0 ; i < n ; i++ ){

        board[nw] = i;

        if( valid(nw) ) ans += nqueen( nw + 1, n );

    }

    return ans;
}

int main(){

    int n;

    cin >> n;

    board.resize(n);

    cout << nqueen( 0, n );
}
