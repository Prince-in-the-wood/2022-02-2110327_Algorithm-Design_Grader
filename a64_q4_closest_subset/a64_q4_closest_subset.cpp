#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> member;
vector<int> cal;
int ans = 1999999999;

void findAns( int idx, int acc, int m, int k ){

    //choose it properly
    if( m == 0 ){
       ans = min( ans, abs( k - acc ) );
       return;
    }

    //not enough member to choose
    if( m > member.size() - idx ) return;

    //it is more than answer we have found
    if( acc > k && abs( k - acc ) >= ans ) return;

    //possible minimum sum
    int mn = ( idx == 0 ) ? cal[ idx + m - 1 ] : cal[ idx + m - 1 ] - cal[ idx - 1 ];

    //if acc + member[idx] > k
    // means difference between k and acc is increasing
    // = no need to do more recursive
    // = only find possible minimum sum
    if( acc + member[idx] > k )
       ans = min( ans, abs( k - acc - mn ) );
    else
       findAns( idx + 1, acc + member[idx], m - 1, k );

    //not choose this member
    findAns( idx + 1, acc, m, k );
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;

    cin >> n >> m >> k;

    member.resize(n);
    cal.resize(n);

    for( int i = 0 ; i < n ; i++ ){
        cin >> member[i];
    }

    sort( member.begin(), member.end() );

    for( int i = 0 ; i < n ; i++ )
        cal[i] = ( i == 0 ) ? member[i] : cal[i-1] + member[i];


    findAns( 0, 0, m, k );

    cout << ans;
}
