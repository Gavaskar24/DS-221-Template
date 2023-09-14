# Generate a matrix with size 100000 with random integers and which has many 0's
# and which can be used to convert into sparse matrix to check computation speed of other codes

import numpy as np
import scipy.sparse as sp
import scipy.io as spio


def main():
    # Generate a matrix with size 100000 with random integers and which has many 0's
    # and which can be used to convert into sparse matrix to check computation speed of other codes
    mat = np.random.randint(0, 100, size=(1000, 10000))
    mat[mat > 10] = 0
    mat = sp.csr_matrix(mat)
    spio.savemat('checker.mat', {'mat': mat})
    # export the matrix to a txt file where each row is a line and each element is separated by a space
    np.savetxt('checker.txt', mat.toarray(), fmt='%d', delimiter=' ')

if __name__ == '__main__':
    main()

