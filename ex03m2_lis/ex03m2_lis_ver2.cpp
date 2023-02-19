#include <iostream>

using namespace std;

int lis[1010];// longest increasing subsequence from 0 to i
int seq[1010];// input sequence

int main(){

    int n;
    int ans = 0;

    cin >> n;

    for( int i = 0 ; i < n ; i++ ){
        cin >> seq[i];

        lis[i] = 1;

        //find longest increasing subsequence that end with i th
        for( int j = 0 ; j < i ; j++ ){
            if( seq[j] < seq[i] )
                lis[i] = max( lis[i], lis[j] + 1 );
        }

        ans = max( ans, lis[i] );
    }

    cout << ans;

}

