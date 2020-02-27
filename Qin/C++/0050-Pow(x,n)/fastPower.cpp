//
// Created by qkuns on 2020/2/21.
//

#include <iostream>
#include <map>

using namespace std;

double sPow(double x, int n, map<int, double> &m){
    if(m.find(n) != m.end()) return m[n];
    double res = sPow(x, n / 2, m) * sPow(x, n - n / 2, m);
    m[n] = res;
    return res;
}

double myPow(double x, int n) {
    map<int, double> memo = {{0, 1.0}, {1, x}, {-1, 1 / x}};
    double res = sPow(x, n, memo);
    for(auto i = memo.begin(); i != memo.end(); i++){
        cout << "memo[" << i->first << "] = " << i->second << endl;
    }
    return res;
}

int main(){
    double x = 1.5;
    int n = 3;
    cin >> x >> n;
    cout << myPow(x, n) << endl;
    return 0;
}