def can_make_sum(S, x, denominations):
    # Initialize dp table
    dp = [[False] * (S + 1) for _ in range(x + 1)]
    
    # Base case: It's possible to make a sum of 0 with 0 coins
    dp[0][0] = True
    
    # Fill the table
    for coin in denominations:
        for i in range(1, x + 1):
            for j in range(coin, S + 1):
                dp[i][j] = dp[i][j] or dp[i - 1][j - coin]
    
    # Check if it's possible to make the sum S using x coins
    return dp[x][S]

# Example usage:
S = 27  # Sum to check
x = 4   # Number of coins
denominations = [1, 3, 6, 10, 15]  # Coin denominations
print(can_make_sum(S, x, denominations))  # Output: True
