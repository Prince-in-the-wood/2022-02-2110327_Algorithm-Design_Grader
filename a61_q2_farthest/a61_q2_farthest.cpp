#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> dis;
priority_queue<pair<int,int>> pq; //weight, node

int main(){

    int n;
    int node, weight;
    int newnode;

    cin >> n;

    graph.resize(n+1);
    dis.resize(n+1);

    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            cin >> weight;

            if( weight != -1 && i != j ){
                graph[i].push_back( {j, weight} );
            }
        }
    }

    //init
    for( int i = 1 ; i <= n ; i++ ){
        dis[i] = 2000000000;
    }

    dis[1] = 0;
    pq.push( {0, 1} );

    while( !pq.empty() ){
        node = pq.top().second;
        pq.pop();

        for( int i = 0 ; i < graph[node].size() ; i++ ){
            newnode = graph[node][i].first;
            weight = graph[node][i].second;

            if( dis[newnode] > dis[node] + weight ){
                dis[newnode] = dis[node] + weight;
                pq.push( { -dis[newnode], newnode } );
            }

        }
    }


    bool notvisit = false;
    int ans = 0;

    for( int i = 1 ; i <= n ; i++ ){
        //check if there is any node that cannot be visit
        if( dis[i] == 2000000000 ){
            notvisit = true;
            break;
        }

        ans = max( ans, dis[i] );

    }

    if( notvisit ) cout << -1;
    else cout << ans;

}
