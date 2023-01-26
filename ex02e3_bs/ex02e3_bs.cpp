#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, a;
    int l, r, mid;

    cin >> n >> m;

    vector<int> input(n);

    for( int i = 0 ; i < n ; i++ )
        cin >> input[i];

    for( int i = 0 ; i < m ; i++ ){
        cin >> a;

        l = 0;
        r = n - 1;

        while( l < r ){
            mid = ( l + r + 1 )/2;

            if( input[mid] <= a )
                l = mid;
            else
                r = mid - 1;
        }

        if( input[l] <= a )
            cout << l << "\n";
        else
            cout << "-1\n";
    }

}
