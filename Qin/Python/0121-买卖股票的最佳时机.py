def main():
    def maxProfit(prices: list) -> list:
        if len(prices) is 0:
            return 0
        maxp, minc = 0, prices[0]
        for c in prices:
            if c < minc :
                minc = c
            maxp = max(maxp, c - minc)
        return maxp
    print(maxProfit([7,1,5,3,6,4]))

if __name__ == '__main__':
    main()
