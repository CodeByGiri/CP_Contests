## Tournament Coins (Lose atleast once)

### Idea:
Chef fights `n` opponents.

- If chef wins match `i`, he earns `A[i]` coins.
- If chef loses match `i`, he loses `B[i]` coins.

It is given that the chef is bound to lose atleast one match.

Therefore, our objective is to maximize the winnings. i.e, maximum total coins earned.

---

### Key Observations:
If chef wins all matches:

$$
total = \sum A[i]
$$

But chef must lose exactly one match, so we should choose the match where there is minimum reduction.

Loss in match `i`:

$$
A[i] - B[i]
$$

So, we subtract the minimum loss.

---

### Derived Formula:
$$
ans = \sumA[i] - \min(A[i] - B[i])
$$

---

### Example:

Banks:

- `A= [10,8,6]`
- `B=[5,7,1]`

Total if all wins:

$$
10 + 8 + 6 = 24
$$

Loss values:

- `10 - 5 = 5`
- `8 - 7 = 1`
- `6 - 1 = 5`

Minimum loss = 1

Final Answer:

$$
24 - 1 = 23
$$

---

### Complexity

We have **t** test cases.

- Time: **O(n)** per test case
- Space: **O(n)**

---
