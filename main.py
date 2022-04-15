x=input("")
#代码开始
total=0
a=[10,9,8,7,6,5,4,3,2,1]
b=[]
for i in range(len(x)):
    if x[i].isdigit():
        total+=a[i]*int(x[i])
        b.append(a[i]*int(x[i]))
    else:
        total+=10*a[i]
        b.append(10*a[i])
for i in range(len(b)):
    if b[i]%10==b[i] and b[i]!=0:
        s=b[i]
total+=s
if total%11==0:
    print(x+str(s))
#代码结束