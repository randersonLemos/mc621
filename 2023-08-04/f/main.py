def main():
    stg1 = ''.join( sorted( input() ) )
    stg2 = ''.join( sorted( input() ) )

    bag = ['']

    for s in stg2:
        if s == '?':
            tmp = []
            for stg in bag:
                tmp.append( '+' + stg )
                tmp.append( stg + '-' )
            bag = tmp

        if s == '+':
            for en, stg in enumerate(bag):
                bag[en] = '+' + stg

        if s == '-':
            for en, stg in enumerate(bag):
                bag[en] = stg + '-'
    
    count = 0
    for stg in bag:
        if stg == stg1:
            count += 1

    print(count/ len(bag))

if __name__ == '__main__':
    main()
