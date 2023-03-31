#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> pre;
bool check[1010];

int main(){

    int n, e;
    int a, b;
    bool isNotOk;

    cin >> n >> e;

    pre.resize(n+1);

    for( int i = 0 ; i < e ; i++ ){
        cin >> a >> b;

        pre[b].push_back(a);
    }

    for( int t = 0 ; t < 5 ; t++ ){

        //init
        for( int i = 1 ; i <= n ; i++ )
            check[i] = false;

        isNotOk = false;

        for( int i = 0 ; i < n ; i++ ){
            cin >> a;

            for( int j = 0 ; j < pre[a].size() && !isNotOk ; j++ ){
                if( !check[ pre[a][j] ] ){
                    isNotOk = true;
                    break;
                }

            }
            check[a] = true;
        }

        if( isNotOk ) cout << "FAIL\n";
        else cout << "SUCCESS\n";

    }

}
