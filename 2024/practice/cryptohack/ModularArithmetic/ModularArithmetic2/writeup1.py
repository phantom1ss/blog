#python   
import sys
sys.path.append('/home/mrrobot/Desktop/blog')  # This is an absolute path
import blog
def fermat_test(a, p):
    return pow(a, p - 1, p)  
import sys
# Test the function with your number and a prime

a=blog.set(273246787654,1)

p=blog.set(17,2) 
 
print(fermat_test(a, p))