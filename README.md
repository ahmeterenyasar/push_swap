*This project has been created as part of the 42 curriculum by ayasar.*

# Push_swap

## Description

Push_swap is a sorting project built around a deliberately minimal toolset. Given a list of integers, the program must produce the shortest reasonable sequence of stack instructions that arranges those integers in ascending order — and nothing else. The score of the project is not whether the data ends up sorted, but *how few moves* it took to get there.

The problem is framed around two stacks:

- **Stack A** holds the unsorted integers passed as arguments.
- **Stack B** starts empty and is used as scratch space during sorting.

Only a fixed instruction set is permitted to move data between and within these stacks:

| Instruction | Effect |
|-------------|--------|
| `sa` / `sb` / `ss` | Swap the top two elements of A / B / both |
| `pa` / `pb` | Push the top of one stack onto the other |
| `ra` / `rb` / `rr` | Rotate A / B / both upward (top goes to bottom) |
| `rra` / `rrb` / `rrr` | Rotate A / B / both downward (bottom goes to top) |

The program reads the integers, computes a valid ordering sequence, and prints those instructions to standard output, one per line. It never sorts the data "out loud" — it only emits the moves a checker could replay to reproduce the sort.

### Technical choice: indexed radix sort

A naive radix sort on raw integers runs into two problems immediately: negative values break the assumption that bits map cleanly onto magnitude, and large values waste passes on high-order bits that almost no element actually uses. Both issues are sidestepped by **normalizing the input before sorting**.

1. **Indexing.** Each input value is replaced by its rank — its position in the sorted order, from `0` to `N-1`. This is an order-preserving transformation, so any sequence of moves that sorts the ranks also sorts the original values. It collapses the value range to exactly `N`, removes negatives entirely, and bounds the number of significant bits to `ceil(log2(N))`.

2. **Bitwise partitioning.** The sort then runs base-2 LSD radix over the ranks. For each bit, every element currently in A is inspected once: if the bit is `0` the element is pushed to B, if the bit is `1` it is rotated to the bottom of A. After the pass, B is emptied back onto A. Because the push/pop pairing is order-stable, each pass preserves the relative order established by previous passes, which is exactly what LSD radix requires.

3. **Small-stack shortcut.** For five elements or fewer, radix is wasteful relative to the hard move limits for those sizes. These cases are handled by a dedicated routine: a hardcoded three-element sort, extended for four and five elements by isolating the smallest ranks in B, sorting the remainder, and pushing them back. This guarantees the small-input cases stay well within their limits.

The result is a sort whose emitted move count grows on the order of `O(N log N)`, with no risk of overflow or undefined behavior from manipulating negative binary values, since the radix stage only ever operates on non-negative ranks.

---

## Instructions

### Compilation

From the root of the repository:

```bash
make
```

If a Makefile is not present, the sources can be compiled directly with the standard flags:

```bash
gcc -Wall -Wextra -Werror *.c -o push_swap
```

### Execution

Pass the integers to sort as command-line arguments. They may be given as separate arguments or grouped inside a single quoted string:

```bash
./push_swap 34 16 4 52 23
./push_swap "34 16 4 52 23"
```

The program prints the sequence of instructions needed to sort Stack A, one instruction per line:

```text
pb
pb
sa
pa
pa
```

If the input is already sorted, or no arguments are given, the program prints nothing and exits cleanly. Invalid input — non-numeric arguments, values outside the signed 32-bit integer range, or duplicates — results in `Error` printed to standard error and a non-zero exit status.

To verify the output, the instruction stream can be piped into the official `checker` program:

```bash
ARG="34 16 4 52 23"; ./push_swap $ARG | ./checker $ARG
```

---

## Resources

The references below cover the algorithmic background and the mechanics of the stacks:

- [Radix sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort) — the LSD base-2 logic applied to the indexed values.
- [Counting / rank-based indexing](https://en.wikipedia.org/wiki/Counting_sort) — background for the order-preserving normalization step.
- [Push_swap: the least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) — a clear walkthrough of the stack rules and move semantics.

### AI usage

AI was used in a limited, advisory capacity — as a sounding board rather than an author. Specifically, it was consulted to discuss the trade-offs of choosing radix sort over chunk-based approaches and to confirm where it sits on the project's move-count expectations, to point toward relevant reference material on the radix and indexing techniques listed above, and for a readability and Norminette review pass over already-written code. The core algorithm, the indexing strategy, and the implementation itself were designed and written without AI-generated logic.