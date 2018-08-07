def compare_grid(G1, G2):
    for i in range(len(G1)):
        if G1[i] != G2[i]:
            return False
    
    return True

def gridSearch(G, P):
    G_row = len(G)
    G_col = len(G[0])

    P_row = len(P)
    P_col = len(P[0])

    for i in range(G_row - P_row + 1):
        if P[0] in G[i]:
            for j in range(G_col - P_col + 1):
                sub_matrix = [row[j:j + P_col] for row in G[i:i + P_row]]
                if compare_grid(sub_matrix, P):
                    return 'YES'
    
    return 'NO'
