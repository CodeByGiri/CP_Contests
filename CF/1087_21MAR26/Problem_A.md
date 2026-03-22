## A - Flip Flops

###  Idea
We can only kill monsters whose power ≤ current power `c`.  
If not, we can increase their power using flip-flops (limited k times).

###  Approach
- Sort the array `a`
- Process monsters from smallest to largest
- If `a[i] ≤ c` → kill and increase `c += a[i]`
- Otherwise:
  - If we still have flip-flops → increase `a[i]`
  - Else → stop

Greedy works because:
→ Always kill smallest available monster first

###  Complexity
Time: O(n log n)  
Space: O(1)

###  Code
```cpp
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    long long c, k ;
    cin >> n >> c >> k;

    vector<long long> a(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }

    sort(a.begin(),a.end());
    
    for(int i = 0; i<n; i++){
        if(a[i] <= c){
            long long use = c - a[i]; // no of flip-flops to use
            long long used = min(k, use);

            k -= used; 
            c += (a[i] + used);
        }else{
            break;
        }
    }

    cout << c << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        solve();
    }
    return 0;
}
```