

if __name__ == '__main__':
    cases = int( input() )
    while cases:
        cases -= 1

        book  = list(map(float, input().split(' ')))
        candles = int( input() )
        light = False
        while candles:
            candles -= 1
            candle = list(map(float,input().split(' ')))

            dist = (
                (book[0] - candle[0])**2 
                + (book[1] - candle[1])**2
            )**0.5
            print(dist)    
            if dist < 8.0:
                light = True
                break
        if light:
            print('light a candle')
        else:
            print('curse the darkness')
