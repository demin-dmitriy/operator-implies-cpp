# Implication Operator For C++

# Features
- Binary operator, no extra parentheses required
- Short-circuit evaluation (that is: if *premise* is false, then *conclusion* expression is not evaluated)
- Right associative
- Correct precedence (except single case when it is on the left of ternary operator, see below)
- No overhead from library
- Works in constexpr expressions

# Example
```cpp
assert(a implies b);
```

# Issues

Operator `implies` is implemented as a macro. Internally, it abuses operators `||` and `?:`. It works perfectly in
almost all situations conceivable, except single case where it is the left argument of the ternary operator `?:`.

```cpp
(a implies b) ? "true case" : "false case" // parentheses are required here
```

Luckily, if you miss parentheses in this case, you are guaranteed to get a compile error (which is great, because
you don't want your compiler to silently compile incorrect code).

I believe it's the only issue of this implementation. Unfortunately, it's probably unavoidable without making other trade-offs.
