#include <iostream>
#include <vector>

using namespace std;

vector<int> vi;

vector<int> hanamard( int l, int r ){

    if( l == r ){
        vector<int> ans = { vi[l] };
        return ans;
    }

    if( l < r ){
        int mid = ( l + r )/2;

        vector<int> ans1 = hanamard( l , mid );
        vector<int> ans2 = hanamard( mid + 1, r );
        vector<int> ans( r - l + 1 );
        int width = ans.size() / 2;


        for( int i = 0 ; i < width ; i++ ){
            ans[i] += ans1[i] + ans2[i];
        }

        for( int i = width ; i < width * 2 ; i++ ){
            ans[i] += ans1[ i % width ] - ans2[ i % width ];
        }


        return ans;
    }

}

int main(){

    int n;

    cin >> n;
    vi.resize( n );

    for( int i = 0 ; i < n ; i++ )
        cin >> vi[i];

    vector<int> ans = hanamard( 0, n - 1 );

    for( int i = 0 ; i < ans.size() ; i++ )
        cout << ans[i] << " ";


}
