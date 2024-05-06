import string, itertools

import sys
 #create map repeating or ciustom like mapping 1 below for this quetion
def create_mapping(i):
    # Generate all possible 5-letter combinations of 'A' and 'B'
    combinations = [''.join(combination) for combination in itertools.product('AB', repeat=i)]
    
    # Map each combination to a letter in the alphabet
    mapping = {combination: letter for combination, letter in zip(combinations, string.ascii_uppercase)}
    
    return mapping
def bacon_decrypt(ciphertext, mapping):
    # Split the ciphertext into chunks of 5 characters (since Bacon's cipher uses 5-bit binary codes)
    chunks = [ciphertext[i:i+5] for i in range(0, len(ciphertext), 5)]
    
    # Decrypt the ciphertext using the provided mapping
    plaintext = ''.join(mapping.get(chunk, '?') for chunk in chunks)
    
    return plaintext


 
mapping1 = {'AAAAA': 'A', 'AAAAB': 'B', 'AAABA': 'C', 'AAABB': 'D', 'AABAA': 'E', 'AABAB': 'F', 'AABBA': 'G', 'AABBB': 'H', 'ABAAA': 'I', 'ABABA': 'L', 'ABBAA': 'N', 'ABBAB': 'O', 'ABBBB': 'P', 'BAAAA': 'Q', 'BAAAB': 'R', 'BAABA': 'T', 'BAABB': 'U', 'BABBB': 'X', 'BABBA': 'Y', 'ABBBA': 'M', 'BBBBA': 'S', 'AABBA': 'V', 'BABBB': 'W', 'BBBB': 'Z'}
mapping2 = {'AAAAA': 'A', 'AAAAB': 'B', 'AAABA': 'C', 'AAABB': 'D', 'AABAA': 'E', 'AABAB': 'F', 'AABBA': 'G', 'AABBB': 'H', 'ABAAA': 'I', 'ABAAB': 'J', 'ABABA': 'K', 'ABABB': 'L', 'ABBAA': 'M', 'ABBAB': 'N', 'ABBBA': 'O', 'ABBBB': 'P', 'BAAAA': 'Q', 'BAAAB': 'R', 'BAABA': 'S', 'BAABB': 'T', 'BABAA': 'U', 'BABAB': 'V', 'BABBA': 'W', 'BABBB': 'X', 'BBAAA': 'Y', 'BBAAB': 'Z'}
 
# Your Bacon-encoded ciphertext
ciphertext = 'ABAAAABABAABBABBAABBAABAAAAAABAAAAAAAABAABBABABBAAAAABBABBABABBAABAABABABBAABBABBAABB'  # Replace with your actual ciphertext
if len(sys.argv)>1:
 ciphertext=sys.argv[1]
if len(sys.argv)>2:
 mapping1=sys.argv[2]   

for i in range(10):
 print(bacon_decrypt(ciphertext,create_mapping(i)))
print(bacon_decrypt(ciphertext,mapping1))
