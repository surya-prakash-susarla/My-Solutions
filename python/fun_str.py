t=raw_input()
for o in range(int(t)):
	s=raw_input()
	r=s[::-1]
	shit=True
	for i in range(len(s)-1):
		z=ord(s[i+1])-ord(s[i])
		g=ord(r[i+1])-ord(r[i])
		if z<0:
			z=0-int(z)
		if g<0:
			g=0-int(g)
	#	print z,g,shit
		if int(z-g)!=0 and shit:
			print "Not Funny"
			shit=False
	if shit:
		print "Funny"
