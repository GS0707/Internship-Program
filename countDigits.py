# Count digits in Number.

n=int(input("Enter the No. "))
count=0

if n<0:
  n*=-1
while n!=0:
  count+=1
  n=n//10
print(count)
