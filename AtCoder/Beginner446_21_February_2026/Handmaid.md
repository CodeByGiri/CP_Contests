## A. Handmaid

### Idea:

We are given a string `S` representing a person's name.

- The first character of `S` is an **uppercase English letter**.
- The remaining characters are **lowercase English letters**.

The name of the person's **handmaid** is constructed by:

1. Converting the **first character** of `S` to **lowercase**.
2. Adding the string `"of"` to the **beginning**.
3. Keeping the rest of the string unchanged.

---

### Key Observation

Only the **first character** needs to be modified.

Steps:

1. Convert `S[0]` to lowercase.
2. Print `"of"` followed by the modified string.

In C++, this can be done using:

```
tolower(S[0])
```

---

### Example

For:

```
S = Glen
```

Steps:

Convert first letter:

```
glen
```

Add `"of"` to the beginning:

```
ofglen
```

Output:

```
ofglen
```

---

### Complexity

The string length is at most **10**, so the operations are constant.

- Time: **O(|S|)**
- Space: **O(1)**

---

### C++ Implementation

```cpp
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
    string s;
    cin >> s;

    s[0] = tolower(s[0]);

    cout<< "Of" << s << "\n";

    return 0;
}
```