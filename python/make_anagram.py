s=raw_input()
t=raw_input()
ch1=[]
r1=[]
for i in s:
	if i in ch1:
		r1[ch1.index(i)]+=1
	else:
		ch1.append(i)
		r1.append(1)
ch2=[]
r2=[]
for i in t:
	if i in ch2:
		r2[ch2.index(i)]+=1
	else:
		ch2.append(i)
		r2.append(1)
if len(ch2)>len(ch1):
	ch1,ch2=ch2,ch1
	r1,r2=r2,r1
for i in ch1:
	if i in ch2:
		z=r1[ch1.index(i)]
		g=r2[ch2.index(i)]
		if z>g:
			r1[ch1.index(i)]=z-g
			r2[ch2.index(i)]=0
		else:
			r1[ch1.index(i)]=0
			r2[ch2.index(i)]=g-z
tot=0
for i in r1:
	tot=tot+i
for i in r2:
	tot=tot+i
print tot
