t=raw_input()
for o in range(int(t)):
	r,c=raw_input().split(" ")
	grid=[]
	for i in range(int(r)):
		grid.append(raw_input())
	gr,gc=raw_input().split(" ")
	pattern=[]
	for i in range(int(gr)):
		pattern.append(raw_input())
	def check(gn,pn,pi):
		if pn==len(pattern):
			return True
		elif pattern[pn] in grid[gn]:
			index=[]
			index.append(grid[gn].find(pattern[pn]))
			while grid[gn][index[-1]+1:].find(pattern[pn])!=-1:
				index.append(grid[gn][index[-1]+1:].find(pattern[pn]))
			if pi!=-1:
				for i in pi:
					if i not in index:
						index.remove(i)
			if check(gn+1,pn+1,index):
				return True
		return False			
	zigler=0
	for i in range(int(r)):
		if check(i,0,-1):
			print "YES"
			zigler=2
	if zigler==0:
		print "NO"
