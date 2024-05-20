
// Function to calculate Simple Recursive Top-Down algorithm without Memoization
//int simpleMaxProfit(int n, int prices[], int path[]) {
//    if (n < MIN_DIMENSION || n % BLOCK_SIZE_MULTIPLE != 0) {
//        return 0;
//    }
//
//    int max_profit = 0;
//    int best_cut = 0;
//
//    for (int i = MIN_DIMENSION; i <= n / 2; i += MIN_DIMENSION) {
//        int current_profit = simpleMaxProfit(i, prices, path) + simpleMaxProfit(n - i, prices, path);
//        if (current_profit > max_profit) {
//            max_profit = current_profit;
//            best_cut = i;
//        }
//    }
//
//    for (int j = MIN_DIMENSION; j <= n / 2; j += MIN_DIMENSION) {
//        int current_profit = simpleMaxProfit(j, prices, path) + simpleMaxProfit(n - j, prices, path);
//        if (current_profit > max_profit) {
//            max_profit = current_profit;
//            best_cut = j;
//        }
//    }
//
//    if (max_profit > prices[n / BLOCK_SIZE_MULTIPLE]) {
//        path[0] = best_cut;
//        path[1] = n - best_cut;
//    }
//    else {
//        path[0] = n / BLOCK_SIZE_MULTIPLE;
//    }
//
//    return max_profit;
//}

//int main() {
//    int n;
//    std::cin >> n;
//
//    int prices[MAX_N / BLOCK_SIZE_MULTIPLE + 1] = { 0 };
//    int path[2] = { 0 };
//
//    // Read prices for specific sizes
//    int size1, size2, price;
//    while (std::cin >> size1 >> size2 >> price && (size1 + size2 + price > 0)) {
//        prices[(size1 + size2) / BLOCK_SIZE_MULTIPLE] = price;
//    }
//
//    // Task 1: Calculate and print the result for Simple Recursive Top-Down algorithm without Memoization
//    std::cout << "Task 1 Result: " << simpleMaxProfit(n, prices, path) << " units\n";
//    std::cout << "Path: " << path[0] << " " << path[1] << "\n";
//
//    //// Task 2: Calculate and print the result for Recursive Top-Down algorithm with Memoization
//    //int memo[MAX_N + 1];
//    //std::fill(memo, memo + MAX_N + 1, -1);
//    //std::cout << "Task 2 Result: " << memoizedMaxProfit(n, prices, memo, path) << " units\n";
//    //std::cout << "Path: " << path[0] << " " << path[1] << "\n";
//
//    //// Task 3: Calculate and print the result for Iterative Bottom-Up algorithm with Memoization
//    //std::cout << "Task 3 Result: " << bottomUpMaxProfit(n, prices, path) << " units\n";
//    //std::cout << "Path: " << path[0] << " " << path[1] << "\n";
//
//    //// Task 4: Calculate and print the result for Optimized storage in the Iterative algorithm
//    //std::cout << "Task 4 Result: " << optimizedBottomUpMaxProfit(n, prices, path) << " units\n";
//    //std::cout << "Path: " << path[0] << " " << path[1] << "\n";
//
//    return 0;
//}

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int MIN_DIMENSION = 5;
const int BLOCK_SIZE_MULTIPLE = 100;
const int MAX_N = 1000;



// Function to calculate Simple Recursive Top-Down algorithm without Memoization
int simpleMaxProfit(int n, int prices[], int path[]) 
{
    if (n < MIN_DIMENSION || n % BLOCK_SIZE_MULTIPLE != 0)
    {
        return 0;
    }

    int max_profit = 0;
    int best_cut = 0;

    for (int i = MIN_DIMENSION; i <= n / 2; i += MIN_DIMENSION) 
    {
        int current_profit = simpleMaxProfit(i, prices, path) + simpleMaxProfit(n - i, prices, path);
        if (current_profit > max_profit) 
        {
            max_profit = current_profit;
            best_cut = i;
        }
    }

    for (int j = MIN_DIMENSION; j <= n / 2; j += MIN_DIMENSION) 
    {
        int current_profit = simpleMaxProfit(j, prices, path) + simpleMaxProfit(n - j, prices, path);
        if (current_profit > max_profit)
        {
            max_profit = current_profit;
            best_cut = j;
        }
    }

    if (max_profit > prices[n / BLOCK_SIZE_MULTIPLE]) 
    {
        path[0] = best_cut;
        path[1] = n - best_cut;
    }
    else
    {
        path[0] = n / BLOCK_SIZE_MULTIPLE;
    }

    return max_profit;
}

int memoizedMaxProfit(int n, int prices[], int memo[], int path[])
{
    if (n < MIN_DIMENSION || n % BLOCK_SIZE_MULTIPLE != 0)
    {
        return 0;
    }

    if (memo[n] != -1)
    {
        return memo[n];
    }

    int max_profit = 0;
    int best_cut = 0;

    for (int i = MIN_DIMENSION; i <= n / 2; i += MIN_DIMENSION)
    {
        int current_profit = memoizedMaxProfit(i, prices, memo, path) + memoizedMaxProfit(n - i, prices, memo, path);
        if (current_profit > max_profit)
        {
            max_profit = current_profit;
            best_cut = i;
        }
    }

    for (int j = MIN_DIMENSION; j <= n / 2; j += MIN_DIMENSION)
    {
        int current_profit = memoizedMaxProfit(j, prices, memo, path) + memoizedMaxProfit(n - j, prices, memo, path);
        if (current_profit > max_profit) 
        {
            max_profit = current_profit;
            best_cut = j;
        }
    }

    if (max_profit > prices[n / BLOCK_SIZE_MULTIPLE]) 
    {
        path[0] = best_cut;
        path[1] = n - best_cut;
    }
    else
    {
        path[0] = n / BLOCK_SIZE_MULTIPLE;
    }

    memo[n] = max_profit;
    return max_profit;
}

