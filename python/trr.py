class tree:
	temp=""
	def __init__(self,string):
		self.temp=string
	def printer(self):
		print "Hello ",self.temp,"\n"

a  = tree("Surya")

a.printer()


class node:
	data = -1
	right = None
	left = None
	def __init__(self,data,r,l):
		self.data=data
		self.right=r
		self.left = l
	def print_left(self):
		print "Left data is ",self.left.printer()
	def print_right(self):
		print "Right data is ",self.right.printer()
	def printer(self):
		return self.data
	def print_data(self):
		print "Data is ",self.data

node1 = node(10,None,None)
node2 = node(20,None,None)
node3 = node(50,node1,node2)

node3.print_left()
node3.print_right()
node3.print_data()
node3.printer()
