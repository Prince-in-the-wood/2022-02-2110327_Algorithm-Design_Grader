#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> dis;

int main(){

    int n, e, k;
    int a, b;
    int ans = 0;

    cin >> n >> e >> k;

    graph.resize(n+1);
    dis.resize(n+1);

    for( int i = 0 ; i < e ; i++ ){
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;
    q.push(0);
    dis[0] = 0;

    while( !q.empty() ){
        a = q.front();
        q.pop();

        if( dis[a] == k ){
            ans++;
            continue;
        }

        for( int i = 0 ; i < graph[a].size() ; i++ ){
            if( dis[ graph[a][i] ] == 0 && graph[a][i] != 0 ){
                dis[ graph[a][i] ] = dis[a] + 1;
                q.push( graph[a][i] );
            }
        }
    }

    cout << ans;

}

