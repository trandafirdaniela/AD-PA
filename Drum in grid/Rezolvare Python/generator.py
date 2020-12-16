import random
import os
def generare():
    current_directory = os.getcwd()
    final_directory = os.path.join(current_directory, r'tests')
    if not os.path.exists(final_directory): 
        os.makedirs(final_directory)
    for test in range(0,10):
        f= open(os.path.join(final_directory,'input'+str(test)+'.txt'),"w")
        x=int((test+1)*50)
        f.write(str(x))
        f.write("\n")
        for i in range(0,x):
            for j in range(0,x):
                f.write(str(random.randint(0,1000))+" ")
            f.write("\n")
        f.close()
