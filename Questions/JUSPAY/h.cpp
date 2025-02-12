#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <functional>

using namespace std;

int z(vector<string> x) {
    unordered_map<char, long long> y;
    unordered_set<char> w;
    
    auto q = [&](const string& v, int u) {
        int t = v.size();
        if(t > 1) {
            w.insert(v[0]);
        }
        long long s = 1;
        for (int r = t - 1; r >= 0; r--) {
            y[v[r]] += u * s;
            s *= 10;
        }
    };
    
    q(x[0], 1);
    q(x[1], 1);
    q(x[2], -1);
    
    vector<char> p;
    for(auto& o : y) {
        p.push_back(o.first);
    }
    
    if(p.size() > 10) return 0;
    
    sort(p.begin(), p.end(), [&](char n, char m) {
        return abs(y[n]) > abs(y[m]);
    });
    
    int l = 0;
    vector<bool> k(10, false);
    
    function<void(int, long long)> j = [&](int i, long long h) {
        if(i == p.size()){
            if(h == 0) l++;
            return;
        }
        char g = p[i];
        for (int f = 0; f < 10; f++) {
            if (k[f]) continue;
            if (f == 0 && w.find(g) != w.end()) continue;
            k[f] = true;
            j(i + 1, h + y[g] * f);
            k[f] = false;
        }
    };
    
    j(0, 0);
    return l;
}