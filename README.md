 SHA-512 Hashing in C++



A minimal, header-only C++ implementation of the SHA-512 cryptographic hash function.

No external dependencies—just the standard library. Ideal for learning how SHA-512 works end-to-end.



✨ Features



Pure C++ (uses only <vector>, <string>, <iostream>, etc.). 



Complete SHA-512 message padding, 1024-bit block processing, and 80-round compression with standard constants K. 



Simple CLI: enter any text and get its SHA-512 digest in hex. 



▶️ Usage

./sha512

please enter password or text that you want to hashing here :

> abc

\# output:

\# SHA-512 hash is :

\# ddaf35a193617abacc417349ae20413112e6fa4e89a97ea20a9eeee64b55d39a

\# 2192992a274fc1a836ba3c23a3feebbd454d4423643ce80e2a9ac94fa54ca49f





(The program prompts for input and prints the 128-hex-char digest.)

