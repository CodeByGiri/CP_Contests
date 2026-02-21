## B. Ice Cream

### Idea:
Chef has `X` grams of icecream.

Every minute, `Y` gram of it melts.

Chef returns after `N` minutes.

We need to find how much icecream remains.

---

### Key Observation

Total Melted in `N` minutes:

$$
Y \times N
$$

Remaining ice cream:

$$
X - (Y \times N)
$$

Since ice cream can't go below 0, the final answer is:

$$
\max(0 \; X - YN)
$$

---

### Example

Input: 5 1 7

Total Melted:

$$
1 \times 7 = 7
$$

Remaining:

$$
5 - 7 = -2
$$

Since negative not allowed, output:

$$
0
$$

---

### Complexity

- Time: **O(1)**
- Memory: **O(1)**

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

        int X,Y,N;
        cin >> X >> Y >> N;

        cout << max(0, X - Y*N) << "\n";
	}

}
```