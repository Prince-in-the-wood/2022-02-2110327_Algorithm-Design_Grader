#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int mergesort( int l, int r, vector<int>& input ){

    if( l == r - 1 ) return 0;

    int mid = ( l + r )/ 2;
    int i;
    int cnt = mergesort( l, mid, input ) + mergesort( mid, r, input );

    queue<int> left, right;

    for( i = l ; i < mid; i++ )
        left.push( input[i] );

    for( i = mid ; i < r ; i++ )
        right.push( input[i] );

    i = l;

    while( !left.empty() && !right.empty() ){

        if( left.front() <= right.front() ){
            input[i] = left.front();
            left.pop();
        }else{
            cnt += left.size();
            input[i] = right.front();
            right.pop();
        }
        i++;
    }

    while( !left.empty() ){
        input[i] = left.front();
        left.pop();
        i++;
    }

    while( !right.empty() ){
        input[i] = right.front();
        right.pop();
        i++;
    }


    return cnt;
}

int main(){

    int n;
    int cnt;

    cin >> n;

    vector<int> input(n);

    for( int i = 0 ; i < n ; i++ )
        cin >> input[i];

    cnt = mergesort( 0, n , input );

    cout << cnt;
}
