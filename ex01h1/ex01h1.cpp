#include <iostream>
#include <vector>

using namespace std;

vector<int> sds;
vector<int> len;

int main(){

    int n, t;
    int cnt, now;

    cin >> n;

    sds.push_back(0);
    len.push_back(0);

    sds.push_back(1);
    len.push_back(1);

    now = 1;
    cnt = 1;

    for( int i = 2 ; len[i-1] <= 2000000000 ; i++ ){
        if( cnt == sds[now] ){
            cnt = 0;
            now++;
        }

        sds.push_back(now);
        len.push_back( sds[i] + len[i-1] );
        cnt++;
    }

    for( int i = 0 ; i < n; i++ ){
        cin >> t;

        cout << lower_bound( len.begin(), len.end(), t ) - len.begin() << "\n";
    }
}
