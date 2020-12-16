import ctypes
import time
import os
from generator import generare
from homework_1 import solve1
from homework_2 import solve2
import math
def test(T):
    current_directory = os.getcwd()
    folder_directory = os.path.join(current_directory, r'tests')
    final_directory = os.path.join(folder_directory,'input'+str(T)+'.txt' )
    f = open ( final_directory)
    l = []
    l = [[int(num) for num in line.split()] for line in f ]
    n=l[0][0]
    l.remove(l[0])
    time1_start=time.time();
    result1=solve1(l,n)
    time1_finish=time.time();
    time2_start=time.time();
    result2=solve2(l,n)
    time2_finish=time.time();
    assert(result1==result2)
    f.close()
    current_directory = os.getcwd()
    folder_directory = os.path.join(current_directory, r'tests')
    final_directory = os.path.join(folder_directory, 'output'+str(T)+'.txt')
    f = open ( final_directory,'w' )
    time1= math.floor((time1_finish-time1_start)*1000)
    time2= math.floor((time2_finish-time2_start)*1000)
    print('Input '+str(T)+':\n')
    print('\tsolve1: '+str(time1)+' ms\tsolve2: '+str(time2)+' ms\n')
    f.write(str(result1))
    f.close()
generare()  
for i in range(0,10):
    test(i)
