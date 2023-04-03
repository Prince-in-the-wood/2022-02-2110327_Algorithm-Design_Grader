#include <iostream>
#include <vector>

using namespace std;

vector<int> start;
vector<pair<pair<int,int>,int>> graph;
vector<int> dis;

int main(){

    int n, m, k;
    int a, b, w;
    int fin;

    cin >> n >> m >> k;
    cin >> fin;

    start.resize(k);
    graph.resize(m);
    dis.resize(n);

    for( int i = 0 ; i < k ; i++ )
        cin >> start[i];

    for( int i = 0 ; i < m ; i++ ){
        cin >> graph[i].first.second >> graph[i].first.first >> graph[i].second;
    }

    for( int i = 0 ; i < n ; i++ )
        dis[i] = 2000000000;
    dis[fin] = 0;

    for( int v = 0 ; v < n ; v++ ){
        for( int i = 0 ; i < m ; i++ ){
            a = graph[i].first.first;
            b = graph[i].first.second;
            w = graph[i].second;

            if( dis[b] > dis[a] + w ){
                dis[b] = dis[a] + w;
            }
        }
    }

    int ans = 2000000000;

    for( int i = 0 ; i < k ; i++ )
        ans = min( ans, dis[ start[i]] );

    cout << ans;
}
