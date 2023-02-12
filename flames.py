#   Program to play flames
        
name1=input("Enter the name1 : ").lower()
name2=input("Enter the name2 : ").lower()
name1=name1.replace(" ","")
name2=name2.replace(" ","")

for i in name1:
    for j in name2:
        if i==j:
            name1=name1.replace(i,"",1) #   it replaces only one occurence
            name2=name2.replace(i,"",1)
            break

#print(name1)
#print(name2)


count= len(name1+name2)

#print(count)


if count>0:

    list1=["Friends","Lovers","Affectionate","Marriage","Enemies","Siblings"]

    while len(list1)>1:
        
        c=count%len(list1)
        s_index=c-1
        if s_index>=0:
            left=list1[:s_index]
            right=list1[s_index+1:]
            list1=left+right

        else:
            list1 = list1[:len(list1)-1]    #  Last element gets removed or deleted

    print("Relationship is: ",list1[0])

else:

    print("Enter Different Names")
