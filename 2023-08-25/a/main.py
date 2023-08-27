if __name__ ==  '__main__':
    count = 0
    text = ''
    while True:
        count += 1
        bill = 0
        n, f = map( int, input().split() )

        if (n == 0) and (f==0):
            break

        for i in range( n ):
            val = int( input() )
            bill += val

        text += "Bill #{} costs {}: each friend should pay {}".format(count, int(bill), int(bill//f))
        text += '\n\n'

    print(text[:-1])
