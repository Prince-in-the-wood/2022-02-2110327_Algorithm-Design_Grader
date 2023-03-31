#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> graph;
vector<int> check; // 0 - white, 1 - gray, 2 - black

void setGraph( int v ){

    graph.resize(v);
    check.resize(v);

    for( int i = 0 ; i < v ; i++ ){
        graph[i].clear();
        check[i] = 0;
    }

}

bool dfs( int node, int parent ){

    bool cycleFound = false;

    for( int i = 0 ; i < graph[node].size() && !cycleFound ; i++ ){

        if( check[ graph[node][i] ] == 0 ){
            check[ graph[node][i] ] = 1;
            cycleFound = cycleFound || dfs( graph[node][i], node );
        }

        if( check[graph[node][i]] == 1 && graph[node][i] != parent )
            return true;

    }

    check[node] = 2;

    return cycleFound;
}

int main(){

    int T;
    int v, e;
    int a, b;
    bool cycleFound;

    cin >> T;

    for( int t = 0 ; t < T ; t++ ){

        cin >> v >> e;

        setGraph(v);

        cycleFound = false;

        for( int i = 0 ; i < e ; i++ ){
            cin >> a >> b;

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for( int i = 0 ; i < v && !cycleFound ; i++ ){

            if( check[i] != 0 )continue;

            check[i] = 1;
            cycleFound = dfs(i, i);
        }

        if( cycleFound ) cout << "YES\n";
        else cout << "NO\n";
    }
}
