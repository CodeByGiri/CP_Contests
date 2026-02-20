## B. Heapify  1

### Idea:
We are given a permutation of length `n`.

We can perform the operation:

- Choose an index `i` such that:

$$
1 \le i \le \lfloor n/2 \rfloor
$$

- Swap:

$$
a[i] \leftrightarrow a[2i]
$$

We need to check if it is possible to sort the permutation into:

$$
[1,2,3,\dots,n]
$$

---

### Key Observation:

Index `i` can only swap with its double `2i`.

So elements can only move inside a connected group:

$$
x,\;2x,\;4x,\;8x,\dots
$$

Therefore, all the elements that can be swapped with each other should be all part of the same component. i.e, all these indices share the same **odd part**.

Example:

- 3 -> 3
- 6 -> 3
- 12 -> 3

So index `i` and value `a[i]` must belong to the same group.

That means:

$$
oddPart(i) = oddPart(a[i])
$$

Otherwise, the element can never reach its correct position.

---

### Odd Part Definition

To get the odd part of a number:

- Remove all factors of 2

Example:

- oddPart(12) = 3
- oddPart(8) = 1

Fast Computation:

$$
oddPart(x) = x >> ctz(x)
$$

---

### Condition for Sorting

For every position:

$$
oddPart(i) = oddPart(a[i])
$$

If this holds for all `i`, answer is **YES**.

Otherwise, **NO**.

---

### Example

Permutation:

$$
[1,4,3,2,5]
$$

At index 2:

- oddPart(2) = 1
- oddPart(4) = 1

So it is valid, and sorting is possible.

Answer: **YES**

---

### Complexity

We check each index once.

- Time: **O(n)**
- Memory: **O(1)**

### C++ Implementation

```cpp
#include<bits/stdc++.h>
using namespace std;

int odd(int x){
    return x >> __builtin_ctz(x);
}


int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
int t;
cin >> t;

while(t--){
    int n;
    cin >> n;
    vector<int> a(n+1);

    for(int i=1 ; i<=n ; i++) cin >> a[i];

    bool ok = true;
    for(int i=0 ; i<=n ; i++){
        if(odd(i) != odd(a[i])){
            ok = false;
            break;
        }
    }

    cout << (ok? "YES\n" : "NO\n");
}
}
```