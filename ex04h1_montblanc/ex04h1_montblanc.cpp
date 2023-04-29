#include <iostream>
#include <vector>

using namespace std;

vector<int> height;

//calculate number of days that use to travel if we travel dis per day
int travel( int dis ){
    int now = 0, cnt = 1;

    for( int i = 1 ; i < height.size() ; i++ ){
        if( now + height[i] - height[i-1] > dis ){
            now = height[i] - height[i-1];
            cnt++;
        }else{
            now += height[i] - height[i-1];
        }
    }

    return cnt;
}

int main(){

    int n, d;
    int l, r, mid;
    int day;
    int mxdif = 0;

    cin >> n >> d;

    height.resize(n+1);

    for( int i = 1 ; i <= n ; i++ ){
        cin >> height[i];

        mxdif = max( mxdif, height[i] - height[i-1] );
    }

    //minimum distance we should travel is distance between each tent
    l = mxdif;

    //maximum distance we should travel is maximum height
    r = height[n];

    //find the answer
    while( l < r ){
        mid = ( l + r )/2;

        if( travel( mid ) <= d )
            r = mid;
        else
            l = mid + 1;

    }

    cout << l << " " << travel( l );

}
