import numpy as np

def fractal( model, k ):
    if k == 1:
        return model

    Model = []
    for row in model:
        for el in row:

    import IPython; IPython.embed()

def main():
    n, k = input().split(' ')

    model = []
    for _ in range(int( n )): 
        model.append( list(input()) )

    model = np.array( model )
    print( fractal(model, 2 ) )

if __name__ == '__main__':
    main()
