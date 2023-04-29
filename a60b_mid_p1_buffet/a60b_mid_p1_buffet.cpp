#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> food;

int main(){

    int f, n, w;

    cin >> f >> w >> n;

    food.resize(f);

    for( int i = 0 ; i < f ; i++ ){
        cin >> food[i];
    }

    //sort food position from left to right
    sort( food.begin(), food.end() );

    int cnt = 0, now;

    for( int i = 0 ; i < food.size() ; i++ ){
        //if food[i] is out of scope that we are using now
        if( i == 0 || food[i] > now ){
            now = food[i] + 2 * w;
            cnt++;
        }
    }

    cout << cnt;

}
