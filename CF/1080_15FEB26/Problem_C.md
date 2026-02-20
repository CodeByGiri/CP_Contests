## C. Dice Roll Sequence

### Idea:
We are given an array `a` of length `n`, where each element is between
`1` and `6`.

A sequence is called a **dice roll sequence** if every adjacent pair satisfies:

- They are on **adjacent faces** of the dice
- They are **not the same**
- They are **not opposite**

On a dice, opposite faces are:

$$
(1,6), (2,5), (3,4)
$$

We can change any  element `a[i]` into any value `1..6` in one operation.

Our goal is to find the **minimum number of changes** required to make the whole array **valid**.

---

### Key Observation

For two adjacent values `x` and `y`:

They are valid neighbors if:

- \(x \neq y\)
- \(x + y \neq 7\)

Because opposite faces always sum to 7.

So the condition becomes:

$$
valid(x,y) = (x \neq y) \ \text{and}\ (x+y \neq 7)
$$

---

### DP Approach

Since values have a fixed set of values, i.e, `1` to `6`, we can use DP with only **6 states**.

Let:

$$
dp[v] = \text{minimum operations so far if the current value is } v
$$

At each position `i`, we try assigning `a[i]` to some value `v`.

Cost:

- If `v == a[i]`, cost = 0
- Else, cost = 1

Transition:

From previous value `u` to current value `v`:

Only allowed if:

$$
valid(u,v)
$$

So:

$$
newdp[v] = \min(newdp[v], dp[u] + cost)
$$

---

### Initialization

$$
dp[v] = (v == a[1] ?  0 : 1)
$$

---

### Final Answer

After processing elements:

$$
ans = \min(dp[1..6])
$$

### Example

Array:

$$
[3,4,6,3]
$$

The pair `(4,6)` is invalid because:

$$
4+6=10 \neq 7 \quad \text{but they are opposite? Actually 3 and 4 are opposite.}
$$

The best fix is changing one value, so answer is:

$$
1
$$

--- 

### Complexity

For each index:

- We try 6 possible values
- We transition from 6 previous values

So:

$$
O(n \cdot 6 \cdot6) = O(n)
$$

Memory:

$$
O(6)
$$

---

### C++ Implementation

```cpp
#include<bits/stdc++.h>
using namespace std;

bool ok(int x, int y){
    if(x == y) return false;
    if (x+y == 7) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i=0 ; i<n ; i++) cin >> a[i];

        const int INF = 1e9;

        vector<int> dp(7, INF);

        for(int v = 1; v <= 6 ; v++){
            if(a[0] == v) dp[v] = 0;

            else dp[v] = 1;
        }

        for(int i = 1; i<n ; i++){
            vector<int> newdp(7,INF);

            for(int v = 1; v<=6 ; v++){
                int cost = (a[i] == v ? 0 : 1);

                for(int u = 1; u<=6 ; u++){
                    if(ok(u,v)){
                        newdp[v] = min(newdp[v], dp[u] + cost);
                    }
                }
            }
            dp = newdp;
        }

        int ans = INF;
        for(int v = 1; v<=6 ; v++){
            ans = min(ans, dp[v]);
        }
        cout << ans << "\n";
    }
}
```