#include "main.hpp"

int check_numbers(char *nbr)
{
    char str[] = "1234567890";
    int i = 0;
    int j = 0;
    int find = 0;
    if (atoi(nbr) < 0)
        return (0);
    if (atol(nbr) > 2147483647)
        return (0);
    while (nbr[i])
    {
        j = 0;
        find = 0;
        while (str[j])
        {
            if (nbr[i] == str[j])
                find = 1;
            j++;
        }
        if (!find)
            return (0);
        i++;
    }
    if (i > 10)
        return (0);
    return (1);
}
int main(int ac, char **av)
{
	std::vector<int> vec;
	std::deque<int> deq;
	clock_t start, end;
    double elapsed_time;


	if (ac < 3)
	{
		std::cout << "Please give me a list im born to sort things\n";
		return (0);
	}

	for (int i = 1; i  < ac; i++) {
        if (!check_numbers(av[i])){
            std::cout << "Error\n";
            return (0);
        }

		vec.push_back(atoi(av[i]));
        deq.push_back(atoi(av[i]));
    }
    std::cout << "Before : ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
    start = clock();
	vec = m_i_sort_vec(vec);
    end = clock();
    std::cout << "After : ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
    elapsed_time = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
    std::cout << "Elapsed time with vector " << elapsed_time << " milliseconds" << std::endl;

    start = clock();
    deq = m_i_sort_deque(deq);
    end = clock();
    elapsed_time = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
    std::cout << "Elapsed time with dqueue " << elapsed_time << " milliseconds" << std::endl;
    
	return (0);
}
