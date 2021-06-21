s=raw_input()
count=0
indi=1
for i in range(len(s)):
	if int(i)==indi:
		if s[i]!='O':
			count+=1
		indi+=3
	elif s[i]!='S':
		count+=1
print count	
