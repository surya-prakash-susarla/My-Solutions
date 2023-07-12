class node:
	data=None
	left=None
	right=None
	def __init__(self):
		self.data=raw_input("Enter the data\n")
		c=raw_input("Do u want left node\n")
		if c=='y':
			self.left = node()
		c=raw_input("Do u want right node\n")
		if c=='y':
			self.right=node()
	def max_heapify(self):
		max=self.data
		if max<self.left.data and self.left!=None:
			max=self.left.data
		if max<self.right.data and self.right!=None:
			max=self.right.data
		self.data=max
		if self.left!=None:
			self.left.max_heapify()
		if self.right!=None:
			self.right.max_heapify()
heap_main_node = node()
heap_main_node.max_heapify()
def printer(node):
	print node.data,"\n"
	if node.left!=None:
		printer(node.left)
	if node.right!=None:
		printer(node.right)
printer(heap_main_node)
