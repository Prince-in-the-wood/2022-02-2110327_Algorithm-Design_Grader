#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> schedule;

int main(){

    int n;
    int last = 0, ans = 0;

    cin >> n;

    schedule.resize( n );

    //start time
    for( int i = 0 ; i < n ; i++ )
        cin >> schedule[i].second;

    //finish time
    for( int i = 0 ; i < n ; i++ )
        cin >> schedule[i].first;

    // maximum choose:
    // choose the one that finish before other
    sort( schedule.begin(), schedule.end() );

    for( int i = 0 ; i < n ; i++ ){
        if( i == 0 || last <= schedule[i].second ){
            last = schedule[i].first;
            ans++;
        }
    }

    cout << ans;
}
