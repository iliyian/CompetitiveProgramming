s=input()
max=0
sum=0
for i in s:
    if i=='0':
        if sum>max:
            max=sum
        sum=0
    else:
        if i=='x' or i=='X':
            sum+=10
        else:
            sum+=int(i)
if sum>max:
    max=sum
print(max)