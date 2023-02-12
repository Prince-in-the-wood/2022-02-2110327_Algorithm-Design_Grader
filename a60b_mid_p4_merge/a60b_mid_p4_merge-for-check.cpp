#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> input;

void mergethem( int l, int m, int r ){

    queue<int> q1, q2;

    for( int i = l ; i < m ; i++ )
        q1.push( input[i] );

    for( int i = m ; i < r ; i++ )
        q2.push( input[i] );

    int i = l;

    while( !q1.empty() && !q2.empty() ){
        if( q1.front() < q2.front() ){
            input[i++] = q1.front();
            q1.pop();
        }else{
            input[i++] = q2.front();
            q2.pop();
        }
    }

    while( !q1.empty() ){
        input[i++] = q1.front();
        q1.pop();
    }

    while( !q2.empty() ){
        input[i++] = q2.front();
        q2.pop();
    }

}

int mergesort( int l, int r ){

    if( l >= r - 1 )
        return 0;

    bool ok = true;

    for( int i = l ; i < r ; i++ )
        if( l <= i - 1 && input[i-1] > input[i] ) ok = false;

    if( ok ) return 0;

    int mid = ( l + r )/2;
    int ans = mergesort( l, mid ) + mergesort( mid, r );
    mergethem( l, mid, r );

    return 2 + ans;

}

int main(){

    int n;

    cin >> n;

    input.resize(n);

    for( int i = 0 ; i < n ; i++ ){
        cin >> input[i];
    }

    cout << mergesort( 0, n ) + 1;

    cout << "\n----\n";

    for( int i = 0 ; i < n ; i++ )
        cout << input[i] << " ";

}
