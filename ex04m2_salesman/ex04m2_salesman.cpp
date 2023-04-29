#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> portal;
vector<int> seq;
vector<int> dis;

//calculate shortest path between two companies
int cal( int i, int j ){

    //clockwise or counter-clockwise
    int way1 = dis[ max( i, j ) ] - dis[ min( i, j ) ];
    int way2 = *( dis.end() - 1 ) - way1;

    //choose the minimum one
    return min( way1, way2 );
}

int main(){

    int n, m;
    int sum, simpleway, portalway;

    cin >> n >> m;

    portal.resize(n);
    seq.resize(m+1);
    dis.resize(m+1);

    //Input: sequence of company we have to visit
    for( int i = 0 ; i < m ; i++ ){
        cin >> seq[i];
    }
    seq[m] = seq[0];

    //Input: distance between each company
    for( int i = 0 ; i < m ; i++ ){
        cin >> dis[i+1];

        dis[i+1] += dis[i];
    }

    //Input: company that portal appear in each day
    for( int i = 0 ; i < n ; i++ )
        cin >> portal[i].first >> portal[i].second;

    //calculate shortest path in each day
    for( int i = 0 ; i < n ; i++ ){
        sum = 0;

        for( int j = 1 ; j <= m ; j++ ){
            simpleway = cal( seq[j-1], seq[j] );
            portalway = min( cal( seq[j-1], portal[i].first ) + cal( portal[i].second, seq[j] ),
                             cal( seq[j-1], portal[i].second ) + cal( portal[i].first, seq[j] ) );

            sum += min( simpleway, portalway );
        }

        cout << sum << "\n";
    }

}
