class node:
	data=None
	right=None
	left=None
	def __init__(self):
		self.data = raw_input("Enter the data\n")
		print "Do u want to create left node"
		c = raw_input()
		if c=='y':
			self.left = node()
		c = raw_input("Do u want to create right node\n")
		if c=='y':
			self.right = node()
	def print_data(self):
		print self.data
	def is_exist(self):
		if self.right!=None and self.left!=None:
			return True
	def get_data(self):
		return self.data
	def set_data(self,a):
		self.data=a

def sort(initial):
	#print initial,initial.right.get_data(),initial.left.get_data(),"\n"
	if initial.right!=None and initial.left!=None:
		if initial.right.get_data()<initial.left.get_data():
			temp=initial.right.get_data()
			temp1 = initial.left.get_data()
			initial.right.set_data(temp1)
			initial.left.set_data(temp)
	if initial.right!=None:
		sort(initial.right)
	if initial.left!=None:
		sort(initial.left)
def print_full_data(Node):
	if(Node.data!=None):
		print Node.get_data(),"\n"
	if(Node.left!=None):
		print_full_data(Node.left)
	if(Node.right!=None):
		print_full_data(Node.right)

print "Node creation begins"
main = node()
sort(main)
print_full_data(main)

