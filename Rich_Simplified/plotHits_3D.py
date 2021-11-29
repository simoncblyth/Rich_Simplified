from math import sqrt
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

ox_result = np.load('/tmp/liyu/opticks/source/evt/g4live/natural/1/ox.npy')

g4_file = open("build/Geant4_hits.txt","r")
g4_result = []
for line in g4_file:
    temp = [float(s) for s in line.strip().split()]
    g4_result.append(temp)
g4_result = np.array(g4_result)

fig = plt.figure()
ax = fig.gca(projection='3d')
for i in range(ox_result.shape[0]):
    pos = ox_result[i,0]
    dire = ox_result[i,1]
    #mold = sqrt( dire[0]**2+dire[1]**2+dire[2]**2 )
    #ax.quiver(pos[0],pos[1],pos[2],dire[0]/mold+pos[0],dire[1]/mold+pos[1],dire[2]/mold+pos[2])
    ax.quiver(pos[0],pos[1],pos[2],dire[0],dire[1],dire[2],length=100,arrow_length_ratio=0.6,linewidths=1,colors='r')
#print(pos[0],pos[1],pos[2],dire[0]/mold+pos[0],dire[1]/mold+pos[1],dire[2]/mold+pos[2])
for i in range(g4_result.shape[0]):
    pos = g4_result[i,0:3]
    dire = g4_result[i,3:6]
    #print(pos,dire)
    #mold = sqrt( dire[0]**2+dire[1]**2+dire[2]**2 )
    #ax.quiver(pos[0],pos[1],pos[2],dire[0]/mold+pos[0],dire[1]/mold+pos[1],dire[2]/mold+pos[2])
    ax.quiver(pos[0],pos[1],pos[2],dire[0],dire[1],dire[2],length=100,arrow_length_ratio=0.6,linewidths=1,colors='b')

ax.view_init(elev=0,azim=-180)
#ax.view_init(elev=0,azim=-270)
plt.xlabel('x')
plt.ylabel('y')
plt.show()
    
