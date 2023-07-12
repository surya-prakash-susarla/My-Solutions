left_limit = 0
right_limit = 2
top_limit = 0
bottom_limit = 2

blank = ' '
board = [ [ blank for _ in range(3) ] for o in range(3) ]
threat_board = [ [ blank for _ in range(3) ] for o in range(3) ]

def print_board () :
	for i in range (0 , 3 ):
		for j in range ( 0 , 3 ):
			print board[i][j], " ",
		print

def check_and_add ( x , y , threat ):
#	print " the current point is " , x , "\t ",y
	if x>-1 and x<3 and y>-1 and y<3:
		temp = []
		temp.append(threat)
		temp.append(x)
		temp.append(y)
#		print "returning ",temp," \tfor ",x," ",y
		return temp
	else:
#		print " returning None "
		return

def find_maximum ( a ):
	maxer, maxind = -1, -1
	for i in a :
		if maxer==-1 or ( maxer!=-1 and i[0]>maxer ):
			maxer = a[0]
			maxind = i
#	print " checkef for " ,a
#   print "returning ",maxind
	return maxind

def threat_calculator ( x, y ):
#	print "\n\n calculating threat of ",x,"\t",y
	# right to left
	count = 0
	pts = []
	lx , ly = -1 , -1
	for i in range ( y-1, -1 , -1 ):
		if board[x][i]=='x':
			count = count + 1
		else:
			lx , ly = x , i
			break
	count_left = count
#	print "the number of x in left are ",count
#	print "co-ordinates of left are ",lx,"\t",ly
	# left to right
	count = 0
	rx , ry = -1 , -1
	for i in range ( y+1 , 3 ):
		if board[x][i]=='x':
			count = count+1
		else:
			rx , ry = x , i
			break
	count_right = count
#	print "the number of x in right are ",count
#	print "co-ordinates of right are ",rx,"\t",ry
	#top to bottom
	count = 0
	bx , by = -1 , -1
	for i in range ( x+1, 3 ):
		if board[i][y]=='x':
			count = count+1
		else:
			bx , by = i , y
			break
	count_bottom = count
#	print "the number of x in bottom are ",count
#	print "co-ordinates of bottom are ",bx,"\t",by
	#bottom to top
	count = 0
	tx , ty = -1 , -1
	for i in range ( x-1 , -1 , -1 ):
		if board[i][y]=='x':
			count = count + 1
		else:
			tx , ty = i , y
			break
	count_top = count
#	print "the number of x in top are ",count
#	print "co-ordinates of top are ",tx,"\t",ty
	#diagonal top right
	count = 0
	tdrx , tdry = -1 , -1
	for i , j in zip ( range ( x-1, -1 , -1 ) , range ( y+1 , 3 )):
		if board[i][j]=='x':
			count = count+1
		else:
			tdrx , tdry = i , j
			break
	count_top_right = count
#	print "the number of x in top right are ",count
#	print "co-ordinates of top right are ",tdrx,"\t",tdry
	#diagonal top left
	count = 0
	tdlx , tdly = -1 , -1
	for i , j in zip ( range ( x-1, -1 , -1 ) , range ( y-1, -1 , -1  )):
		if board[i][j]=='x':
			count = count+1
		else:
			tdlx , tdly = i , j
			break
	count_top_left = count
#	print "the number of x in top left are ",count
#	print "co-ordinates of top left are ",tdlx,"\t",tdly
	#diagonal bottom left
	count = 0
	bdlx , bdly = -1 , -1
	for i , j in zip ( range ( x+1, 3 ) , range ( y-1, -1 , -1  )):
		if board[i][j]=='x':
			count = count+1
		else:
			bdlx , bdly = i , j
			break
	count_bottom_left = count
#	print "the number of x in bottom left are ",count
#	print "co-ordinates of bottom left are ",bdlx,"\t",bdly
	#diagonal bottom right
	count = 0
	bdrx ,  bdry = -1 , -1
	for i , j in zip ( range ( x+1,3 ) , range ( y+1 , 3 )):
		if board[i][j]=='x':
			count = count+1
		else:
			bdrx , bdry = i , j
			break
	count_bottom_right = count
#	print "the number of x in bottom right are ",count
#	print "co-ordinates of bottom right are ",bdrx,"\t",bdry
	# total threats in each direction
	k=0
	if board[x][y]=='x':
		k=1
	d = count_right + count_left + k
	threat_left, threat_right = d , d
	d = count_top + count_bottom + k
	threat_top , threat_bottom = d , d
	d = k + count_top_right + count_bottom_left
	threat_diagonal_rl = d
	d = k + count_top_left + count_bottom_right
	threat_diagonal_lr = d
#	print " threat - left , right = ",threat_left
#	print " threat - top , bottom = ",threat_bottom
#	print " diagonal threat - right to left = ",threat_diagonal_rl
#	print " diagonal threat - left to right = ",threat_diagonal_lr

	if threat_left==3 or threat_right==3 or threat_top==3 or threat_bottom==3 or threat_diagonal_rl==3 or threat_diagonal_lr==3:
#		print " returning since the sum of threat is 3 "
		return " Game Over "

	final_pts = []
	temp = check_and_add(lx,ly,threat_left)
	if ( temp!=None ):
		final_pts.append(temp)
	temp = check_and_add(rx,ry,threat_right)
	if ( temp!=None ):
		final_pts.append(temp)
	temp = check_and_add(bx,by,threat_bottom)
	if ( temp!=None ):
		final_pts.append(temp)
	temp = check_and_add(tx,ty,threat_bottom)
	if ( temp!=None ):
		final_pts.append(temp)
	temp = check_and_add(tdrx,tdry,threat_bottom)
	if ( temp!=None ):
		final_pts.append(temp)
	temp = check_and_add(tdlx,tdly,threat_bottom)
	if ( temp!=None ):
		final_pts.append(temp)
	temp = check_and_add(bdrx,bdry,threat_bottom)
	if ( temp!=None ):
		final_pts.append(temp)
	temp = check_and_add(bdlx,bdly,threat_bottom)
	if ( temp!=None ):
		final_pts.append(temp)
#	print " the final pts array is "
#	print final_pts

	threat_board[x][y] = find_maximum ( final_pts )
#	print "finally selected value for ",x," ",y," is ",threat_board[x][y]
	return

def select_point ( ):
	maxer = -1
	maxx,maxy = -1 , -1
	for i in range (3):
		for j in range( 3 ):
			if board[i][j]==blank:
				 if maxer==-1 or ( maxer!=-1 and threat_board[i][j]!=None and threat_board[i][j][0]>maxer):
					 maxer = threat_board[i][j][0]
					 maxx = threat_board[i][j][1]
					 maxy = threat_board[i][j][2]
	if maxx==-1 or maxy==-1:
		return "Game Over"
	board[maxx][maxy]='o'
	return "Done"

def check_board () :
	for i in range(3):
		for j in range(3):
			if board[i][j]==blank or board[i][j]==None:
				return True
	return False

def play_game () :
	while  check_board() :
		ux , uy = raw_input(" Enter co-ordinates to place your X \n").split()
		ux = int(ux)
		uy = int(uy)
		board[ux][uy]='x'
		for i in range(3):
			for j in range(3):
				if threat_calculator ( i, j) == " Game Over ":
					print "You win !!! . Congratulations "
					return
		print "the current board is "
		print_board()
		if select_point()=="Game Over":
			print "You win!!! . Congratulations "
		print "the computer is done , the board is "
		print_board()
		print "now your turn"
	print "\n\n\n\n Thanks for playing \n\n\n\n "

print_board()
play_game()
