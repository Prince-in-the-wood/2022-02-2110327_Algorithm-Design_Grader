#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

                                //  i, j
vector<pair<int,int>> correct = { { 3, 3}, { 0, 0}, { 0, 1}, { 0, 2}, { 0, 3},
                                  { 1, 0}, { 1, 1}, { 1, 2}, { 1, 3},
                                  { 2, 0}, { 2, 1}, { 2, 2}, { 2, 3},
                                  { 3, 0}, { 3, 1}, { 3, 2},
                                };

struct game{

    int step;

    vector<vector<int>> table;

    //cost function: calculate possible number of step we have to do more = distance between each tile and its correct position
    int cost() const {
        int ans = 0;

        for( int i = 0 ; i < 4 ; i++ ){
            for( int j = 0 ; j < 4 ; j++ ){
                if( this->table[i][j] == 0 ) continue;
                ans += abs( i - correct[ this->table[i][j] ].first ) + abs( j - correct[ this->table[i][j] ].second );
            }
        }

        return ans;
    }

    //emptyTile in table
    pair<int, int> emptyTile() const{
        for( int i = 0 ; i < 4 ; i++ ){
            for( int j = 0 ; j < 4 ; j++ ){
                if( this->table[i][j] == 0 )
                    return { i, j };
            }
        }
    }

    //if each tile are in  its correct place
    bool fin() const {
        return cost() == 0;
    }

    bool operator<( const game& r )const{
        int cthis  = cost();
        int cright = r.cost();

        //we can estimate the step we use by step we have done + cost
        return cthis + step > cright + r.step;
    }



};

vector<pair<int,int>> po = { {  0,  1}, {  0, -1},
                             {  1,  0}, { -1,  0} };

set< vector<vector<int> > > s;
priority_queue<game> pq;

int main(){

    vector<vector<int>> table(4);
    game state;

    for( int i = 0 ; i < 4 ; i++ ){
        table[i].resize(4);

        for( int j = 0 ; j < 4 ; j++ )
            cin >> table[i][j];
    }

    s.insert( table );

    state.step = 0;
    state.table = table;
    pq.push( state );

    while( !pq.empty() ){
        state = pq.top();
        pq.pop();

        if( state.fin() ){
            cout << state.step;
            break;
        }

        game nxt;
        pair<int, int> nxtMove, thisMove = state.emptyTile();

        for( int i = 0 ; i < 4 ; i++ ){

            nxt.step = state.step + 1;
            nxt.table = state.table;
            nxtMove.first = thisMove.first + po[i].first;
            nxtMove.second = thisMove.second + po[i].second;

            //valid nxtMove
            if( 0 <= nxtMove.first && nxtMove.first < 4 && 0 <= nxtMove.second && nxtMove.second < 4 ){
                swap( nxt.table[ thisMove.first ][ thisMove.second ], nxt.table[ nxtMove.first ][ nxtMove.second ] );


                //never found before?
                if( s.find( nxt.table ) == s.end() ){
                    s.insert( nxt.table );
                    pq.push( nxt );
                }
            }

        }
    }


}

