import random
import time

def merge(s1,s2):
    out=[]
    for i in s1:
        out.append(s2[i])
    return out
def sim(arr,reps):
    n=len(arr)
    ans=list(range(n))

    k=1
    while k<=reps:
        if reps&k:
            ans=merge(ans,arr);
        arr=merge(arr,arr)
        k*=2
    return ans

def dumb(arr,reps):
    if reps == 0:
        return list(range(len(arr)))
    reps -= 1
    t = arr[:]
    ans = arr[:]
    for i in range(reps):
        for j in range(len(ans)):
            ans[j] = t[ans[j]]
    return ans

def case():
    sarr=input().split()
    n=int(sarr[0])
    reps=int(sarr[1])
    arr=[int(x) for x in input().split()]
    #dans=dumb(arr,reps)
    ans=sim(arr,reps)
    #assert(dans==ans)
    #print(dans)
    #print(ans)
    for i in range(n):
        print(ans[i])


def timeStuff(maxr):
        n=5000
        arr=[0]*(n+1)
        v=0
        mt=0
        for k in range(10):
                for i in range(n):
                        arr[i]=random.randint(0,n-1)
                x=time.time()
                a=dumb(arr,random.randint(0,int(maxr)))
                v+=time.time()-x
                mt=max(mt,time.time()-x)
        print(v)
        print(mt)

    
def gen(idn,reps):
    n=random.randint(1,5000)
    f=open('input'+str(idn)+'.txt','w')
    arr=[0]*(n+1)
    f.write(str(n)+' '+str(reps)+'\n')
    for i in range(n):
            arr[i]=random.randint(0,n-1)
            f.write(str(arr[i]))
            if i!=n-1:
                    f.write(' ')
    f.write('\n')
    f.close()
    f=open('output'+str(idn)+'.txt','w')
    a=sim(arr,reps)
    f.write(str(a)+'\n')

case()
