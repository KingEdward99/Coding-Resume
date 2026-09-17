e = 43
p = 83
q = 13
n = p * q

c = [
    996, 894, 379, 631, 894,
    82, 379, 852, 631, 677,
    677, 194, 893
]

phi = (p - 1) * (q - 1)

# compute private key d using Python's built-in modular inverse
d = pow(e, -1, phi)
print("d =", d)

# decrypt each ciphertext
for i in c:
    i_mod = i % n          # reduce ciphertext modulo n
    m = pow(i_mod, d, n)   # RSA decryption
    print(chr(m), end="")

print()
