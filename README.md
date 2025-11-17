# buffer-overflow-c

A simple C program that demonstrates how buffer overflows occur when user-controlled input exceeds the allocated memory.

The code shows:
- How overflowing a buffer can overwrite adjacent memory on the stack
- Common vulnerable patterns such as use of sprintf()
- How compilers and protections (stack canaries) affect exploitability
