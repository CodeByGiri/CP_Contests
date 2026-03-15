## D. Max Straight

### Idea:

We are given an integer sequence:

A = (A₁, A₂, ..., Aₙ)

We must find the **maximum length of a subsequence B** such that:


This means every next element in the subsequence must be exactly **1 greater than the previous element.**

So the subsequence must look like:

99 Ask ChatGPT
We must find the **maximum length of a subsequence B** such that:

$$
Bᵢ + 1 = Bᵢ₊₁
$$

This means every next element in the subsequence must be exactly **1 greater than the previous element.**

So the subsequence must look like:

$$
x, x+1, x+2, x+3 ...
$$

### Key Observation

Since the elements of the subsequence must increase by exactly 1, we only care about *how many times each number appears*.

If we know the longest chain ending at value x, then:

dp[x] = dp[x-1] + 1

because we can extend the sequence ending at x-1 by adding x.

If x-1 does not exist yet, the chain simply starts at x.

---

### Strategy

We use a *hash map (or unordered_map)* to store the longest subsequence length ending at each value.

For each element x in the array:

1. Look at the chain ending at x-1
2. Extend it by adding x

dp[x] = dp[x-1] + 1

3. Keep track of the *maximum value of dp[x]*.

This gives the length of the longest valid subsequence.

---

### Example

For:
$$
A = [3,4,3,5,7,6,2]
$$
Possible subsequence:

**3 → 4 → 5 → 6**

Length: 4

No longer subsequence exists, so the answer is 4.

---

### Complexity

We process each element once.

- Time Complexity: *O(N)*
- Space Complexity: *O(N)*

This works within the constraint N ≤ 2 × 10⁵.

---

### C++ Implementation

```cpp
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if(!(cin >> N)) return 0;

    map<int,int> dp;
    int max_len = 0;

    for(int i =0; i < N; i++){
        int x;
        cin >> x;

        dp[x] = max(dp[x] , dp[x-1] + 1);
        
        max_len = max(max_len, dp[x]);
    }

    cout << max_len << "\n";

    return 0;
}
```
