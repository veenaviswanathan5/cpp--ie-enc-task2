// Print the Fibonacci series sum for n numbers using recursion.

#include <iostream>

// Recursive function to calculate Fibonacci series
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to calculate the sum of the first n Fibonacci numbers
int fibonacciSum(int n) {
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        sum += fibonacci(i);
    }

    return sum;
}

int main() {
    int n;

    // Get user input for the number of Fibonacci numbers
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    // Calculate and display the sum of the first n Fibonacci numbers
    std::cout << "Sum of the first " << n << " Fibonacci numbers: " << fibonacciSum(n) << std::endl;

    return 0;
}
