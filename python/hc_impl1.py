n=int(raw_input())
a=[]
for i in range(n):
	a.append(raw_input())
f=[]
def grade(t):
	t=int(t)
	if t<38:
		f.append(t)
		return
	else:
		div=t/5
		num=5*(div+1)
		if num-t<3:
			f.append(num)
			return
		else:
			f.append(t)
			return
for i in a:
	grade(i)
for i in f:
	print i
