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



🧠 How it works (high level)



Converts input to bytes, applies SHA-512 padding (append 0x80, then zeros, then 128-bit length).



Processes 1024-bit chunks: expands to 80 words, then runs the compression rounds using Ch, Maj, Σ0/Σ1, σ0/σ1, and the 80 constants K.



Accumulates state (8×64-bit) and prints the final 512-bit digest as hex.



✅ Known Test Vector



Input: abc



SHA-512:

ddaf35a193617abacc417349ae20413112e6fa4e89a97ea20a9eeee64b55d39a2192992a274fc1a836ba3c23a3feebbd454d4423643ce80e2a9ac94fa54ca49f



(Matches program output above.)

⚠️ Security Notes



This code is primarily for learning. It does not implement constant-time I/O or side-channel mitigations and hasn’t undergone formal cryptographic review. Don’t use it as-is to protect real secrets.





