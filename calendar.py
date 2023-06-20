def get(m,y):
    if m in [1,3,5,7,8,10,12]:
        return 3
    elif m==2:
        if y%100==0:
            if y%400==0:
                return 1
            else:
                return 0
        else:
            if y%4==0:
                return 1
            else:
                return 0
    else:
        return 2
def day(n):
    d=['Sunday','Monday','Tuesday','Wednesday','Thursday','Friday','Saturday']
    return d[n];
d=int(input("Enter the day : "))
m=int(input("Enter the month : "))
y=int(input("Enter the year : "))
n=0
for i in range(1,y):
    for j in range(1,13):
        n+=get(j,i)

for i in range(1,m):
    n+=get(i,y)
n+=d
print("The day is : ",day(n%7))
