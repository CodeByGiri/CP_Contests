## All Even

### Idea:
We have an array of `n` numbers.

In one operation:
- Add the last element to the second last element.
- Remove the last element.

Our objective is to check whether the array is such that after some operations, is it possible to land in an array that only contains even numbers.

---

### Key Observation
This works greatly on the property of parity (odd/even):

- Even + Even = Even
- Even + Odd = Odd
- Odd + Odd = Even

So if u observe, no of even elements in the array doesn't matter, an addition operation containing an odd number can only give out even answer if both of the operands are odd. i.e, odd numbers can only disappear in pairs.

Therefore, the array can become all even iff the number of odd elements in the array is even.

---

### Derived Condition

$$
\text{Answer is YES if oddCount is even}
$$

---

### Example

Array:
[1,5,2,6]

Odd numbers = 2

Since 2 is even, answer is **YES**.

---

### Complexity:

We have **t** test cases.

- Time: **O(n)** per test case.
- Space: **O(1)** 

---

### C++ Implementation:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin >> n;
	    
	    int odd = 0;
	    for(int i=0;i<n;i++){
	        long long x;
	        cin >> x;
	        if (x % 2 != 0) odd++;
	    }
	    
	    if(odd%2 == 0) cout << "YES" << "\n";
	    else cout << "NO" << "\n";
	}

}
```
