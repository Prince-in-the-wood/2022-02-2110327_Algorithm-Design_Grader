#include <iostream>
#include <map>
#include <queue>

using namespace std;

map<pair<int,int>,int> graph;
map<pair<int,int>,int> dis;
priority_queue<pair<int,pair<int,int>>> pq;

pair<int, int> direc[4] = { { 0, -1}, { 0,  1},
                          {-1,  0}, { 1,  0}};

int main(){

    int r, c;
    pair<int,int> po, npo;

    cin >> r >> c;

    for( int i = 0 ; i < r ; i++ ){

        for( int j = 0 ; j < c ; j++ ){
            cin >> graph[{i,j}];
        }
    }

    //init
    for( int i = 0 ; i < r ; i++ ){
        for( int j = 0 ; j < c ; j++ )
            dis[{i, j}]= 2000000000;
    }

    dis[{0,0}] = 0;
    pq.push({0,{0,0}});

    while( !pq.empty() ){
        po = pq.top().second;
        pq.pop();

        for( int i = 0 ; i < 4 ; i++ ){
            npo.first = po.first + direc[i].first;
            npo.second = po.second + direc[i].second;

            if(    0 <= npo.first && npo.first < r && 0 <= npo.second && npo.second < c //valid position
                && dis[npo] > dis[po] + graph[npo] )//distance is less than before
            {
                    dis[npo] = dis[po] + graph[npo];
                    pq.push( { -dis[npo],  npo } );
            }
        }
    }

    for( int i = 0 ; i < r ; i++ ){
        for( int j = 0 ; j < c ; j++ )
            cout << dis[{i,j}] << " ";
        cout << "\n";
    }


}
