## Problem 2. All Even

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


