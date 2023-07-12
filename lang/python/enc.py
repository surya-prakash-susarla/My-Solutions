import math
import sys
s=raw_input()
h=int(len(s))
row_limit=int(math.floor(math.sqrt(h)))
col_limit=int(math.ceil(math.sqrt(h)))
r=int(row_limit)
c=int(col_limit)
def check(r,c):
	if r*c<h:
		if r<col_limit:
			r+=1
			r,c=check(r,c)
		elif c<col_limit:
			c+=1
			r,c=check(r,c)
	return r,c
r,c=check(r,c)
a=[]
t=0
for i in range(r):
	temp=[]
	for j in range(c):
		if t<h:
			temp.append(s[t])
		else:
			temp.append(-1)
		t+=1
	a.append(temp)	
for i in range(c):
	for j in range(r):
		if a[j][i]!=-1:
			sys.stdout.write(a[j][i])
	if i<c-1:
		sys.stdout.write(" ")
