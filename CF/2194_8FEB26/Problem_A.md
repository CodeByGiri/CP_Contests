## A.Lawn Mower

### Idea:
We have 'n' fence boards.
A lawn mower of width **w** escapes if there are **w consecutive removed boards in the fence.**

So our objective is to remove maximum no of boards possible without leaving a gap of `w` consecutive boards.

----

### Key Observation
Since w consecutive boards cannot be removed, the maximum safe consecutive removal we can execute is:

\[
w-1 boards
\]

The Pattern:

The best pattern I derived to implement this maximum removal of w-1 is by

- split the fences into groups of `w`
- remove `w-1` consecutive from each group
- keep `1` board in each group.

By this way, I can make sure maximum no of consecutive boards are removed and atleast one is retained so not for the lawnmower to escape.

---

### Derived Formula

$$
ans = n - \left\lfloor \frac{n}{w} \right\rfloor
$$


---

### Example

For:

- `n = 9`
- `w = 3`

$$
ans = 9 - \left\lfloor \frac{9}{3} \right\rfloor = 9 - 3 = 6
$$


--- 

### Complexity

We have **t** test cases.

- Time: **O(1)** per test case.
- Memory: **O(1)**


---

### C++ Implementation 


```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >>t;

	while(t--){
    		long long n,w;
    		cin >> n >> w;

    		cout << n-(n/w) << "\n";
	}

	return 0;
}
```

