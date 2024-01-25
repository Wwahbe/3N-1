// Wissam Wahbe

#include <climits>
#include <iostream>
#include <stdexcept>
#include <vector>

int maxNum = 0;
int totalSteps = 0;
int oddCounts = 0;
int evenCounts = 0;
bool overflow = false;
std::vector<int> sequence;

int collatz(int n)
{
    if (n == 1)
    {
        sequence.push_back(1);
        return 0;
    }
    if (n > maxNum)
    {
        maxNum = n;
    }
    sequence.push_back(n);
    if (n % 2 == 0)
    {
        evenCounts++;
        n = n / 2;
    }
    else
    {
        oddCounts++;
        n = (3 * n) + 1;
    }
    return 1 + collatz(n);
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        int input;
        std::cout << "Enter a 3n+1 candidate number:";
        std::cin >> input;
        totalSteps = collatz(input);
        std::cout << "Solving 3n+1 - starting value:" << input << std::endl;
        for (int i = 0; i < sequence.size(); i++)
        {
            try
            {
                if (i != 0)
                {
                    if (sequence[i] < 0)
                    {
                        throw std::overflow_error("Integer overflow detected");
                    }
                    std::cout << "->(" << sequence[i] << ")";
                }
                else
                {
                    std::cout << "(" << sequence[i] << ")";
                }
            }
            catch (const std::overflow_error &e)
            {
                std::cerr << "-> ###overflow###" << std::endl;
                std::cerr << "\noverflow detected for n:" << sequence[i - 1]
                          << std::endl;
                std::cerr << "3n + 1:" << sequence[i] << std::endl;
                std::cerr << "SOMETHING BROKE AHHHHHHHHHHHHHHHHHHHHHHHHHHH"
                          << std::endl;
                std::cerr << "overflow" << std::endl;
                overflow = true;
                break;
            }
        }
        if (overflow == false)
        {
            std::cout << std::endl;
            std::cout << "start:" << input << std::endl;
            std::cout << "steps:" << totalSteps << std::endl;
            std::cout << "max:" << maxNum << std::endl;
            std::cout << "odds:" << oddCounts << std::endl;
            std::cout << "evens:" << evenCounts << std::endl;
        }
    }
    else if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            overflow = false;
            maxNum = 0;
            totalSteps = 0;
            oddCounts = 0;
            evenCounts = 0;
            totalSteps = collatz(atoi(argv[i]));
            std::cout << "Solving 3n+1 - starting value:" << atoi(argv[i])
                      << std::endl;
            for (int i = 0; i < sequence.size(); i++)
            {
                try
                {
                    if (i != 0)
                    {
                        if (sequence[i] < 0)
                        {
                            throw std::overflow_error("Integer overflow detected");
                        }
                        std::cout << "->(" << sequence[i] << ")";
                    }
                    else
                    {
                        std::cout << "(" << sequence[i] << ")";
                    }
                }
                catch (const std::overflow_error &e)
                {
                    std::cerr << "-> ###overflow###" << std::endl;
                    std::cerr << "\noverflow detected for n:" << sequence[i - 1]
                              << std::endl;
                    std::cerr << "3n + 1:" << sequence[i] << std::endl;
                    std::cerr << "SOMETHING BROKE AHHHHHHHHHHHHHHHHHHHHHHHHHHH"
                              << std::endl;
                    std::cerr << "overflow" << std::endl;
                    std::cout << std::endl;
                    sequence.clear();
                    overflow = true;
                    break;
                }
            }
            if (overflow == false)
            {
                std::cout << std::endl;
                std::cout << "start:" << atoi(argv[i]) << std::endl;
                std::cout << "steps:" << totalSteps << std::endl;
                std::cout << "max:" << maxNum << std::endl;
                std::cout << "odds:" << oddCounts << std::endl;
                std::cout << "evens:" << evenCounts << std::endl;
                sequence.clear();
                std:: cout << std::endl;
            }
        }
    }
    return 0;
}