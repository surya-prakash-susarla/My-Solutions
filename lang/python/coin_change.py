m=raw_input("enter the number of numbers\n")
a=[]
for i in range(int(m)):
	a.append(raw_input())
co=[]
for i in a:
	co.append(i)
val=[]
for i in a:
	val.append(-1)
def check(num):
	if num==0:
		return 1
	elif num in co and val[co.index(num)]!=-1:
		return val[co.index(num)]
	else:
		found=False
		z=0
		total=0
		for j in a:
		#	print "j=",j," num=",num
			if int(j)==int(num) or int(j)<int(num):
#				print j<=num
				z=check(int(num)-int(j))
				print j,"\t",int(num)-int(j),"\t",num
				print "Checking for ",int(num)-int(j)," got: ",z
				if z>0:
					total+=z
					found=True
		if not found:
			return 0
		else:
			if num in co:
				val[co.index(num)]=total
			else:
				co.append(num)
				val.append(total)
		return total	
				
print check(raw_input("Enter any number to check\n"))
