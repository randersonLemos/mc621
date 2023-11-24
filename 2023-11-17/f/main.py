N = input()
sticks = sorted( list( map( int, input().split(' ')) ) )
sticks.reverse()

possible = False
for i in range(0, len(sticks) - 2):
    a, b, c = sticks[i], sticks[i+1], sticks[i+2]
    if(a<b+c):
        possible = True
        break

if possible:
    print('possible')
else:
    print('impossible')
        
