#  Count Occurrences

def countDigit(no):
    countDic = {}
    for digit in no:
        try:
            countDic[digit]+=1
        except:
            countDic[digit]=1
    return countDic

no=input("Enter the number: ")

print(countDigit(no))    
