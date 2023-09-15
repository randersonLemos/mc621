######################
### https://www.geeksforgeeks.org/prime-numbers/
#####################


def isPrimeBrutalForce( n ):
    m = 3
    while(m*m <= n):
        if ( n % m ) == 0:
            return False
        m = m + 2
    return True


def isPrime( n ):
    if n == 2:
        return True

    if n == 3:
        return True


    if n % 2 == 0:
        return False

    return isPrimeBrutalForce( n )


if __name__ == '__main__':
    while(True):
        n = int(input())
        if not n:
            break

        p = 2*n+1
        while not isPrime(p):
            p = p+2

        if not isPrime(n):
            print( '{} ({} is not prime)'.format(p, n) )
        else:
            print( '{}'.format(p) )
