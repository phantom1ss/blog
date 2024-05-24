import sys
from binascii import unhexlify
import sys
sys.path.append('/home/mrrobot/Desktop/blog')  # This is an absolute path
import blog
def brute(input, key):
    if len(input) != len(key):
        return "Failed!"
    output = b''
    for b1, b2 in zip(input, key):
        output += bytes([b1 ^ b2])
    try:
        return output.decode("utf-8")
    except:
        return "Cannot Decode some bytes"
def solve(data,search="crypto{"):
 cipher = unhexlify(data)
 print("[-] CIPHER: {}".format(cipher))
 # First Step
 key_part = brute(cipher[:7], search.encode())
 print("[-] PARTIAL KEY FOUND: {}".format(key_part))
 # Second Step
 key = (key_part + "y").encode()
 key += key * int((len(cipher) - len(key))/len(key))
 key += key[:((len(cipher) - len(key))%len(key))]
 print("[-] Decoding using KEY: {}".format(key))
 plain = brute(cipher, key)
 return plain 
if __name__ == "__main__" :
 data=blog.set("0e0b213f26041e480b26217f27342e175d0e070a3c5b103e2526217f27342e175d0e077e263451150104",1)
 search=blog.set("crypto{",2)
 plain=solve(data,search)
 print("\n[*] FLAG: {}".format(plain))