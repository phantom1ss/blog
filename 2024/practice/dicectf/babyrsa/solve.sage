from Crypto.Util.number import long_to_bytes
p, q = int(input("input p get p,q from factordb")), int(input("input q"))
N = int(input("input n"))
e = int(input("input e"))
cipher = int(input("input c"))
# factor with cado-nfs


assert p * q == N

p_roots = mod(cipher, p).nth_root(e, all=True)
q_roots = mod(cipher, q).nth_root(e, all=True)

for xp in p_roots:
    for xq in q_roots:
        x = crt([Integer(xp), Integer(xq)], [p,q])
        x = int(x)
        flag = long_to_bytes(x)
        if flag.startswith(b"dice"):
            print(flag.decode())
