from random import randint
fout = open("bridges.in", 'w')
N = 98725
M = 76249
fout.write(str(N)+' '+str(M)+'\n')
i=M
while i>0:
   a = randint(1, N)
   b = randint(1, N)
   if a==b:
      continue
   fout.write(str(a)+' '+str(b)+'\n')
   i-=1