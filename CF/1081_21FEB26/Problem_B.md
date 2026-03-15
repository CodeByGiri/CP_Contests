## B. Binary String Flip

### Idea:

We are given a binary string `s` of length `n`.

We can perform the following operation:

- Choose an index `i`
- Flip every bit **except** the bit at index `i`

That means for every `j ≠ i`:

$$
0 → 1
1 → 0
$$

Each index can be chosen **at most once**.

Our goal is to make **all bits equal to `0`**.

---

### Key Observation

Instead of simulating every operation, we analyze how many times each position is flipped.

Suppose we perform `x` operations.

For any position `j`:

- If index `j` **was chosen**, it gets flipped `x − 1` times.
- If index `j` **was not chosen**, it gets flipped `x` times.

To end with `0`, we must satisfy:

- If original bit is **1**, it must flip **odd** number of times.
- If original bit is **0**, it must flip **even** number of times.

---

### Two Possible Strategies

Let:

**c1 = number of '1's c0 = number of '0's**

#### Case 1: `c1` is even

Choose **all indices containing `1`**.

Then:

- Those positions flip `c1 - 1` times → odd
- Other positions flip `c1` times → even

So all bits become `0`.

---

#### Case 2: `c0` is odd

Choose **all indices containing `0`**.

Then:

- Chosen positions flip `c0 - 1` times → even
- Other positions flip `c0` times → odd

Again all bits become `0`.

---

#### Otherwise

It is **impossible**.

---

### Example

For:
$$
s = 101

So,
c1 = 2 
c0 = 1
$$

Since `c1` is even, choose indices of `1`:
** 1 3 **

Operations = 2.

Final string becomes:

**000**
---

### Complexity

We scan the string once.

- Time Complexity: **O(n)**
- Space Complexity: **O(n)**

---

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;  

    int c1 = 0, c0 = 0;
    for(char c : s){
        if (c=='1') c1++;
        else c0++;
    }
    if (c1 % 2 == 0){
        cout << c1 << "\n";
        for(int i=0 ; i<n ; i++){
            if (s[i] == '1'){
                cout << i+1 << " ";
            }
        }
        cout << "\n";
    }

    else if (c0 % 2 != 0){
        cout << c0 << "\n";
        for(int i = 0; i<n ; i++){
            if(s[i] == '0'){
                cout << i+1 << " ";
            }
        }
        cout << "\n";
    }

    else{
        cout << -1 << "\n";
    }
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