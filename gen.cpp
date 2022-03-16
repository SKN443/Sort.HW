#include <bits/stdc++.h>

using namespace std;

#define For(i, a, b) for (int i = a; i <= b; i++)

typedef long long ll;
typedef double db;

const int N = 1e6 + 1e3;

db a[N];

ll Rand(ll x, ll y) {
    return x +((ll)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (ll) rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (ll) rand() * (RAND_MAX + 1) +
                (ll) rand()) % (y - x + 1);
}

string Cal(int x) {
    string ans = "";
    if (x > 0) ans = ((char)(x%10 + '0')) + ans;
    x/=10;
    if (x > 0) ans = ((char)(x%10 + '0')) + ans;
    return ans;
}

int main() {
    srand(time(NULL));
    //clock_t start = clock();
    ofstream inp(".inp");
    ///Tang dan
    //ofstream inp("test1.inp");
    ll n = Rand(1e6-1e3, 1e6+1e3);
    inp <<n <<'\n';

    For(i, 0, n-1) a[i] = (db)Rand(1e3, 1e15)/10000;
    sort(a, a+n);
    For(i, 0, n-1) inp <<fixed <<setprecision(4) <<a[i] <<' ';
    inp <<'\n';
    //inp.close();

    ///Giam dan
    //ofstream inp("test2.inp");
    n = Rand(1e6-1e3, 1e6+1e3);
    inp <<n <<'\n';

    For(i, 0, n-1) a[i] = (db)Rand(1e3, 1e15)/10000;
    sort(a, a+n, greater<db>());
    For(i, 0, n-1) inp <<fixed <<setprecision(4) <<a[i] <<' ';
    inp <<'\n';
    //inp.close();

    ///8 day con lai
    For(t, 1, 8) {
        //ofstream inp(("test" + Cal(t) + ".inp").c_str());
        n = Rand(1e6-1e3, 1e6+1e3);
        inp <<n <<'\n';
        For(i, 1, n) inp <<fixed <<setprecision(4) <<(db)Rand(1e3, 1e15)/10000 <<' ';
        inp <<'\n';
        //inp.close();
    }

    inp.close();
}


