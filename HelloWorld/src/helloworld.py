#print("Hello World")
#x = 10.2
#print("bla", x)
import os

myfile = open("somefile.txt", "w")
myfile.write("blablalba")
myfile.close()

myfile = open("somefile.txt", "r")
myContent = myfile.read()
print(myContent)
myfile.close()
os.remove("somefile.txt")