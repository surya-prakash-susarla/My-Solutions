val=[]
co=[]

def change(coin,m,sum):
	if sum in co:
		return val[co.index(sum)]
	if m<0 and sum>0:
		return 0
	elif m>=0 and sum==0:
		return 1
	else:
		x = change(coin,m-1,sum)+change(coin,m,int(sum)-int(coin[m]))
		co.append(sum)
		val.append(x)
		return x
coin=[]
coin=raw_input("enter the coins").split(" ")
print change(coin,len(coin)-1,raw_input("enter the sum"))
