#!/usr/bin/ python
t=raw_input()
s=raw_input()
k=raw_input()

a=""
def rotater(c,i):
	if i.islower() and int(c)>122:
		c=c-122
		c=c+96
		c=rotater(c,i)
	elif i.isupper() and int(c)>90:
		c=c-90
		c=c+64
		c=rotater(c,i)
	return c

for i in s:
	if i.isalpha():
		z=ord(i)+int(k)
		z=chr(rotater(z,i))
		a=a+z
	else:
		a=a+i
print a
		
