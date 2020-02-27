def Solution(d:int, f:int, target:int) -> int:
    dp = [[1 if (j is 1 and i <= f) else 0 for i in range(target+1)] for j in range(d+1)]
    for i in range(2,d+1):
        for j in range(1,target+1):
            dp[i][j] = sum(dp[i-1][max(1,j-f):(j-1)+1])
    return dp[-1][-1] % (10 ** 9 + 7)
        
def main():
    d,f,target = map(int, input().split())
    print(Solution(d,f,target))

if __name__ == '__main__':
    main()
