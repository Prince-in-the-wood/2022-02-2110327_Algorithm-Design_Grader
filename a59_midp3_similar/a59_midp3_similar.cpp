#include <iostream>

using namespace std;

bool check_similar( string& a, string&b , int la, int ra, int lb, int rb ){

    if( la == ra )
        return a[la] == b[lb];

    int mida = ( la + ra )/2;
    int midb = ( lb + rb )/2;

    return ( check_similar( a, b, la, mida, lb, midb ) && check_similar( a, b, mida + 1 , ra, midb + 1, rb ) ) ||
           ( check_similar( a, b, la, mida, midb + 1, rb ) && check_similar( a, b, mida + 1 , ra, lb, midb ) );
}

int main(){

    string a, b;

    cin >> a >> b;

    if( check_similar( a, b, 0, a.size() - 1, 0, b.size() - 1 ) )
        cout << "YES";
    else
        cout << "NO";

}
