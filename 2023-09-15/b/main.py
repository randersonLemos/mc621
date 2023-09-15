if __name__ == '__main__':
    n = int( input() )
    wheels = list( map( int, input().split(' ') ) )

    left = wheels[0]
    for right in wheels[1:]:

        print( left, right )
