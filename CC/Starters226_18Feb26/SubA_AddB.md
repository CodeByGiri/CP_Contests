## C.Sub A Add B

### Idea:
We are given a string of length `N`.

We are allowed to repeatedly:

- Choose a substring of length `A`.
- Replace it with a substring of lenght `B`.

Since `B<A`, every operation reduces the string length.

Our goal is to find the final length of string after performing operations optimally.

---

### Key Observation:

Each operation reduces the length by:

$$
A - B
$$

Let:

$$
d = A - B
$$

So each operation does:

$$
N \ge A
$$

Once `N<A`, we can no longer choose a substring of length `A`.

---

### Derived Process 

Keep Subtracting:

$$
A - B
$$

from `N` until:

$$
N < A
$$

That final value of `N` is the answer.

---

### Example:

For:

- `N = 10`
- `A = 5`
- `B = 3`

$$
d = 5 - 3 = 2
$$

Process:

$$
10 \rightarrow 8 \rightarrow 6 \rightarrow 4
$$

Since `4 < 5`, we stop.

Final Answer:

$$
4
$$

---

### Complexity:

We only do arithmetic.

- Time: **O(1)** per test case.
- Memory: **O(1)**.

---

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	while(t--){

        int  N, A, B;
        cin >> N >> A >> B;
        
        long d = A - B;
        
        while(N >= A)
            N-= d;

        cout << N << "\n";
	}
	return  0;
}
```