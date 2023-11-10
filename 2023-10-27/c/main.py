def kmpProcess(p):
    m = len(p)
    b = [-1]*(m+1)
    i,j = 0,-1
    while i < m:
        while j >= 0 and p[i] != p[j]:
            j = b[j]
        i += 1
        j += 1
        b[i] = j
    return b

def maior_solucao(s):
    pref = kmpProcess(s)
    n = len(s)
    candidato = pref[n]
    while candidato > 0:
        for i in range(1,n):
            if pref[i] == candidato:
                return s[:candidato]
        candidato = pref[candidato]
    return ''



if __name__ == '__main__':
    stg = input()
    aws = maior_solucao( stg )
    if aws:
        print(aws)
    else:
        print('Just a legend')

