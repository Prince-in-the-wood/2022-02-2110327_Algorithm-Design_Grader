#include<iostream>
#include<queue>

using namespace std;

char maze[110][110];
int dis[110][110];
pair<int, int> direction[4] = { { 0, 1}, { 0, -1},
                                { 1, 0}, {-1,  0} };

int main(){

    int r, c;
    pair<int,int> tile;
    pair<int,int> ntile;

    cin >> r >> c;

    for( int i = 1 ; i <= r ; i++ ){

        for( int j = 1 ; j <= c ; j++ ){
            cin >> maze[i][j];
            dis[i][j] = -1;
        }
    }

    queue<pair<int,int>> q;
    q.push({ 1, 1 });
    dis[1][1] = 0;

    while( !q.empty() ){
        tile = q.front();
        q.pop();

        for( int i = 0 ; i < 4 ; i++ ){
            ntile.first = tile.first + direction[i].first;
            ntile.second = tile.second + direction[i].second;

            if( 1 <= ntile.first && ntile.first <= r && 1 <= ntile.second && ntile.second <= c ){
                if( dis[ntile.first][ntile.second] == -1 && maze[ntile.first][ntile.second] == '.' ){
                    dis[ntile.first][ntile.second] = dis[tile.first][tile.second] + 1;
                    q.push(ntile);
                }
            }
        }
    }

    cout << dis[r][c];
}
