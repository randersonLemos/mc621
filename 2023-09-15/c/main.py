if __name__ == '__main__':

    n = int(input())
    counter = 0
    
    for i in range(n - 1, 0, -1):
        print(i)
        counter += 1
        if n % i == 0:
            break
    
    print(couner)
