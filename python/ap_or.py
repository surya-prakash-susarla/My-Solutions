start,end=raw_input().split(" ")
a,b=raw_input().split(" ")
na,nb=raw_input().split(" ")
fa=raw_input().split(" ")
fb=raw_input().split(" ")
ta=to=0
for i in fa:
	a=int(a)
	b=int(b)
	i=int(i)
	start=int(start)
	end=int(end)
	#print i,a,i+a,i+a>=start and i+a<=end
	if i+a>=start and i+a<=end:
		ta+=1
	#print ta
for i in fb:
	a=int(a)
	b=int(b)
	i=int(i)
	start=int(start)
	end=int(end)
	if i+b<=end and i+b>=start:
		to+=1
print ta,"\n",to
