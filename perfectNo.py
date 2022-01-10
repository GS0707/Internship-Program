# Check how number are perfect number upto n.
n=int(input("Enter the no. "))

# check no. is grater than 6 or not
if n<6:
  print("Smallest perfect no is 6. Enter again valid no.")
  exit(0)

# check each no. upto n
for i in range(6,n):
  sum=0
  for j in range(1,i):
    # if no. is divisible add it to sum
    if i%j == 0:
      sum+=j
  #sum of divisors equal to that no. then it is perfect   
  if sum == i:
    print(i)
