import sys
a=raw_input("enter the numbers\n").split(" ")
add=[]
found=False
total=0
class node:
	global total,add,found
	data=left=right=None
	def __init__(self,dat):
		self.data=dat
	def ins(self,num):
		global total
		if self.left==None:
			self.left=node(num)
			total+=1
			add.append(self.left)
			self.check()
#			print "Inserted ",num," at ",self.data," left"
			found=True
			return 
		elif self.right==None:
			self.right=node(num)
			total+=1
			add.append(self.right)
			self.check()
#			print "Inserted ",num," at ",self.data," right"
			found=True
		add.remove(self)
	def check(self):
		if self.left!=None and self.left.data>self.data:
			self.left.data,self.data=self.data,self.left.data
		if self.right!=None and self.right.data>self.data:
			self.right.data,self.data=self.data,self.right.data
#	def printer(self):
#		print self.data
#		if self.left!=None:
#			print "In left of ",self.data
#			self.left.printer()
#		if self.right!=None:
#			print "In right of ",self.data
#			self.right.printer()
main_node=node(a[0])
add.append(main_node)
for i in range(1,len(a)):
	add[0].ins(a[i])
back = total
while total>0:
	main_node.check()
	total-=1		
def checker(node):
	if node.left!=None and node.left.data>node.data:
		node.left.data,node.data=node.data,node.left.data
	if node.right!=None and node.right.data>node.data:
		node.right.data,node.data=node.data,node.right.data
	if node.left!=None:
		checker(node.left)
	if node.right!=None:
		checker(node.right)	

print "Sorting############################################\n"
while back>0:
	sys.stdout.write(main_node.data+" ")
	main_node.data=-1
	te=back
	while te>0:
		checker(main_node)
		te-=1
	back-=1
