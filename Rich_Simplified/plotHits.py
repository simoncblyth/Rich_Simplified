import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

data_file = open("build/All_data.txt","r")
result = []
for line in data_file:
    temp = [float(s) for s in line.strip()[1:-1].split(",")]
    result.append(temp);
result = np.array(result)

g4_file = open("build/Geant4_hits.txt","r")
g4_result = []
for line in g4_file:
    temp = [float(s) for s in line.strip().split()]
    g4_result.append(temp)
g4_result = np.array(g4_result)

op_count = [0,0,0,0]
g4_count = [0,0,0,0]
for r in result:
    if(r[1]<600 and r[1]>200 and r[2]>2000 and r[2]<2200):
        op_count[0]+=1
    elif(r[1]<1100 and r[1]>600 and r[2]<1300 and r[2]>1000):
        op_count[1]+=1
    elif(r[1]<1300 and r[1]>1100 and r[2]>1200 and r[2]<1500):
        op_count[2]+=1
    elif(r[1]<1600 and r[1]>1300 and r[2]>1400 and r[2]<1700):
        op_count[3]+=1
for r in g4_result:
    if(r[1]<600 and r[1]>200 and r[2]>2000 and r[2]<2200):
        g4_count[0]+=1
    elif(r[1]<1100 and r[1]>600 and r[2]<1300 and r[2]>1000):
        g4_count[1]+=1
    elif(r[1]<1300 and r[1]>1100 and r[2]>1200 and r[2]<1500):
        g4_count[2]+=1
    elif(r[1]<1600 and r[1]>1300 and r[2]>1400 and r[2]<1700):
        g4_count[3]+=1

opticks_hits = open("build/Opticks_hits.txt","r")
hits = []
for line in opticks_hits:
    hits.append( [float(s) for s in line.strip().split()] )
hits = np.array(hits)

plt.scatter(result[:,1],result[:,2],s=5,color='red',label='Opticks: '+str(result.shape[0])+' intersections')
plt.scatter(g4_result[:,1],g4_result[:,2],s=5,color='blue',label='Geant4: '+str(g4_result.shape[0])+' hits')
plt.scatter(hits[:,1],hits[:,2],s=5,color='black',label='Opticks: '+str(hits.shape[0])+' hits')
plt.legend(loc='best')

plt.text(600,2000,"Opticks: "+str(op_count[0]))
plt.text(600,1900,"Geant4: "+str(g4_count[0]))
plt.text(1100,1100,"Opticks: "+str(op_count[1]))
plt.text(1100,1000,"Geant4: "+str(g4_count[1]))
plt.text(1100,1400,"Opticks: "+str(op_count[2]))
plt.text(1100,1300,"Geant4: "+str(g4_count[2]))
plt.text(1600,1800,"Opticks: "+str(op_count[3]))
plt.text(1600,1700,"Geant4: "+str(g4_count[3]))
plt.axis([0,1600,900,2300])
ax = plt.gca()
ax.invert_xaxis()
plt.title("Hits collected by Opticks and Geant4")
plt.xlabel("y")
plt.ylabel("z")

plt.savefig("plotHits.pdf")
plt.show()
    
