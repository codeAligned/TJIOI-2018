s=input()
n=len(s)
n2=int(n/2)
if n%2==1:
	s=s[:n2]+s[n2+1:]
	n-=1
ed=0
for i in range(n2):
	if s[i]!=s[n-i-1]:
		ed+=1
print(ed)
