'''Decrypt my super sick RSA:
c: 240986837130071017759137533082982207147971245672412893755780400885108149004760496
n: 831416828080417866340504968188990032810316193533653516022175784399720141076262857
e: 65537 
'''


def gcd(a,b):
 
 if a<b:
  a,b=b,a
 if b==0:
    return a
 else:
    return gcd(b,a%b)
print(gcd(12,2))