#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){

    int n, w;
    int a, sum = 0;
    int mx;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

    cin >> n >> w;

    pq.push( { 0, 0 } );

    for( int i = 1 ; i <= n ; i++ ){
        cin >> a;

        while( !pq.empty() && i - pq.top().second > w )
            pq.pop();

        sum += a;
        if( pq.empty() ){
            mx = ( i == 1 )? a: max( mx, a );
        }else{
            mx = ( i == 1 )? a: max( mx, sum - pq.top().first );
        }

        pq.push( { sum, i } );

    }


    cout << mx;
}
