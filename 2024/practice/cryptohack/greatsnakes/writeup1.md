
<!DOCTYPE html>
<html>

<body>
    <h1>ctf event- challengename Challenge Writeup(first save it)</h1>

    <h2>Challenge Description</h2>
    <p> your description
Modern cryptography involves code, and code involves coding. CryptoHack provides a good opportunity to sharpen your skills.

Of all modern programming languages, Python 3 stands out as ideal for quickly writing cryptographic scripts and attacks. For more information about why we think Python is so great for this, please see the FAQ.

Run the attached Python script and it will output your flag.

Challenge files:
 <a href="https://cybersecctf.github.io/blog/2024/practice/cryptohack/great_snakes_35381fca29d68d8f3f25c9fa0a9026fb.py">greate_snakes.py</a>       
Resources:
 <a href="https://wiki.python.org/moin/BeginnersGuide/Download">python resources</a>       

</p>
 
    <h2>Solution Approach</h2>
    <p>Here are the steps we took to solve the challenge:</p>
    <ol>
this is a challenge for test python version and run python code and get flag if version is not 2.
after run code below will get flag
<pre>
#python
import ast
import sys
# import this
print("custom usage -v listinstring hex")
if sys.version_info.major == 2:
    print("You are running Python 2, which is no longer supported. Please update to Python 3.")

if len(sys.argv)>1:
  ords=sys.argv[1]
  ords= ast.literal_eval(ords)

else:
  ords = [81, 64, 75, 66, 70, 93, 73, 72, 1, 92, 109, 2, 84, 109, 66, 75, 70, 90, 2, 92, 79]
hexs="0x32" 
if len(sys.argv)>2:
  hexs=sys.argv[2]
print(ords)
for x in ords:
  print(x)
print("Here is your flag:")

hexs = int(hexs, 16)
print("".join(chr(o ^ hexs) for o in ords))

    </ol>
<br>
    <h2>Flag</h2>
    <p class="flag">crypto{z3n_0f_pyth0n}
</p>

    <h2>Conclusion</h2>
    <p>this is a challenge for get python version and run it</p>
</body>
</html>

