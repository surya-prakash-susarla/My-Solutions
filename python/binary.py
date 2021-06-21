n =int(raw_input("Enter the number of numbers\n"))

a=[]
for i in range(n):
	a.append(raw_input())

ind =0 
search = raw_input("Enter the number to be searched\n")

def se(a,first,last):
	if (first+last)>2:
		middle = (first+last)/2
		if a[middle]>search:
			se(a,middle+1,len(a))
		elif a[middle]<search:
			se(a,0,middle)
		elif a[middle]==search:
			ind=middle
			return
	elif a[first]==search:
		ind=first
		return
	elif a[last-1]==search:
		ind = last-1
		return


se(a,0,len(a))
print(ind)
