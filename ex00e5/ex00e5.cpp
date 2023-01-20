#include <iostream>
#include <vector>

using namespace std;

void consecutiveOne( int n, vector<int> &sol, int len, int one, int k, bool valid  ){

    if( n == len ){
        if( valid ){
            for( int i = 0 ; i < n ; i++ )
                cout << sol[i];
            cout << "\n";
        }
        return;
    }

    sol[len] = 0;
    consecutiveOne( n, sol, len + 1, 0, k, valid );

    sol[len] = 1;
    consecutiveOne( n, sol, len + 1, one + 1, k, ( one + 1 >= k || valid ) );
}

int main(){

    int n, k;

    cin >> n >> k;

    vector<int> sol(n);

    consecutiveOne( n, sol, 0, 0, k, false );
}
