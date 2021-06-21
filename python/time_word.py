import sys
ho=raw_input()
m=raw_input()

dict_time={
'00':"o' clock",
'01':'one',
'02':'two',
'03':'three',
'04':'four',
'05':'five',
'06':'six',
'07':'seven',
'08':'eight',
'09':'nine',
'10':'ten',
'11':'eleven',
'12':'twelve',
'13':'thirteen',
'14':'fourteen',
'15':'quarter',
'16':'sixteen',
'17':'seventeen',
'18':'eighteen',
'19':'nineteen',
'20':'twenty',
'21':'twenty one',
'22':'twenty two',
'23':'twenty three',
'24':'twenty four',
'25':'twenty five',
'26':'twenty six',
'27':'twenty seven',
'28':'twenty eight',
'29':'twenty nine',
'30':'half'
}
h="0"+ho
if int(m)==0:
	sys.stdout.write(dict_time[h])
	sys.stdout.write(" ")
	sys.stdout.write(dict_time['00'])
	sys.stdout.write("\n")
elif int(m)<=30:
	sys.stdout.write(dict_time[m])
	sys.stdout.write(" ")
	if int(m)!=15 and int(m)!=30 and int(m)>1:
		sys.stdout.write("minutes ")
	if int(m)!=15 and int(m)!=30 and int(m)<=1:
		sys.stdout.write("minute ")
	sys.stdout.write("past ")
	sys.stdout.write(dict_time[h])
elif int(m)>30:
	m=60-int(m)
	if m<10:
		m=str("0"+str(m))
	sys.stdout.write(dict_time[str(m)])
	sys.stdout.write(" ")
	if int(m)!=15 and int(m)!=30 and int(m)>1:
		sys.stdout.write("minutes ")
	if int(m)!=15 and int(m)!=30 and int(m)<=1:
		sys.stdout.write("minute ")
	sys.stdout.write("to ")
	h=str(int(h)+1)
	if int(h)<10:
		h="0"+h
	sys.stdout.write(dict_time[h])
	
