## A.Sieve of Erato67henes

### Idea:
We are given `n` numbers.

We need to check if it possible to select **some non-empty subset** of them such that:

\[
    product = 67
\]

Note: We can choose any no of elements, starting from 1 but not zero.

---

### Key Observation:

67 is a prime number.

So the only possible factors for the no are `1` and `67`.

Therefore, the ways in which we can make the product 67 is :

- Choose the element `67` itself.
- Choose the element `1` and `67` together.
- Choose multiple occurences of `1` and `67` together.

But since all the numbers are between `1` and `67`, the only valid subset must contain:

- Exactly one `67`
- Any number of `1`s

So the answer is :

**YES** if the array contains 67.
**NO** otherwise.

---

### Example:

\[
[1,7,6,7,67,5]
\]

\[
    1 \times 67 = 67
\]

So, the answer is **YES**.

---

### Complexity

We check the array once.

- Time: **O(n)**
- Space: **O(1)**

---
