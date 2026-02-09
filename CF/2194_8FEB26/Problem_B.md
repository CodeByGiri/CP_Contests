## Problem B.Offshores

### Idea:

We have n banks with balances `a[i]`.

A transfer here works under some specific conditions:

We remove exactly x rubles from one bank.  
The other bank will only receive only y rubles and is considered to be as a fee.  

So after each transfer, there is a loss of:

$$
x - y
$$

The objective of the problem is to maximize the amount of money that can end up in a **single bank**.

---

### Key Observation

A bank with `a[i]` rubles can only donate money in groups of x rubles. i.e, In chunks of size x each.

Therefore, the no of chunks we can transfer from a bank i is :

$$
chunks[i] = \left\lfloor \frac{a[i]}{x} \right\rfloor
$$

So with the help of this formula, we can identify the total number of chunks available by adding them in a variable **totalChunks** as we traverse through different banks `a[i]`

Total available chunks in the system for transfer:

$$
totalChunks = \sum chunks[i]
$$

---

### Choosing the Final Bank

Suppose we choose a bank i as the receiver.

The money accumulated in this bank is given as follows:

It retains its money : `a[i]`  
All the other banks transfer their chunks into this.  

Therefore, removing the no of chunks of the receiver bank from the totalChunks, the number of chunks coming in from other banks will be:

$$
totalChunks - chunks[i]
$$

Each chunk adds y rubles, so final money in the receiver bank i becomes:

$$
a[i] + (totalChunks - chunks[i]) \cdot y
$$

We compute this value for every bank and then whichever gives the maximum, we return it.

---

### Example

Banks:


x=5,y=4

Chunks:

- 10/5 = 2  
- 9/5 = 1  
- 8/5 = 1  
- 7/5 = 1  

So:

$$
totalChunks = 5
$$

Now, if we take bank with 9 as receiver:

$$
9 + (5-1)\cdot 4 = 25
$$

So the answer is **25**.

---

### Complexity:

We have **t** test cases.

Time: **O(n)** per test case.  
Space: **O(n)**

---

### C++ Implementation:

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        int n;
        long long x,y;
        cin >> n >> x >> y;

        vector<long long> a(n) , chunks(n);
        long long totalChunks = 0;

        for(int i = 0; i<n ; i++){
            cin >> a[i];
            chunks[i] = a[i]/x;
            totalChunks += chunks[i];
        }

        long long ans = 0;
        for(int i=0; i<n ; i++){
            ans = max(ans,a[i]+(totalChunks - chunks[i])*y);
        }

        cout << ans <<  "\n";
    }

    return 0;
}
```
