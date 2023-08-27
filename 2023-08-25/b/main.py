class Frog:
    def __init__(self, hop):
        self.hop = hop
        self.pos = 0
        self.wei = 1


    def position(self):
        return self.pos


    def increaseWeight(self):
        self.wei += 1


    def weight(self):
        return self.wei


    def jump(self):
        self.pos += self.hop


    def __repr__(self):
        return 'Frog H {} P {} W {}'.format(self.hop, self.pos, self.wei)


if __name__ == '__main__':
    N = int( input() )
    for i in range(N):
        n = int( input() )
        frogs = {}
        
        jumpPositions = [0]*(n+1)
        maxJump = 0

        for hop in list(map(int, input().split())):
            if hop not in frogs:
                frogs[hop] = Frog(hop=hop)
                continue
            frogs[hop].increaseWeight()

        frogsList = list( frogs.values() )

        for frog in frogsList:
            while True:
                frog.jump()
                if frog.pos > n:
                    break
                jumpPositions[frog.pos] += frog.wei

                if maxJump < jumpPositions[frog.pos]:
                    maxJump = jumpPositions[frog.pos]

        print(maxJump)



