#include <iostream>
#include <vector>

using namespace std;

vector<int> dis;
vector<pair<pair<int,int>,int>> edge;

int main(){

    int n, e, s;
    int a, b, w;

    cin >> n >> e >> s;

    //init
    dis.resize(n);
    for( int i = 0 ; i < n ; i++ )
        dis[i] = 2000000000;
    dis[s] = 0;

    edge.resize(e);

    for( int i = 0 ; i < e ; i++ ){
        cin >> edge[i].first.first >> edge[i].first.second >> edge[i].second;
    }

    //Bellman-Ford
    for( int v = 1 ; v <= n ; v++ ){
        for( int i = 0 ; i < e ; i++ ){
            a = edge[i].first.first;
            b = edge[i].first.second;
            w = edge[i].second;

            if( dis[b] > dis[a] + w ){
                dis[b] = dis[a] + w;
            }
        }
    }

    //check if negative edge
    bool negcycle = false;

    for( int i = 0 ; i < e ; i++ ){
        a = edge[i].first.first;
        b = edge[i].first.second;
        w = edge[i].second;

        if( dis[b] > dis[a] + w ){
            negcycle = true;
            break;
        }
    }

    if( negcycle ) cout << "-1";
    else{
        for( int i = 0 ; i < n ; i++ ){
            cout << dis[i] << " ";
        }
    }




}
