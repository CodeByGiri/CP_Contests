## C. All-in-one Gun

### Idea:

We have a gun with `n` bullets.  
The `i-th` bullet deals damage `aᵢ`.

The enemy has `h` health and dies when health becomes `≤ 0`.

Rules:

- The gun fires **one bullet per second**.
- After firing all `n` bullets, the gun **reloads for `k` seconds**.
- After reloading, the **same sequence of bullets repeats**.
- Before the fight, we can perform **at most one swap** between two bullets.

Our goal is to **minimize the time required to kill the enemy**.

---

### Key Observation

Bullets are fired in a **fixed repeating sequence**.

So damage is dealt in **cycles**:

**cycle damage = a₁ + a₂ + ... + aₙ**

Each cycle takes:

**n + k seconds**

(except the last one which may stop early).

---

### Important Observation About the Swap

Since we can perform **at most one swap**, the best strategy is:

- Move a **large damage bullet earlier** in the sequence.

This increases the **prefix damage**, which may allow the enemy to die **before finishing a full cycle**, saving reload time.

---

### Strategy

1. Compute the **prefix sums** of damage.
2. Check the earliest position where cumulative damage ≥ `h`.
3. If the enemy is not killed in one cycle:
   - Compute how many **full cycles** are needed.
   - Add the time for those cycles.
4. Try performing **one swap** to bring the maximum damage bullet earlier.
5. Recompute the earliest kill time and take the **minimum possible time**.

---

### Example

For:
$$
n = 5 h = 10 k = 1
a = [4, 2, 3, 5, 3]
$$

Swap positions `2` and `5`:
$$
[4, 3, 3, 5, 2]
$$
Now cumulative damage:

$$
4 → 7 → 10
$$

Enemy dies in **3 seconds**.

---

### Complexity

For each test case:

- Processing bullets: **O(n)**
- Trying optimal swap: **O(n)**

Overall complexity:
O(n)

This works within the constraint:

Σ n ≤ 2 × 10⁵
---

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, h, k;
    cin >> n >> h >> k;

    vector<long long> a(n);
    long long S = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        S += a[i];
    }

    long long cycles = (h - 1) / S;
    long long rem = h - cycles * S;

    vector<long long> P(n);
    vector<long long> min_in(n);
    P[0] = a[0];
    min_in[0] = a[0];
    
    for (int i = 1; i < n; i++) {
        P[i] = P[i - 1] + a[i];
        min_in[i] = min(min_in[i - 1], a[i]);
    }

    vector<long long> max_out(n, 0);
    if (n > 1) {
        max_out[n - 2] = a[n - 1];
        for (int i = n - 3; i >= 0; i--) {
            max_out[i] = max(max_out[i + 1], a[i + 1]);
        }
    }

    long long best_m = n;
    for (int m = 0; m < n; m++) {
        long long max_sum = P[m];
        
        if (m < n - 1) {
            max_sum = max(max_sum, P[m] - min_in[m] + max_out[m]);
        }
        
        if (max_sum >= rem) {
            best_m = m + 1; 
            break;
        }
    }

    long long ans = cycles * (n + k) + best_m;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
```