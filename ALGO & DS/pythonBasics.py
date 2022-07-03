a=[[1,2], 3, 4]


#a.insert(len(a), [10, 10])
#print(a)

a[0].insert(len(a[0]), 6)




a= []
#a.insert(len(a), [10, 10])
#print(a)
for i in range(1, 10):
    a.append(i)
    
a.append([10,11])
print(a)






info = {} 
   
info.__setitem__('Address', [[1,2], [3,4]]) 

list = info['Address'][0]
print(list)
print(info['Address'][1])