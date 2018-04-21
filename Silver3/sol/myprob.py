import random
import time

def trans(arr):
        q = arr.pop(0)
        arr.append(0)
        
        return [x + 1 if i < q else x for i, x in enumerate(arr)]


def mapLen(arr):
    m={}
    st=0
    while True:
        t=tuple(arr)
        #print(arr)
        if t in m:
            return (st-m[t],m[t])
        m[t]=st
        arr=trans(arr)
        st+=1

def case():
        n=int(input())
        arr=[int(x) for x in input().split()]
        a,b=mapLen(arr)
        print(str(a)+' '+str(b))
        
def timeStuff(n):
        arr=[0]*(n+1)
        v=0
        mt=0
        for k in range(60):
                for i in range(n):
                        arr[i]=random.randint(0,n-1)
                x=time.time()
                a,b=mapLen(arr)
                print(str(a)+' '+str(b))
                v+=time.time()-x
                mt=max(mt,time.time()-x)
        print(v)
        print(mt)

def genCase(idn,n):
        f=open('input'+str(idn)+'.txt','w')
        arr=[0]*(n+1)
        f.write(str(n)+'\n')
        for i in range(n):
                arr[i]=random.randint(0,n-1)
                f.write(str(arr[i]))
                if i!=n-1:
                        f.write(' ')
        f.write('\n')
        f.close()
        f=open('output'+str(idn)+'.txt','w')
        a,b=mapLen(arr)
        f.write(str(a)+' '+str(b)+'\n')
        
#134.8934371471405
