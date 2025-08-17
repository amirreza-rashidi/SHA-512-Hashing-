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

## ▶️ Usage
```bash
./sha512
please enter password or text that you want to hashing here :
> abc
# output:
# SHA-512 hash is :
# ddaf35a193617abacc417349ae20413112e6fa4e89a97ea20a9eeee64b55d39a
# 2192992a274fc1a836ba3c23a3feebbd454d4423643ce80e2a9ac94fa54ca49f

## 🧠 How it works (high level)
- ✍ Converts input → bytes, applies **SHA-512 padding** (`0x80`, zeros, 128-bit length).  
- 📦 Splits into **1024-bit chunks** → expands to 80 words.  
- 🔁 Runs compression rounds with `Ch`, `Maj`, `Σ0/Σ1`, `σ0/σ1`, and constants `K`.  
- 🧮 Accumulates state (**8×64-bit**) → prints **512-bit digest** as hex.  

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
