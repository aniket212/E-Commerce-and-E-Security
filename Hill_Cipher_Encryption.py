# cook your dish here

import math
import numpy as np

text=input("Enter your text")
key=input("Enter your key")
my_list=[(ord(x)-97) for x in text]
text_vector=np.array(my_list).T

x=int(math.sqrt(len(key)))
key_list=[]
for char in key:
    key_list.append(ord(char)-97)

key_vector=np.array(key_list).reshape(x,x)
mat_mul=np.dot(key_vector,text_vector)

cipher_list=(mat_mul.T).tolist()
cipher_text=' '
for x in cipher_list:
    cipher_text=cipher_text + chr(int(x%26) +ord('a'))

print("Encryption")
print("Cipher Text for your text is {0}".format(cipher_text))



