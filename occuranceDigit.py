no=input("Enter the number: ")

countDic = {}

for digit in no:
  try:
    countDic[digit]+=1
  except:
    countDic[digit]=1
print(countDic)    
