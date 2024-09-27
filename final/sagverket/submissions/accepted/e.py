#!/usr/bin/env python3

import sys

def guess(g):
  sys.stdout.write("? "+str(g)+"\n")
  sys.stdout.flush()
  return list(map(int,sys.stdin.readline().split()))

def printsol():
  lst.sort()
  sys.stdout.write("! "+" ".join(map(str,lst))+"\n")
  sys.stdout.flush()

N,T=map(int,sys.stdin.readline().split())
  
x=1
d=guess(x)
F=dict()
for i in d:
  if i not in F:
    F[i]=0
  F[i]+=1 
lst=[1+sum(d)]
x=sum(d)+1

if T==1 or N==1:
  sys.stdout.write("! "+str(1+d[0])+"\n")
  sys.stdout.flush()
else:  
  d=guess(x)
  lst.append(x-sum(d))
  G=dict()
  for i in d:
    if i not in G:
      G[i]=0
    G[i]+=1
  F=G
  x=min(lst)+1
  while len(lst)<N:
    d=guess(x)
   
    G=dict()
    for i in d:
      if i not in G:
        G[i]=0
      G[i]+=1
    
    dim=-1
    for y in G:
      if y not in F or F[y]<G[y]:
        dim=y
    add=1
    if dim==-1:
      dim=0
      
    lst.append(x+dim)  
    x=x+dim+1
    '''
    sys.stderr.write("F:"+str(F)+"\n")
    sys.stderr.flush()
    sys.stderr.write("G:"+str(G)+"\n")
    sys.stderr.flush()
    sys.stderr.write("dim:"+str(dim)+"add:"+str(add)+"\n")
    sys.stderr.flush()
    '''
    if dim in G: 
      G[dim]-=1
      G[add]-=1
      if dim+add not in G:
        G[dim+add]=0
      G[dim+add]+=1
      if 0 not in G:
        G[0]=0
      G[0]+=1    
    F=G
    '''
    sys.stderr.write("G after:"+str(G)+"\n")
    sys.stderr.flush()  
    '''
  printsol()     
    