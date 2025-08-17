# 🔐 SHA-512 Hashing in C++


A minimal, header-only **C++ implementation** of the **SHA-512 cryptographic hash function**.  
No external dependencies—just the standard library. 🚀  
Perfect for **learning how SHA-512 works end-to-end**.

---

## ✨ Features
- ⚡ **Pure C++** (only `<vector>`, `<string>`, `<iostream>`, etc.).  
- 🔄 Full **SHA-512 padding, 1024-bit blocks, 80-round compression** with constants `K`.  
- 🖥 **Simple CLI**: input text → get 128-char SHA-512 hex digest.  


---

## ✅ Known Test Vector
- Input: `abc`  
- Output:  
ddaf35a193617abacc417349ae20413112e6fa4e89a97ea20a9eeee64b55d39a
2192992a274fc1a836ba3c23a3feebbd454d4423643ce80e2a9ac94fa54ca49f

✔ Matches program output above!

---

## ⚠️ Security Notes
This project is **educational**.  
It does *not* include constant-time logic or side-channel protections, and it hasn’t been audited.  
👉 Don’t use in production to protect real secrets.  

---

<p align="center"> Made with ❤️ in C++ </p>
