#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> point;
vector<int> ans;

int main(){

    int n;

    cin >> n;

    point.resize(n);

    ans.resize(n);
    int sizeAns = 0;

    for( int i = 0 ; i < n ; i++ ){
        cin >> point[i].first >> point[i].second;
        point[i].second *= -1; //for making them sort: i < j then |xi| <= |xj| and |yi| >= |yj| since both x,y is non negative integer
    }

    sort( point.begin(), point.end() );

    for( int i = 0 ; i < n ; i++ ){
        if( i == 0 ){
            ans[sizeAns] = point[i].second;
            sizeAns++;
            continue;
        }

        if( point[i-1].first == point[i].first ) //no any y more than the first y we found so we can continue
            continue;

        int idx = lower_bound( ans.begin(), ans.begin() + sizeAns, point[i].second ) - ans.begin();
        // find where yi should be
        // if there is any y that less than or equal yi mean that (xj, yj) dominate all of those y <= yi

        ans[idx] = point[i].second;
        sizeAns = idx + 1;
    }

    cout << sizeAns;

}
