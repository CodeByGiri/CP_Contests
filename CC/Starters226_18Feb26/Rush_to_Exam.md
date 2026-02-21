## A. Rush to Exam

### Idea:
Chef has:

- `N` hours before the exam
- `M` pages to be read.
- Reading spread of `A` pages per hour

We need to check whether Chef has finished all pages before the exam.

---

### Key Observation

In `N` hours, Chef can read:

$$
N \times A
$$

If this value is greater than or equal to `M`, then Chef can finish reading.

So the condition becomes:

$$
N \times A \ge M
$$

---

### Example
Input:
[3,6,2]

Chef can read:

$$
3 \times 2 = 6
$$

Since `6 >= 6`, the answer is:
**YES**

---

### Complexity

- Time: **O(1)**
- Complexity: **O(1)**

---

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int N, M, A;
    cin >> N >> M >> A;

    if(N * A >= M)
        cout << "Yes\n";
    else
        cout << "No\n";
        
    return 0;
}
```