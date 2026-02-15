## Payment Scheme
## Division 4 Problem

### Idea: 
Chef has two payment schemes:

- Scheme 1: To pay `100`coins immediately and pay `X` coins each week for 4 weeks.
- Scheme 2: Pay `300` coins immediately.

Our objective to choose the either of the scheme in such a way the Chef needs to only pain minimum coins in total.

--- 

### Key Observation
The total cost for the both schemes can be directly calculated:

- Scheme 1 total:

$$
100  + 4K
$$

- Scheme 2 total:

$$
300
$$
 
 So we use the `min` function to take the minimum of these.

 ---

 For:

 - `X = 8`

 Scheme 1:

 $$
 100 + 4 \cdot 8 = 132
 $$

 Scheme 2:
 
 $$
 300
 $$

 So as observed, we'll obviously choose the answer as:

 $$
 \min(132,300) = 132
 $$

 --- 

 ### Complexity

 We have **t** test cases.

 - Time: **O(1)** per test case.
 - Memory: **O(1)**

 ---

 ### C++ Implementation:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	int X;
	cin >> X;
	
	cout << min(300, 100 + 4*X) << "\n";
	return 0;
}
```
