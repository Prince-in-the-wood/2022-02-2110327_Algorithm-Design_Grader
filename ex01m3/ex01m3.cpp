#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){

    int n, test;
    long long int minT, no;
    long long int l, r, mid;

    cin >> n >> test;

    vector<long long int> time(n);

    for( int i = 0 ; i < n ; i++ ){
        cin >> time[i];

        minT = ( i == 0 )? time[i] : min( minT, time[i] );
    }

    for( int i = 0 ; i < test ; i++ ){
        cin >> no;

        l = 0;
        r = minT * no;

        while( l < r ){
            mid = ( l + r )/2;

            long long int cnt = 0;

            for( int j = 0 ; j < n ; j++ )
                cnt += 1 + mid/time[j];

            if( cnt >= no )
                r = mid;
            else
                l = mid + 1;
        }

        cout << l << "\n";


    }
}
