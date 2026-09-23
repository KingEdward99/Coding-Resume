#This program is a RSA decryption script. It was derived from the RSA decryption tool guide from NCLs

#Prompting the user to enter the values
print("What is the small prime (p): ")
small_prime = int(input())

print("What is the large prime (q): ")
large_prime = int(input())

print("What is the encrypt exponent (e): ")
encrypt_exponent = int(input())

print("Enter the ciphertext values separated by commas: ")
message = input()

#Convert ciphertext into a list of integers 
message = [int(x.strip()) for x in message.split(",")]

modulus = small_prime * large_prime #n = p * q

message = "" #ciphertext

eulers_totient = (small_prime-1)*(large_prime -1) #Q(n) = (p-1)*(q-1)

# compute private key d using Python's built-in modular inverse
decrypt_exponent = pow(encrypt_exponent, -1, eulers_totient)

print(f"\nModulus (n): {modulus}")
print(f"Euler Totient (phi): {eulers_totient}")
print(f"Private exponent (d): {decrypt_exponent}\n")

# Decrypt ciphertext
plaintext = ""

for m in message:
    c_mod = m % modulus              # normalize ciphertext
    m = pow(c_mod, decrypt_exponent, modulus)        # RSA decryption
    plaintext += chr(m)

print("Decrypted message:")
print(plaintext)