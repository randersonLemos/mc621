t = int(input())

while t:
    t = t - 1
    n = int(input())
    
    if n == 2:
        # Alice [1,1] => Bob [2]
        winner = 'Bob'
    
    if n == 3:
        # Alice [1,1,1] => Bob [2,1]
        # Alice [1,1,1] => Bob [3]
        winner = 'Bob'
    
    if n == 4:
        # Alice [1,1,1,1] => Bob [2,1,1] => Alice [2,2] => Bob [4]
        # Alice [1,1,1,1] => Bob [3,1]
        # Alice [1,1,1,1] => Bob [4]
        winner = 'Bob' 
    
    if n >= 5:
        # Alice [1,1,1,...,1] => Bob [1,1,a] => Alice [2,a]
        winner = 'Alice'
    
    print(winner)
