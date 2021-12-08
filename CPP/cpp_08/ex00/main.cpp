#include "easyfind.hpp"

int main()
{
    srand(time(NULL));

    int find_number = rand() % 100;
    std::vector<int> vec_num;
    vec_num.reserve(30);
    for (int i = 0; i < 30; i++)
        vec_num.push_back(rand() % 100);
    for (int i = 0; i < 30; i++)
		std::cout << vec_num[i] << " ";
	std::cout << std::endl;
	std::cout << "search: " << find_number << std::endl;
    std::vector<int>::iterator it = easyfind(vec_num, find_number);
	if (*it != find_number)
		std::cout << "match not found: " << find_number << std::endl;
	else
		std::cout << "match found: " << find_number << std::endl;
    return (0);
}