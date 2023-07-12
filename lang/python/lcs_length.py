s=raw_input("enter the first string\n")
t=raw_input("enter the second string\n")
def max(a,b):
	if a>b:
		return a
	else:
		return b
def len_lcs(s,t,m,n):
	if m==0 or n==0:
		return 0
	elif s[m-1]==t[n-1]:
		return 1+len_lcs(s,t,m-1,n-1)
	else:
		return max(len_lcs(s,t,m-1,n),len_lcs(s,t,m,n-1))
print len_lcs(s,t,len(s),len(t))
