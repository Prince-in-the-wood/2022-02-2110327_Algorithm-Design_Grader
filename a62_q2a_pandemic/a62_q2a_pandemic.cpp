#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int graph[510][510]; // 0 - no pandemic and no mountain
                     // 1 - pandamic and no mountain
                     // 2 - mountain
int direction[4][2] = { {  1,  0 },
                        { -1,  0 },
                        {  0,  1 },
                        {  0, -1 }
                      };

queue< pair< pair<int, int>, int > > q;

int main(){

    int r, c, t;
    int x, y, nx, ny, now;
    int cnt = 0;

    cin >> r >> c >> t;

    for( int i = 0 ; i < r ; i++ ){
        for( int j = 0 ; j < c ; j++ ){
            cin >> graph[i][j];

            if( graph[i][j] == 1 ){
                cnt++;
                q.push( { { i, j}, 0 } );
            }
        }
    }

    //bfs
    while( !q.empty() ){
        x = q.front().first.first;
        y = q.front().first.second;
        now = q.front().second;
        q.pop();

        if( now >= t )break;

        for( int i = 0 ; i < 4 ; i++ ){
            nx = x + direction[i][0];
            ny = y + direction[i][1];

            if( 0 <= nx && nx < r && 0 <= ny && ny < c && graph[nx][ny] == 0 ){
                graph[nx][ny] = 1;

                cnt++;
                q.push( { { nx, ny }, now + 1 } );
            }
        }
    }

    cout << cnt;
}
