#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n, m;
    int item[510][2];
    int dp[510][510];

    int i, j;

    vector<int> ans;

    cin >> n >> m;

    for( i = 1 ; i <= n ; i++ ) //value
        cin >> item[i][0];

    for( i = 1 ; i <= n ; i++ ) //weight
        cin >> item[i][1];

    for( i = 0 ; i <= n ; i++ ){
        for( j = 0 ; j <= m ; j++ ){
            cin >> dp[i][j];
        }
    }

    i = n;//number of thing
    j = m;//weight

    while( i > 0 ){
        if( j - item[i][1] >= 0 && dp[i][j] == dp[i-1][ j - item[i][1] ] + item[i][0] ){
            ans.push_back(i);

            j -= item[i][1];
            i -= 1;
        }else{
            i -= 1;
        }
    }

    cout << ans.size() << "\n";
    for( i = ans.size() - 1 ; i >= 0 ; i-- )
        cout << ans[i] << " ";

}
