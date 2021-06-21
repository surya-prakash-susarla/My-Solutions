n=raw_input()
a=[]
a=raw_input().split(" ")
h=-1
for i in a:
	if i>=h:
		h=i
tower=0
for i in a:
	if int(i)==int(h):
		tower+=1
pritn tower
