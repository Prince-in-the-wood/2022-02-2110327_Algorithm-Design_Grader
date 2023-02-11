#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> point[50010];
pair<int, int> strip[50010];

const int MAX = ( 30000 * 30000 ) * 2;

bool comparex( pair<int, int> l, pair<int, int> r ){
    if( l.first == r.first )
        return l.second < r.second;
    return l.first < r.first;
}

bool comparey( pair<int, int> l, pair<int, int> r ){
    if( l.second == r.second )
        return l.first < r.first;
    return l.second < r.second;
}

int distance( pair<int, int> p1, pair<int, int> p2 ){

    int disx = p1.first - p2.first;
    int disy = p1.second - p2.second;

    return disx * disx + disy * disy;
}

int findMinStrip( int nstrip, int minDis ){

    int ans = minDis;

    for( int i = 0 ; i < nstrip ; i++ ){
        for( int j = i + 1 ; j < nstrip ; j++ ){
            if( distance( strip[i], strip[j] ) > ans )break;
            ans = distance( strip[i], strip[j] );
        }
    }

    return ans;
}

int findMinDis( int start, int stop ){
    if( start == stop ) return MAX;

    int mid = ( start + stop )/2;
    int left = findMinDis( start, mid );
    int right = findMinDis( mid + 1, stop );

    int sz = 0;

    for( int i = start ; i <= stop ; i++ ){
        if( abs( point[i].first - point[mid].first ) <= min( left, right ) ){
            strip[sz++] = point[i];
        }
    }

    sort( strip, strip + sz, comparey );

    return findMinStrip( sz, min( left, right ) );

}

int main(){

    int n, x, y;

    cin >> n;

    for( int i = 0 ; i < n ; i++ ){
        cin >> point[i].first >> point[i].second;
    }

    sort( point, point + n , comparex );

    cout << findMinDis( 0, n - 1 );


}
