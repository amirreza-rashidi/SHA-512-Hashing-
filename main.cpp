#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <vector>
using namespace std;
typedef unsigned char uint8;
typedef unsigned long long uint64;

const uint64 K[] = {
        0x428a2f98d728ae22ULL, 0x7137449123ef65cdULL,
        0xb5c0fbcfec4d3b2fULL, 0xe9b5dba58189dbbcULL,
        0x3956c25bf348b538ULL, 0x59f111f1b605d019ULL,
        0x923f82a4af194f9bULL, 0xab1c5ed5da6d8118ULL,
        0xd807aa98a3030242ULL, 0x12835b0145706fbeULL,
        0x243185be4ee4b28cULL, 0x550c7dc3d5ffb4e2ULL,
        0x72be5d74f27b896fULL, 0x80deb1fe3b1696b1ULL,
        0x9bdc06a725c71235ULL, 0xc19bf174cf692694ULL,
        0xe49b69c19ef14ad2ULL, 0xefbe4786384f25e3ULL,
        0x0fc19dc68b8cd5b5ULL, 0x240ca1cc77ac9c65ULL,
        0x2de92c6f592b0275ULL, 0x4a7484aa6ea6e483ULL,
        0x5cb0a9dcbd41fbd4ULL, 0x76f988da831153b5ULL,
        0x983e5152ee66dfabULL, 0xa831c66d2db43210ULL,
        0xb00327c898fb213fULL, 0xbf597fc7beef0ee4ULL,
        0xc6e00bf33da88fc2ULL, 0xd5a79147930aa725ULL,
        0x06ca6351e003826fULL, 0x142929670a0e6e70ULL,
        0x27b70a8546d22ffcULL, 0x2e1b21385c26c926ULL,
        0x4d2c6dfc5ac42aedULL, 0x53380d139d95b3dfULL,
        0x650a73548baf63deULL, 0x766a0abb3c77b2a8ULL,
        0x81c2c92e47edaee6ULL, 0x92722c851482353bULL,
        0xa2bfe8a14cf10364ULL, 0xa81a664bbc423001ULL,
        0xc24b8b70d0f89791ULL, 0xc76c51a30654be30ULL,
        0xd192e819d6ef5218ULL, 0xd69906245565a910ULL,
        0xf40e35855771202aULL, 0x106aa07032bbd1b8ULL,
        0x19a4c116b8d2d0c8ULL, 0x1e376c085141ab53ULL,
        0x2748774cdf8eeb99ULL, 0x34b0bcb5e19b48a8ULL,
        0x391c0cb3c5c95a63ULL, 0x4ed8aa4ae3418acbULL,
        0x5b9cca4f7763e373ULL, 0x682e6ff3d6b2b8a3ULL,
        0x748f82ee5defb2fcULL, 0x78a5636f43172f60ULL,
        0x84c87814a1f0ab72ULL, 0x8cc702081a6439ecULL,
        0x90befffa23631e28ULL, 0xa4506cebde82bde9ULL,
        0xbef9a3f7b2c67915ULL, 0xc67178f2e372532bULL,
        0xca273eceea26619cULL, 0xd186b8c721c0c207ULL,
        0xeada7dd6cde0eb1eULL, 0xf57d4f7fee6ed178ULL,
        0x06f067aa72176fbaULL, 0x0a637dc5a2c898a6ULL,
        0x113f9804bef90daeULL, 0x1b710b35131c471bULL,
        0x28db77f523047d84ULL, 0x32caab7b40c72493ULL,
        0x3c9ebe0a15c9bebcULL, 0x431d67c49c100d4cULL,
        0x4cc5d4becb3e42b6ULL, 0x597f299cfc657e2aULL,
        0x5fcb6fab3ad6faecULL, 0x6c44198c4a475817ULL
};

inline uint64 rotr(uint64 x, uint64 n) {
    return (x >> n) | (x << (64 - n));
}

inline uint64 shr(uint64 x, uint64 n) {
    return x >> n;
}

inline uint64 Ch(uint64 x, uint64 y, uint64 z) {
    return (x & y) ^ (~x & z);
}

inline uint64 Maj(uint64 x, uint64 y, uint64 z) {
    return (x & y) ^ (x & z) ^ (y & z);
}

inline uint64 Sigma0(uint64 x) {
    return rotr(x, 28) ^ rotr(x, 34) ^ rotr(x, 39);
}

inline uint64 Sigma1(uint64 x) {
    return rotr(x, 14) ^ rotr(x, 18) ^ rotr(x, 41);
}

inline uint64 sigma0(uint64 x) {
    return rotr(x, 1) ^ rotr(x, 8) ^ shr(x, 7);
}

inline uint64 sigma1(uint64 x) {
    return rotr(x, 19) ^ rotr(x, 61) ^ shr(x, 6);
}

string sha512(const string& message) {
    uint64 h[] = {
            0x6a09e667f3bcc908ULL, 0xbb67ae8584caa73bULL,
            0x3c6ef372fe94f82bULL, 0xa54ff53a5f1d36f1ULL,
            0x510e527fade682d1ULL, 0x9b05688c2b3e6c1fULL,
            0x1f83d9abfb41bd6bULL, 0x5be0cd19137e2179ULL
    };

    vector<uint8> data(message.begin(), message.end());
    data.push_back(0x80);
    while ((data.size() + 16) % 128 != 0) {
        data.push_back(0);
    }

    uint64 bitsLen = message.size() * 8;
    for (int i = 15; i >= 0; --i) {
        data.push_back((bitsLen >> (i * 8)) & 0xff);
    }

    for (size_t i = 0; i < data.size(); i += 128) {
        uint64 w[80];
        for (int j = 0; j < 16; ++j) {
            w[j] = 0;
            for (int k = 0; k < 8; ++k) {
                w[j] = (w[j] << 8) | data[i + j * 8 + k];
            }
        }
        for (int j = 16; j < 80; ++j) {
            w[j] = sigma1(w[j - 2]) + w[j - 7] + sigma0(w[j - 15]) + w[j - 16];
        }

        uint64 a = h[0], b = h[1], c = h[2], d = h[3];
        uint64 e = h[4], f = h[5], g = h[6], h_ = h[7];

        for (int j = 0; j < 80; ++j) {
            uint64 T1 = h_ + Sigma1(e) + Ch(e, f, g) + K[j] + w[j];
            uint64 T2 = Sigma0(a) + Maj(a, b, c);
            h_ = g;
            g = f;
            f = e;
            e = d + T1;
            d = c;
            c = b;
            b = a;
            a = T1 + T2;
        }

        h[0] += a; h[1] += b; h[2] += c; h[3] += d;
        h[4] += e; h[5] += f; h[6] += g; h[7] += h_;
    }

    stringstream ss;
    for (int i = 0; i < 8; ++i) {
        ss << hex << setfill('0') << setw(16) << h[i];
    }
    return ss.str();
}

int main() {
    string input;
    cout << "please enter password or text:\n> ";
    getline(cin, input);

    string hash = sha512(input);
    cout << "\n SHA-512:\n" << hash << endl;

    return 0;
}
