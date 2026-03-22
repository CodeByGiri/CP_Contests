## FONTA

### Idea:

A drink is called **fanta-like** if the last three characters of its name are:

nta

We are given a string `S` of length `5` representing the drink name.

Our task is to check whether the drink name **ends with "nta"**.

---

### Key Observation

Since the string length is fixed (`5`), the last three characters start at index `2`.

So we simply check:
$$
S.substr(2,3)
$$

If this substring equals `"nta"`, the drink is **fanta-like**.

---

### Example

For:

S = fanta

Last three characters: 

**nta**

So answer is:
**YES**

---

### Complexity

The string size is constant.

- Time Complexity: **O(1)**
- Space Complexity: **O(1)**

---

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    
    if(s.substr(2,3) == "nta") cout << "Yes\n";
    else cout << "NO\n";
    
    return 0;
}
```