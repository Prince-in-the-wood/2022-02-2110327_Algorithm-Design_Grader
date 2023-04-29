#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pond;

int main(){

    int n, l;

    cin >> n >> l;

    pond.resize(n);

    for( int i = 0 ; i < n ; i++ )
        cin >> pond[i];

    sort( pond.begin(), pond.end() );

    int cnt = 0, now;

    //sort pond position from left to right
    for( int i = 0 ; i < n ; i++ ){

        //if pond[i] is out of scope that we are using now
        if( i == 0 || now < pond[i] ){
            now = pond[i] + l - 1;
            cnt++;
        }
    }

    cout << cnt;
}
