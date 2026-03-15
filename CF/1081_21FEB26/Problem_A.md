## A. String Rotation Game

### Idea:

A **block** is defined as a contiguous substring of characters that are the same.

For example, in:

aabcccdaa

The blocks are:

aa | b | ccc | d | aa


Total blocks = **5**.

We are given a string `s` and we can **cyclically rotate** it any number of times.

The goal is to **maximize the number of blocks** in the final string.

---

### Key Observation

The number of blocks in a string depends on how many times **adjacent characters are different**.

If we scan the string and count:

s[i] != s[i-1]

each such position creates a **new block**.

So the total blocks in the string are:

1 + number of adjacent unequal pairs

---

### Important Observation About Rotation

Rotation only affects the **connection between the first and last characters**.

Two cases arise:

1. **If `s[0] != s[n-1]`**

   Rotating cannot merge any blocks, so the block count stays the same.

2. **If `s[0] == s[n-1]`**

   The first and last blocks may merge after rotation, reducing the number of blocks by `1`.

So the maximum blocks we can achieve are:

blocks - 1   (if first and last characters are same) blocks       (otherwise)

---

### Example

For:

s = abbc

Blocks:

a | bb | c

Total = **3**

But by rotating:

bcab

Blocks become:
b | c | a | b

Total = **4**

So rotation can increase the number of blocks.

---

### Complexity

We scan the string once.

- Time Complexity: **O(n)**
- Space Complexity: **O(1)**

---

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        string s;
        cin >> n >> s;

        int circular_diff = 0;
        bool has_equal = false;

        for(int i = 0; i < n; i++){
            if(s[i] != s[(i+1)%n])
                circular_diff++;
            else
                has_equal = true;
        }

        if(has_equal)
            cout << circular_diff + 1 << "\n";
        else
            cout << circular_diff << "\n";
    }
}
```