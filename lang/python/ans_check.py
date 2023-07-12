import sys
cal = open(sys.argv[1],'r+').read()
ans = open(sys.argv[2],'r+').read()
for i,j in zip(cal,ans):
    if i!=j:
        print "INCORRECT ----- answer differs at ",i,"\t",j
        exit()
print("CORRECT !!!")
