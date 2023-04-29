#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> happy; //store happiness between each node
vector<bool> check; //check if we already visit that node
int ans = -200000000;

//calculate possible maximum happiness
int bound( int node ){
    int summx = 0;
    int mx;

    for( int i = 0 ; i < happy.size() - 1 ; i++ ){

        //if we already visit i th node
        //note: `node` can be calculate for the maximum sum
        //      because we are at that `node` and have to visit to another node
        if( check[i] ) continue;

        mx = -2000000000;

        for( int j = 0 ; j < happy.size() ; j++ ){

            //if 1. we already visit j th node
            //or 2. we are now at the `node`
            //or 3. we are travel from one node to the same
            if( check[j] || j == node || i == j ) continue;
            mx = max( mx, happy[i][j] );
        }

        summx += mx;

    }

    return summx;
}

void findPath( int node, int n, int acc ){

    //if n == 1: means start and finish point is the same
    //if n == 2: means we already visit every point except n th point
    if( n <= 2 ){
        ans = max( ans, acc + *( happy[node].end() - 1 ) );
        return;
    }

    //if happiness at now + maximum happiness in future <= answer we have know
    // = never have and answer that more than answer we have know
    // = no need to do more
    if( acc + bound(node) <= ans ) return;

    check[node] = true;


    for( int i = 1 ; i < happy[node].size() - 1 ; i++ ){
        if( !check[i] ){
            findPath( i, n - 1, acc + happy[node][i] );
        }
    }

    check[node] = false;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    happy.resize(n);
    check.resize(n);

    for( int i = 0 ; i < n ; i++ ){
        happy[i].resize(n);

        for( int j = 0 ; j < n ; j++ )
            cin >> happy[i][j];
    }

    findPath( 0, n, 0 );

    cout << ans;
}
