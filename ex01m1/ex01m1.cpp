#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void findAns( int x, int y, int ex, int ey, int l, vector< pair<int, pair<int,int> > >& ans ){
    if( l == 2 ){

        int type;

        if( ex < x + l/2 && ey < y + l/2 )
            type = 0;
        else if( ex >= x + l/2 && ey < y + l/2 )
            type = 1;
        else if( ex < x + l/2 && ey >= y + l/2 )
            type = 2;
        else
            type = 3;

        ans.push_back( { type, { x, y } } );
        return;
    }

    int newX = x + l/2, newY = y + l/2;

    if( ex < x + l/2 && ey < y + l/2 ){
        findAns(    x,    y,       ex,       ey, l/2, ans );
        findAns( newX,    y,     newX, newY - 1, l/2, ans );
        findAns(    x, newY, newX - 1,     newY, l/2, ans );
        findAns( newX, newY,     newX,     newY, l/2, ans );
        ans.push_back( { 0, { newX - 1, newY - 1 } } );
    }
    else if( ex >= x + l/2 && ey < y + l/2 ){
        findAns(    x,    y, newX - 1, newY - 1, l/2, ans );
        findAns( newX,    y,       ex,       ey, l/2, ans );
        findAns(    x, newY, newX - 1,     newY, l/2, ans );
        findAns( newX, newY,     newX,     newY, l/2, ans );
        ans.push_back( { 1, { newX - 1, newY - 1 } } );
    }
    else if( ex < x + l/2 && ey >= y + l/2 ){
        findAns(    x,    y, newX - 1, newY - 1, l/2, ans );
        findAns( newX,    y,     newX, newY - 1, l/2, ans );
        findAns(    x, newY,       ex,       ey, l/2, ans );
        findAns( newX, newY,     newX,     newY, l/2, ans );
        ans.push_back( { 2, { newX - 1, newY - 1 } } );
    }
    else{
        findAns(    x,    y, newX - 1, newY - 1, l/2, ans );
        findAns( newX,    y,     newX, newY - 1, l/2, ans );
        findAns(    x, newY, newX - 1,     newY, l/2, ans );
        findAns( newX, newY,       ex,       ey, l/2, ans );
        ans.push_back( { 3, { newX - 1, newY - 1 }} );
    }
}

int main(){

    int l, x, y;

    cin >> l >> x >> y;

    vector<pair<int,pair<int, int >>> ans; // type, coordinate;


    findAns( 0, 0, x, y, l, ans );

    cout << ans.size() << "\n";

    for( int i = 0 ; i < ans.size() ; i++ )
        cout << ans[i].first << " " << ans[i].second.first << " " << ans[i].second.second << "\n";
}
