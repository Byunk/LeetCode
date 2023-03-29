class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        res = []
        minHeap = []
        for point in points:
            heapq.heappush(minHeap, Point(point))
        for i in range(k):
            res.append(heapq.heappop(minHeap).point)
        return res

class Point:
    def __init__(self, point):
        self.point = point

    def __lt__(self, other):
        if self.dist(self.point) <= self.dist(other.point):
            return True
        else:
            return False
        
    def dist(self, point):
        return math.sqrt(point[0]**2 + point[1]**2)