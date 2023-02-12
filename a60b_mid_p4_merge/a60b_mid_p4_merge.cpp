#include <iostream>
#include <vector>

using namespace std;

void findAns( vector<int>& ans, int start, int fin, int& k ){

    if( start == fin - 1 || k <= 0 ) return;

    int mid = ( start + fin )/ 2;

    if( k > 0 ){
        k -= 2;
        swap( ans[mid], ans[ mid - 1 ] );
    }

    findAns( ans, start, mid, k );
    findAns( ans,   mid, fin, k );



}

int main(){

    int n, k;

    cin >> n >> k;

    vector<int> ans(n);

    for( int i = 0 ; i < n ; i++ )
        ans[i] = i + 1;

    k -= 1;
    findAns( ans, 0, n, k );

    if( k == 0 ){
        for( int i = 0 ; i < n ; i++ )
            cout << ans[i] << " ";
    }
    else
        cout << -1;

}
