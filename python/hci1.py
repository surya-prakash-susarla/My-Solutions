import sys
ml=raw_input()
s=raw_input().split(" ")
ele=s[len(s)-1]
indi=-1
def printer(s):
	for i in range(len(s)):
		sys.stdout.write(s[i])
		if i<len(s)-1:
			sys.stdout.write(" ")	
for i in range(len(s)-1,-1,-1):
	if s[i]== ele:
		continue
	else:
		if s[i]>ele:
			s[i+1]=s[i]
			indi=i
			printer(s)
			sys.stdout.write("\n")
		else:
			s[indi]=ele
			printer(s)
			sys.stdout.write("\n")
