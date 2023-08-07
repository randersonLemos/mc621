    #
# https://www.geeksforgeeks.org/prime-numbers/
#
def _is_prime(n , i):
    if (n == 0 or n == 1):
        return False

    if (n == i):
        return True

    if (n % i == 0):
        return False

    i += 1

    return _is_prime(n,i)
    

def is_prime(n):
    return _is_prime(n, 2)


def main():

    n = int( input() )
    
    for m in range(1,1001):
        if not is_prime(n*m + 1):
            return m


if __name__ == '__main__':
    print( main() )
