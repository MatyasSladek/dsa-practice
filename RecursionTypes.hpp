#ifndef RECURSIONTYPES_HPP
#define RECURSIONTYPES_HPP

class RecursionTypes {
public:
    /**
     * @brief Linear recursion example: factorial implementation
     * Time complexity: O(n), Space complexity: O(n)
     * @param n Non-negative integer to compute factorial for
     */
    int factorial(int n);

    /**
     * @brief Tail recursion example: Euclidean algorithm for GCD
     * Time complexity: O(log(min(a,b))), Space complexity: O(log(min(a,b)))
     * @param a First positive integer
     * @param b Second positive integer
     */
    int gcd(int a, int b);

    /**
     * @brief Tree recursion example: Fibonacci number implementation
     * Time complexity: O(2^n), Space complexity: O(n)
     * @param n Non-negative integer position in Fibonacci sequence
     */
    int fibonacci(int n);

    /**
     * @brief Nested recursion example: Ackermann function implementation
     * Time complexity: O(A(m,n)), Space complexity: O(A(m,n))
     * @param m Non-negative integer (first parameter)
     * @param n Non-negative integer (second parameter)
     */
    int ackermann(int m, int n);

};

#endif //RECURSIONTYPES_HPP