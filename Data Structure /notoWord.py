# No to Word.

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

if __name__=="__main__":
    num=int(input("Enter number:"))
    if num == 0:
        print("Zero")
        exit(0)

    Base=['','Thousand','Million','Billion','Trillion','Quadrillion','Quintillion','Sextillion','Septillion',
    'Octillion','Nonillion','Decillion','Undecillion','Duodecillion','Tredecillion','Quatttuor-decillion',
    'Quindecillion','Sexdecillion','Septen-decillion','Octodecillion','Novemdecillion','Vigintillion']

    ind=0
    Res=''
    isMinus = False
    if num < 0:
            isMinus = True
            num= -1*num

    while  num:
        
        say = num%1000
        if say != 0:
            Res=ToWord(say)+" "+Base[ind]+" "+Res
        num//=1000
        ind+=1

    if isMinus:
        Res = "Minus "+Res
    print(Res)  
