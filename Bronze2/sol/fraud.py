import random

def shift(s,i):
	return s[i:]+s[:i]
def case(s):
	sbest=s
	for i in range(1,len(s)):
		st=shift(s,i)
		if st<sbest:
			sbest=st
	return sbest

def makeCase(n,idn):
	f=open('input'+str(idn)+'.txt','w')
	s=''
	for i in range(n):
		s=s+chr(random.randint(ord('a'),ord('z')))
	if idn==9:
		s='k'*2000
	f.write(s)
	f.write('\n')
	f.close()
	f=open('output'+str(idn)+'.txt','w')
	a=case(s)
	f.write(a+'\n')

cases=[6,26,999,1645,1895,1978,2000,1999,2000]
for i in range(len(cases)):
	makeCase(cases[i],i+1)

s=input()	
print(case(s))

