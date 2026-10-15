#include <bits/stdc++.h>
using namespace std;

struct State {
    int len;
    int mask; // 子集掩码，最多 16 位
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> len(n);
    vector<int> parity(n, 0); // 26 位奇偶性掩码
    
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        len[i] = s[i].size();
        int cnt[26] = {0};
        for (char c : s[i]) cnt[c - 'a'] ^= 1;
        for (int j = 0; j < 26; ++j) {
            if (cnt[j]) parity[i] |= (1 << j);
        }
    }
    
    int halfn = n / 2;
    int down = n - halfn;
    
    unordered_map<int, State> dp1, dp2;////由于26字母掩码占位略大，所以采用map存
    
    // 枚举前半
    int sz1 = 1 << halfn;
    vector<int> xr1(sz1, 0), len1(sz1, 0);//xr:表示得到的26字母掩码
    dp1[0] = {0, 0};
    for (int i = 1; i < sz1; ++i) {
        int low = i & -i;
        int j = __builtin_ctz(low);
        int prev = i ^ low;
        xr1[i] = xr1[prev] ^ parity[j];
        len1[i] = len1[prev] + len[j];
        auto it = dp1.find(xr1[i]);
        if (it == dp1.end() || len1[i] > it->second.len) {
            dp1[xr1[i]] = {len1[i], i};
        }
    }
    
    // 枚举后半
    int sz2 = 1 << down;
    vector<int> xr2(sz2, 0), len2(sz2, 0);
    dp2[0] = {0, 0};
    for (int i = 1; i < sz2; ++i) {
        int low = i & -i;
        int j = __builtin_ctz(low);
        int prev = i ^ low;
        xr2[i] = xr2[prev] ^ parity[halfn + j];
        len2[i] = len2[prev] + len[halfn + j];
        auto it = dp2.find(xr2[i]);
        if (it == dp2.end() || len2[i] > it->second.len) {
            dp2[xr2[i]] = {len2[i], i};
        }
    }
    
    int anslen = 0;
    int best_mask1 = 0, best_mask2 = 0;
    
    // 合并两半
    for (auto &p : dp1) {
        int xr1 = p.first;
        int l1 = p.second.len;
        int m1 = p.second.mask;
        
        // 情况 1: xr1 ^ xr2 == 0  =>  xr2 == xr1
        if (dp2.count(xr1)) {
            int total = l1 + dp2[xr1].len;
            if (total > anslen) {
                anslen = total;
                best_mask1 = m1;
                best_mask2 = dp2[xr1].mask;
            }
        }
        
        // 情况 2: xr1 ^ xr2 == (1 << j)  =>  xr2 == xr1 ^ (1 << j)
        for (int j = 0; j < 26; ++j) {
            int target = xr1 ^ (1 << j);
            if (dp2.count(target)) {
                int total = l1 + dp2[target].len;
                if (total > anslen) {
                    anslen = total;
                    best_mask1 = m1;
                    best_mask2 = dp2[target].mask;
                }
            }
        }
    }
    
    // 按题目要求输出
    if (anslen > 0) {
        cout << "possible\n";
        for (int i = 0; i < n; ++i) {
            if (i < halfn) {
                if (best_mask1 & (1 << i)) cout << s[i];
            } else {
                if (best_mask2 & (1 << (i - halfn))) cout << s[i];
            }
        }
        cout << "\n";
    } else {
        cout << "impossible\n";
    }
    
    return 0;
}