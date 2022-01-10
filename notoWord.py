'''def wordNo(no):
    noDic = {0:"Zero",1:"One",2:"Two",3:"Three",4:"Four",5:'Five',6:"Six",7:"Seven",8:"Eight",9:"Nine",
                10:"Ten",11:"Eleven",12:"Twelve",13:"Therteen",14:"Fourteen",15:"Fifteen",16:"Sixteen",
                17:"Seventeen",18:"Eightteen",19:"Nineteen",20:"Twenty",30:"Thirty",40:"Fourty",50:"Fifty",
                60:"Sixty",70:"Seventy",80:"Eighty",90:"Ninety"}
    st = ""
    no=int(no)

    if no>99:
        lastTwo = no%100
        firstOne = no // 100

        if lastTwo == 0:
            return st+noDic[firstOne]+" Hundred"

        if lastTwo > 19 and lastTwo % 10 != 0:
            last = lastTwo % 10
            first = lastTwo - last 
            st += noDic[first] + " " + noDic[last]
        else:
            st += noDic[lastTwo] 
        st = noDic[firstOne] + " Hundred " + st 
    else:
        if no > 19 and no % 10 != 0:
            last = no % 10
            first = no - last 
            st += noDic[first] + " " + noDic[last]
        else:
            st += noDic[no] 

    return st

no=input("Enter the Number: ")

Base=['','Thousand','Million','Billion','Trillion','Quadrillion','Quintillion','Sextillion','Septillion',
'Octillion','Nonillion','Decillion','Undecillion','Duodecillion','Tredecillion','Quatttuor-decillion',
'Quindecillion','Sexdecillion','Septen-decillion','Octodecillion','Novemdecillion','Vigintillion']

print(wordNo(no))
'''

def ToWord(N):
    Result=''
    Unit=['','One','Two','Three','Four','Five','Six','Seven','Eight','Nine','Ten'
    ,'Eleven','Twelve','Thirteen','Fourteen','Fifteen','Sixteen','Seventeen','Eighteen','Nineteen']
    Decimal=["","",'Twenty','Thirty','Fourty','Fifty','Sixty','Seventy','Eighty','Ninety']
    if N>99:
        Result= Unit[N//100]+" Hundred"
    if N%100!=0:
        N%=100
        if N>19:
            Result=Result+" "+Decimal[N//10]+" "+Unit[N%10]
        else:
            Result=Result+" "+Unit[N%20]#+" "+Unit[N%10]    
    return Result

num=int(input("Enter number:"))
Base=['','Thousand','Million','Billion','Trillion','Quadrillion','Quintillion','Sextillion','Septillion',
 'Octillion','Nonillion','Decillion','Undecillion','Duodecillion','Tredecillion','Quatttuor-decillion',
 'Quindecillion','Sexdecillion','Septen-decillion','Octodecillion','Novemdecillion','Vigintillion']
ind=0
Res=''

while  num:
    Res=ToWord(num%1000)+" "+Base[ind]+" "+Res
    num//=1000
    ind+=1

print(Res)    