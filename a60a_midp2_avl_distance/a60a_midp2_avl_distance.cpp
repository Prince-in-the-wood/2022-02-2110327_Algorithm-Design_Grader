#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
int ans = 0;

const int MAX_Height = 30;

vector<int> findKDis( int node, int k, int height ){

    vector<int> nodeInHeight( MAX_Height, 0 );

    if( graph[node].empty() ){
        nodeInHeight[height] = 1;
        return nodeInHeight;
    }

    nodeInHeight = findKDis( graph[node][0], k, height + 1 );
    nodeInHeight[height] = 1;

    if( graph[node].size() == 1 ){
        if( height + k < MAX_Height )
            ans += nodeInHeight[ height + k ];
        return nodeInHeight;
    }

    vector<int> nodeInHeight2 = findKDis( graph[node][1], k, height + 1 );
    nodeInHeight2[height] = 1;

    int idx;

    for( int i = height ; i < MAX_Height ; i++ ){

        //Since i - height is distance from this node to the one children side (Assume it is left)
        //then it needs the right one to be far from this node = k - ( i - height )
        idx = ( k - ( i - height ));

        //but k might be less than i - height
        //and we complete the find only in this height ( not less this than height )
        //idx must be >= 0 and idx + height not more than max height
        if( 0 <= idx && height + idx < MAX_Height )
            ans += nodeInHeight[i] * nodeInHeight2[ height + idx ];
    }
    for( int i = height + 1 ; i < MAX_Height ; i++ )
        nodeInHeight[i] += nodeInHeight2[i];

    return nodeInHeight;
}

int main(){

    int n, k;
    int a, b;

    cin >> n >> k;

    graph.resize( n + 1 );

    for( int i = 1 ; i < n ; i++ ){
        cin >> a >> b;

        graph[a].push_back(b);
    }

    vector<int> show = findKDis( 1, k, 0 );

    cout << ans;


}
