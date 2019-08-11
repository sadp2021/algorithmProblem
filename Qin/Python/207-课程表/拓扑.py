class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        if numCourses is 0 or len(prerequisites) is 0:
            return True
        indeg = [0] * numCourses # 入度
        ver = [[] for _ in range(numCourses)]
        # 计算入度,顺便建图
        for fr,to in prerequisites:
            indeg[to] += 1
            ver[fr].append(to)
        q = []  # 待处理队列
        count = 0  # 安排好的的课程数目
        res = []
        # 寻找度数为0的
        for index, value in enumerate(indeg):
            if value is 0:
                q.append(i)
        while q:  # 为空结束
            v = q.pop()  # 取一个出来点
            # 所有能到达的度数减一，入度为0入队
            for to in ver[v]:
                indeg[to] -= 1
                if indeg[to] is 0:
                    q.append(to)
            # 处理后
            count += 1
            res.append(v)
        return count == numCourses
