'''Matrix Multipication'''

# Func to accept matrix
def acceptM(rows,col):
    matrix=[]
    for i in range(rows):
        row=[]
        for j in range(col):
            row.append(int(input("Enter the element Row:{0} Col:{1}:".format(i,j))))

        matrix.append(row)
    for i in matrix:
        print(*i)        
    return matrix        


if __name__=='__main__':
    print("First Matrix: ")
    rows1=int(input("How many Rows of 1st Matrix: "))
    col1=int(input("How many Columns of 1st Matrix : "))

    print("\nSecond Matrix: ")
    rows2=int(input("How many Rows of 2nd Matrix: "))
    col2=int(input("How many Columns of 2nd Matrix : "))

    # condition to check col and row
    if col1 != rows2:
        print("Columns of 1st matrix must same as Rows of 2nd matrix")
        exit(0)

    # print 1st and 2nd matrix
    print("\nMatrix 1: ")
    matrix1=acceptM(rows1,col1)
    print('\nMatrix 2: ')
    matrix2=acceptM(rows2,col2)

    # Multiplication matrix
    print("\nMultiplication Matrix: ")
    for i in range(rows1):
        for j in range(col2):
            Sum=0
            for k in range(rows2):
                Sum+=matrix1[i][k]*matrix2[k][j]
            print(Sum,end=" ")
        print()        
