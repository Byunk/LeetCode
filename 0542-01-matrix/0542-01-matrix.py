class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        res = [[-1 for i in range(n)] for j in range(m)]
        visited = [[False for i in range(n)] for j in range(m)]

        queue = []
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 0:
                    queue.append((i, j))
                    visited[i][j] = True
        
        dr = [0, 1, 0, -1]
        dc = [1, 0, -1, 0]
        dis = 0
        while queue:
            l = len(queue)
            for j in range(l):
                pos = queue[j]
                res[pos[0]][pos[1]] = dis
                for i in range(4):
                    nr = pos[0] + dr[i]
                    nc = pos[1] + dc[i]
                    if nr < 0 or nc < 0 or nr >= m or nc >= n or res[nr][nc] != -1 or visited[nr][nc]:
                        continue
                    visited[nr][nc] = True
                    queue.append((nr, nc))
            
            while l > 0:
                queue.pop(0)
                l -= 1
            dis += 1
        return res
