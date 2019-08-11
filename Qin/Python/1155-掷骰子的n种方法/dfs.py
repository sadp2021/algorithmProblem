global count


def dfs(d:int, f:int, target:int, nowdice:int, nowsum:int):
    global count
    if nowdice < d:
        for i in range(1, min(f, target-nowsum)+1):
            dfs(d,f,target,nowdice+1,nowsum+i)
        
    if nowdice == d and nowsum == target:
        count += 1
        

def solution(d:int, f:int, target:int):
    global count
    if target < d:
        return 0
    dfs(d,f,target,0,0)
    return count


def main():
    global count
    count = 0
    d, f, target = map(int, input().split())
    print(solution(d,f,target))


if __name__ == '__main__':
    main()
