A simple C program that demonstrates how buffer overflows occur when user-controlled input exceeds the allocated memory.

The code shows:
- How overflowing a buffer can overwrite adjacent memory on the stack.
- How misuse of unsafe string/IO functions like sprintf() without bounds can lead to buffer overflows.
- A demonstration of control-flow hijacking by overwriting a return address or function pointer to call an unintended function.
- How compiler protection like stack canaries affect exploitability.
