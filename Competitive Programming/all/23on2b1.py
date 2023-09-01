n=input()
kt = True
for i in range (0, n):
    if i%2==0:
        if n[i]!=n[i].lower():
            kt = False
            break
    else: 
        if n[i]!=n[i].upper():
            kt = False 
            break
            
if kt == True:
    print('Yes')
else:
    print('No')