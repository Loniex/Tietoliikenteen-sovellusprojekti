from mpl_toolkits import mplot3d
import pandas as pd
import numpy as np
from numpy import sqrt
import matplotlib.pyplot as plt
from numpy import savetxt


d=np.loadtxt("putty.log")
samples=len(d)
numberOfRows=int(samples/3)
data=np.zeros((numberOfRows,3))
data[:,0]=d[0::3]
data[:,1]=d[1::3]
data[:,2]=d[2::3]

#data
kp=np.array([[231,123,291],[50,100,231],[120,241,401],[23,1,220]])
centerPointCumulativeSum=np.array([[0,0,0],[0,0,0],[0,0,0],[0,0,0]])
Count=np.array([0,0,0,0]) #voittaja
Distances=np.array([0,0,0,0]) #laskettu etäisyys

#calc function
def calc(P1,P2):
 c=sqrt((P2[0]-P1[0])**2+(P2[1]-P1[1])**2+(P2[2]-P1[2])**2)
 return c

#calc test
#print(calc(centerPointCumulativeSum[0],centerPointCumulativeSum[1]))

check=0
NumberOfSimulations = 10000

for j in range(NumberOfSimulations):
 centerPointCumulativeSum=np.array([[0,0,0],[0,0,0],[0,0,0],[0,0,0]])
 Count=np.array([0,0,0,0])
 for i in range(numberOfRows):
   #print("=====Start======",i)
   for j in range(4):
    #print("S number:", i)
    Distances[j]=calc(data[i,:],kp[j,:])
    #print("CALC ANSWER==", calc(data[i,:],kp[j,:]), "I number", i)
    #print("Data1:", data[0], "Data2:",data[s])
    #print("Distances:", Distances)
    if j == 3:
     check=np.argmin(Distances)
     #np.where(Distances == min(Distances))
     #print("Check====", check)
     Count[check]=Count[check]+1
     centerPointCumulativeSum[check,:]=data[i,:]+centerPointCumulativeSum[check,:]
     #print("========CPCS========",centerPointCumulativeSum)
     
     #print("=====",check)
     #print("=====",Count)
     #print("======Stop=====", i)
   
 for i in range(4):
    if Count[i]==0:
      kp[i,:]=np.random.randint(low=0,high=1023,size=3)
      print("IF", kp)
    else:
       kp[i,:]=centerPointCumulativeSum[i,:]/Count[i]
       print("ELSE", kp, "I number", i)
file=open("keskipisteet.h","w+")
content=str(kp)
file.write(content)
file.close()
