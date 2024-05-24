#python
import sys,base64,binascii
import sys
sys.path.append('/home/mrrobot/Desktop/blog')  # This is an absolute path
import blog
def solve(type,text,codecs="text"):
 try:
  if type=="encode":
   sample_string_bytes = text.encode("ascii") 
   base64_bytes = base64.b64encode(sample_string_bytes) 
   if codecs=="hex":
     print(binascii.hexlify(base64_bytes))
   else:  
    print( "encoded in base64:",base64_bytes.decode("ascii") ) 
  else:
   base64_bytes = text.encode("ascii") 
   if codecs=="hex":
     print(binascii.hexlify(base64_bytes))
   else: 
    print("decoded from base64:",base64.b64decode(base64_bytes) )
 
 except Exception as   e:
  print("error:"+str(e)) 
if __name__ == "__main__" :
 codecs="text"
 type=blog.set("decode",1,"str","usage -v decode/encode text [text[default] hex base64]")
 text=blog.set("VGhlIFZlbm9uYSBwcm9qZWN0IHdhcyBhIFVuaXRlZCBTdGF0ZXMgY291bnRlcmludGVsbGlnZW5jZSBwcm9ncmFtIGluaXRpYXRlZCBkdXJpbmcgV29ybGQgV2FyIElJLg==",2)
 codecs=blog.set("text",3)
 solve(type,text,codecs)