int bottomUpMaxProfit(int n, int prices[], int path[])
{
    int memo[MAX_N + 1];
    fill(memo, memo + MAX_N + 1, 0);

    for (int i = MIN_DIMENSION; i <= n; i += MIN_DIMENSION)
    {
        int max_profit = 0;
        int best_cut = 0;

        for (int j = MIN_DIMENSION; j <= i / 2; j += MIN_DIMENSION) 
        {
            int current_profit = memo[j] + memo[i - j];
            if (current_profit > max_profit)
            {
                max_profit = current_profit;
                best_cut = j;
            }
        }

        for (int k = MIN_DIMENSION; k <= n / 2; k += MIN_DIMENSION) 
        {
            int current_profit = memo[k] + memo[n - k];
            if (current_profit > max_profit)
            {
                max_profit = current_profit;
                best_cut = k;
            }
        }

        if (max_profit > prices[i / BLOCK_SIZE_MULTIPLE]) 
        {
            path[0] = best_cut;
            path[1] = i - best_cut;
        }
        else
        {
            path[0] = i / BLOCK_SIZE_MULTIPLE;
        }

        memo[i] = max_profit;
    }

    return memo[n];
}

int optimizedBottomUpMaxProfit(int n, int prices[], int path[])
{
    int memo[MAX_N + 1];
    fill(memo, memo + MAX_N + 1, 0);

    for (int i = MIN_DIMENSION; i <= n; i += MIN_DIMENSION) 
    {
        int max_profit = 0;
        int best_cut = 0;

        for (int j = MIN_DIMENSION; j <= i / 2; j += MIN_DIMENSION) 
        {
            int current_profit = memo[j] + memo[i - j];
            if (current_profit > max_profit) 
            {
                max_profit = current_profit;
                best_cut = j;
            }
        }

        for (int k = MIN_DIMENSION; k <= n / 2; k += MIN_DIMENSION)
        {
            int current_profit = memo[k] + memo[n - k];
            if (current_profit > max_profit)
            {
                max_profit = current_profit;
                best_cut = k;
            }
        }

        if (max_profit > prices[i / BLOCK_SIZE_MULTIPLE])
        {
            path[0] = best_cut;
            path[1] = i - best_cut;
        }
        else
        {
            path[0] = i / BLOCK_SIZE_MULTIPLE;
        }

        memo[i] = max_profit;
    }

    return memo[n];
}

int main()
{

    // Task 1: Calculate and print the result for Simple Recursive Top-Down algorithm without Memoization
//    std::cout << "Task 1 Result: " << simpleMaxProfit(n, prices, path) << " units\n";
//    std::cout << "Path: " << path[0] << " " << path[1] << "\n";
//
//    //// Task 2: Calculate and print the result for Recursive Top-Down algorithm with Memoization
//    //int memo[MAX_N + 1];
//    //std::fill(memo, memo + MAX_N + 1, -1);
//    //std::cout << "Task 2 Result: " << memoizedMaxProfit(n, prices, memo, path) << " units\n";
//    //std::cout << "Path: " << path[0] << " " << path[1] << "\n";
//
//    //// Task 3: Calculate and print the result for Iterative Bottom-Up algorithm with Memoization
//    //std::cout << "Task 3 Result: " << bottomUpMaxProfit(n, prices, path) << " units\n";
//    //std::cout << "Path: " << path[0] << " " << path[1] << "\n";
//
//    //// Task 4: Calculate and print the result for Optimized storage in the Iterative algorithm
//    //std::cout << "Task 4 Result: " << optimizedBottomUpMaxProfit(n, prices, path) << " units\n";
//    //std::cout << "Path: " << path[0] << " " << path[1] << "\n";

    ifstream inputFile("TestCase5.txt");

    if (!inputFile.is_open()) 
    {
        cerr << "Error: Unable to open the file.\n";
        return 1;
    }

    int n;
    inputFile >> n;

    int prices[MAX_N / BLOCK_SIZE_MULTIPLE + 1] = { 0 };
    int path[2] = { 0 };

    int size1, size2, price;
    while (inputFile >> size1 >> size2 >> price && (size1 + size2 + price > 0)) {
        prices[(size1 + size2) / BLOCK_SIZE_MULTIPLE] = price;
    }

    cout << "Task 1 Result: " << simpleMaxProfit(n, prices, path) << " units\n";
    cout << "Path: " << path[0] << " " << path[1] << "\n";

    int memo[MAX_N + 1];
    fill(memo, memo + MAX_N + 1, -1);
    cout << "Task 2 Result: " << memoizedMaxProfit(n, prices, memo, path) << " units\n";
    cout << "Path: " << path[0] << " " << path[1] << "\n";

    cout << "Task 3 Result: " << bottomUpMaxProfit(n, prices, path) << " units\n";
    cout << "Path: " << path[0] << " " << path[1] << "\n";

    cout << "Task 4 Result: " << optimizedBottomUpMaxProfit(n, prices, path) << " units\n";
    cout << "Path: " << path[0] << " " << path[1] << "\n";

    inputFile.close();

    return 0;
}
