import sys


def multiply(A, B):
    Arow, Acol = len(A), len(A[0])
    Brow, Bcol = len(B), len(B[0])

    assert Acol == Brow
    ans = [[0.0] * Bcol for _ in range(Arow)]

    for i in range(Bcol):
        for j in range(Arow):
            for k in range(Acol):
                ans[j][i] += B[k][i] * A[j][k]
    
    return ans

def transpose_matrix(A):
    Arow, Acol = len(A), len(A[0])
    ans = [[A[i][j] for i in range(Arow)] for j in range(Acol)]
    return ans

def submatrix(A, i, j):
    m, n = len(A), len(A[0])
    C = [[A[x][y] for y in range(n) if y!=j] for x in range(m) if x!= i]
    return C

def det(A):
    assert len(A) >= 1 and len(A[0]) >= 1
    m, n = len(A), len(A[0])
    assert m == n
    if m == 1 and n == 1:
        return A[0][0]

    else:
        value = 0
        for j in range(n):
            value += ((-1) ** (j+2)) * A[0][j] * det(submatrix(A, 0, j))
        return value

def inverse(A):
    m, n = len(A), len(A[0])
    C = [[0 for _ in range(n)] for _ in range(m)]
    d = det(A)
    for i in range(m):
        for j in range(n):
            if m == 1 and n == 1:
                C[i][j] = 1
            else:
                C[i][j] = ((-1) ** (i+j+2)) * det(submatrix(A, j, i))
                
            C[i][j] /= d

    return C


# input_data = ["[1,2]", "[3;4]"]

input_data = list()

for line in sys.stdin:
    input_data.append(line.strip())

A = input_data[0][1:-1].split(';')
A = [a.strip().split(',') for a in A]

A = [[float(it) for it in a] for a in A]

b = input_data[1][1:-1].split(';')
b = [[float(it)] for it in b]

rst = multiply(transpose_matrix(A), A)
assert len(rst) == len(rst[0])
rst = inverse(rst)

rst = multiply(rst, transpose_matrix(A))
rst = multiply(rst, b)
rst = [str(int(s[0] + 0.5)) for s in rst]
rst = ';'.join(rst)
rst = '['+rst+']'
print(rst)


