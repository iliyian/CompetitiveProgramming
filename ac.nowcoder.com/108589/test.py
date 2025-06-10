def xor_to(k):
    """Compute XOR from 1 to k."""
    mod = k % 4
    if mod == 0:
        return k
    elif mod == 1:
        return 1
    elif mod == 2:
        return k + 1
    else:  # mod == 3
        return 0

def main():
    import sys
    data = sys.stdin.read().split()
    t = int(data[0])
    index = 1
    results = []
    for _ in range(t):
        n = int(data[index])
        m = int(data[index + 1])
        index += 2
        total = n + m
        if total % 4 != 3:
            results.append("-1")
        else:
            # Initialize matrix with zeros
            matrix = [[0] * m for _ in range(n)]
            
            # Set last column for first n-1 rows
            for i in range(n - 1):
                matrix[i][m - 1] = i + 1
            
            # Set last row for first m-1 columns
            for j in range(m - 1):
                matrix[n - 1][j] = n + j + 1
            
            # Compute bottom-right element if needed
            if n >= 1 and m >= 1:
                L = n + 1
                R = n + m - 1
                if L <= R:
                    xor_range = xor_to(R) ^ xor_to(L - 1)
                else:  # When m=1, no c_j to XOR, so xor_range = 0
                    xor_range = 0
                matrix[n - 1][m - 1] = xor_range ^ n
            
            # Format matrix output
            res = []
            for row in matrix:
                res.append(" ".join(map(str, row)))
            results.append("\n".join(res))
    
    # Output all results
    for res in results:
        print(res)

if __name__ == "__main__":
    main()