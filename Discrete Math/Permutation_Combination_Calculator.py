#Calculator that figures out the combination and permutation

#C(n,r) = n!/(r!*(n-r)!)

#Combination function
#Top Half
n = int(input("Enter a number"))
top_factorial = 1

for i in range(1, n+1):
    top_factorial *= i

print("The factorial of ", n, " is ", top_factorial)

#Bottom Left Half
r = int(input("Enter a number"))
BL_factorial = 1

for i in range(1,r+1):
    BL_factorial *= i

print("The factorial of ", r, " is ", BL_factorial)

#Bottom Right Half
BR_factorial = 1
s = n-r

for i in range(1,s+1):
    BR_factorial *= i

combination = top_factorial/(BL_factorial*BR_factorial)

print("Combination is ",combination)