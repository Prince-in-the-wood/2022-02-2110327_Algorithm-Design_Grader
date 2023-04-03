#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int R, C;
int times[110][110];
bool check[110][110];
char graph[110][110];
vector< pair< int, pair<int, int> > > ghostInfo; //position, time
pair<int, int> direction[4] = { { 0, -1}, { 0, 1}, {-1,  0}, { 1, 0}};

void init(){

    for( int i = 0 ; i < R ; i++ ){
        for( int j = 0 ; j < C ; j++ ){
            times[i][j] = 2000000000;
            check[i][j] = false;
        }

    }
}

bool valid( pair<int,int> po ){

    return  ( 0 <= po.first && po.first < R && 0 <= po.second && po.second < C ) //1. position they are going to go is in the graph
            && graph[po.first][po.second] != '#';                                //2. this position is not a block(#)

}

void gbfs(pair<int,int> ghost, int ti ){

    queue<pair<int,int>> q;
    pair<int, int> nghost;

    times[ghost.first][ghost.second] = ti;
    q.push( ghost );

    while( !q.empty() ){
        ghost = q.front();
        q.pop();

        for( int i = 0 ; i < 4 ; i++ ){
            nghost.first = ghost.first + direction[i].first;
            nghost.second = ghost.second + direction[i].second;

            //if 1. ghost can be in that place and 2. visit in the shorter time
            //then visit that place
            if( valid(nghost) && times[nghost.first][nghost.second] > times[ghost.first][ghost.second] + 1 ){
                times[nghost.first][nghost.second] = times[ghost.first][ghost.second] + 1;
                q.push( nghost );
            }
        }
    }
}

void pbfs(pair<int,int> pacman){

    queue<pair<int, pair<int,int>>> q;
    pair<int, int> npacman;
    int t;

    //if pacman born at the same place with ghost
    if( times[pacman.first][pacman.second] <= 0 )
        return;

    check[pacman.first][pacman.second] = true;
    q.push( {0, pacman} );

    while( !q.empty() ){
        t = q.front().first;
        pacman = q.front().second;
        q.pop();

        for( int i = 0 ; i < 4 ; i++ ){
            npacman.first = pacman.first + direction[i].first;
            npacman.second = pacman.second + direction[i].second;

            if(   valid(npacman)                                //1. pacman can move to that place
               && times[npacman.first][npacman.second] > t + 1  //2. no ghost is waiting for pacman
               && !check[npacman.first][npacman.second])        //3. never visit this place before
            {                                                   //   (if we come again mean the same as we stay in this place til the time come)
                check[npacman.first][npacman.second] = true;
                q.push( { t+1, npacman } );
            }
        }
    }

}

int main(){

    int test;
    int n, ti;
    pair<int,int> ghost;
    int T;
    pair<int, int> pacman;

    cin >> test;

    for( int t = 0 ; t < test ; t++ ){

        cin >> R >> C;

        cin >> n;

        cin >> T >> pacman.first >> pacman.second;

        //clear old data
        ghostInfo.clear();
        init();

        //input----------------------------------------
        for( int i = 0 ; i < n ; i++ ){
            cin >> ti >> ghost.first >> ghost.second;
            ghostInfo.push_back( {ti, ghost} );
        }



        for( int i = 0 ; i < R ; i++ ){
            for( int j = 0 ; j < C ; j++ ){
                cin >> graph[i][j];
            }
        }

        //Calculate Answer-------------------------------

        sort( ghostInfo.begin(), ghostInfo.end() );

        //bfs of ghost --> which and when ghost can be waiting for pacman
        for( int i = 0 ; i < ghostInfo.size() ; i++ ){
            ti    = ghostInfo[i].first;
            ghost = ghostInfo[i].second;
            if( times[ghost.first][ghost.second] > ti ){
                gbfs(ghost, ti);
            }
        }

        //bfs of pacman --> which place that pacman can go
        pbfs( pacman );

        //find ans
        bool ans = false;

        for( int i = 0 ; i < R && !ans ; i++ ){
            for( int j = 0 ; j < C && !ans ; j++ ){
                //if ghost cannot be there on time but pacman does
                //then ghost cannot catch pacman
                if( times[i][j] > T && check[i][j] )
                    ans = true;
            }
        }

        if( ans ) cout << "YES\n";
        else cout << "NO\n";

    }
}
