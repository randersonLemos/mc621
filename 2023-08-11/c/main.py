n, k = input().split(' ')
n = int( n ); k = int( k )

V    = list( map(int, input().split(' ')) )

head = 0
tail = k 
mean = 0

for i in range(head, tail):
    mean += V[i]
mean = mean/k
meanMinFirstIdx = 0
meanMin = mean
meanMaxFirstIdx = 0
meanMax = mean

while True:
    headOldElem = V[head]

    head = head + 1
    tail = tail + 1
    if tail > n:
        break

    tailNewElem = V[tail-1]

    mean = mean - headOldElem/k + tailNewElem/k

    if mean < meanMin:
        meanMinFirstIdx = head
        meanMin = mean

    if mean > meanMax:
        meanMaxFirstIdx = head
        meanMax = mean
    

#print('head', head)
#print('tail', tail)
#print('mean', mean)

print(meanMinFirstIdx+1, meanMaxFirstIdx+1)

