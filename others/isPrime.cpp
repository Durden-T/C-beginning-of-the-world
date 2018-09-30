bool isPrime(int n)
{
    if (n == 2)
        return true;
    if (n == 1 || !(n & 1))
        return false;
    int limit = sqrt(n);
    for (int i = 3; i <= limit; i += 2)
        if (!(n % i))
            return false;
    return true;
}