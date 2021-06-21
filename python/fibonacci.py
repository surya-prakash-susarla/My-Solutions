n = int(raw_input("Enter the limit\n"))
a=[]
a.append(0)
a.append(1)
print a[0]
for i in range(2,n):
	a.append(a[i-1]+a[i-2])
print a
