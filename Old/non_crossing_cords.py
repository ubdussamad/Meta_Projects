import math

n = int( input( "Enter the value of n:") )

print("Enter the wieghts of 2n nodes.")

node_array = []

for i in range(2*n):
    node_array.append(int(input("Enter W%d: "%i)))
node_array.append(node_array[0])
def abs(x):
    return( x if x>0 else -x)

max_wt = 0
max_wt_index = None
for i in range(2*n):
    index = [i,i+1]
    wt = abs(node_array[i]-node_array[i+1])
    print("Comp nodes: %d and %d and sum is: %d"%(node_array[i],node_array[i+1],wt))
    if  (wt > max_wt):
        print(">>>Max wt is: %d current wt is: %d"%(max_wt,wt))
        max_wt_index = index
        max_wt = wt
        print(max_wt_index)
print(node_array[max_wt_index[0]] , node_array[max_wt_index[1]] ,"Are the starting node.")
    
