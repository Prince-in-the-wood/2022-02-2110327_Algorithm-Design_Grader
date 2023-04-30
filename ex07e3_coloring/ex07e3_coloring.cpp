#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool graph[50][50];
vector<bool> check;
vector<int> color;
vector<vector<int>> connected;

void dfs( int node, int group, int n ){

    //Add node to component
    connected[group].push_back( node );
    check[node] = true;

    for( int i = 0 ; i < n ; i++ ){

        //have an edge to i and never add them to any component
        if( graph[node][i] && !check[i] ){
            dfs( i, group, n );
        }
    }
}

bool valid( int idx, int group, int n ){

    //check if it is valid to assign color to the node
    for( int i = 0 ; i < n ; i++ ){
        if( graph[ connected[group][idx] ][i] && color[ connected[group][idx] ] == color[i] )
            return false;
    }

    return true;
}

bool cancolor( int idx, int numcolor, int group, int n ){

    //color all node in the component
    if( idx == connected[group].size() ) return true;

    //all color we can assign
    for( int i = 1 ; i <= numcolor ; i++ ){

        color[connected[group][idx]] = i;

        //if we can assign i th color to node ( only consider this state )
        //and we can assign other remaining node if we assign color i th to node
        if( valid( idx, group, n ) && cancolor( idx + 1, numcolor, group, n ) ){
            color[connected[group][idx]] = 0;
            return true;
        }
    }

    //no way that we can assign color to all node
    color[connected[group][idx]] = 0;
    return false;

}

int findAns( int group, int n ){

    //using i color to color in this connected component
    for( int i = 1 ; i <= connected[group].size() ; i++ ){
        if( cancolor( 0, i, group, n ) ) return i;
    }
}

int main(){

    int n, e;
    int a, b;
    int ans = 0;

    cin >> n >> e;

    for( int i = 0 ; i < e ; i++ ){
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    check.resize(n);
    color.resize(n);

    //find connected component
    for( int i = 0 ; i < n ; i++ ){
        if( check[i] ) continue;
        connected.push_back( {} );
        dfs( i, connected.size() - 1, n );
    }


    //find minimum color we need in each connected component
    //we must use maximum of them so we can color all node
    for( int i = 0 ; i < connected.size() ; i++ ){
        ans = max( ans, findAns( i, n ) );
    }

    cout << ans;
}
