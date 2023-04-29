#include <iostream>
#include <queue>

using namespace std;

#define Max 2000000000
typedef pair<int, pair<int,int>> pairofintpair;


int graph[1010][1010];
int dis[1010][1010];
priority_queue<pairofintpair, vector<pairofintpair>, greater<pairofintpair>> q;

pair<int,int> direction[4] = { { 0, 1}, {0, -1},
                               {-1, 0}, {1,  0}};

bool valid( pair<int, int> p ){
    return    0 < p.first  && p.first  <= 1000
           && 0 < p.second && p.second <= 1000;
}

bool isHole( pair<int, int> p ){
    return graph[p.first][p.second] == -1;
}

int main(){

    pair<int,int> house;
    pair<int,int> now, next;
    int n, cost,ans = Max;

    cin >> n;
    cin >> house.first >> house.second;

    for( int i = 0 ; i < n ; i++ ){
        cin >> now.first >> now.second;

        graph[now.first][now.second] = -1;
    }

    for( int i = 0 ; i <= 1000 ; i++ ){
        for( int j = 0 ; j <= 1000 ; j++ )
            dis[i][j] = Max;
    }

    dis[house.first][house.second] = 0;
    q.push( {0, house });

    while( !q.empty() ){
        now = q.top().second;

        q.pop();

        for( int i = 0 ; i < 4 ; i++ ){
            next.first = now.first + direction[i].first;
            next.second = now.second + direction[i].second;

            if( valid( next ) ){

                if( ( !isHole(now) && !isHole(next) ) || ( isHole(now) && !isHole(next) ) )
                    cost = 1;
                else
                    cost = 0;

                if( dis[next.first][next.second] > dis[now.first][now.second] + cost ){
                    dis[next.first][next.second] = dis[now.first][now.second] + cost;
                    q.push( {dis[next.first][next.second], next});
                }

            }
        }
    }

    for( int i = 1 ; i <= 1000 ; i++ ){
        ans = min( ans, min( min( dis[i][1], dis[i][1000] ), min( dis[1][i], dis[1000][i] ) ));
    }

    cout << ans;

}

