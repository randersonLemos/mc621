n, m = input().split(' ')
n = int( n ); m = int( m )

k = 1
manners = 1
total_manners = 0

while True:
    if (k > m) or (k > n):
        break

    manners = manners*(m - (k-1))
    total_manners += manners

    k += 1

print(total_manners)
    
