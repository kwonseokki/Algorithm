#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e;
int sum;
int main() {
    cin >> a  >> b >> c >> d >> e;
    a = a * a;
    b = b * b;
    c = c * c;
    d = d * d;
    e = e * e;
    cout << (a + b + c + d + e) % 10 << "\n";
    return 0;
}