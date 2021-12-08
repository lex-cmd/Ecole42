#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
	uintptr_t	saver;

	ptr->content = "a b c d e f g h i j k l m n o p q r s t u v w x y z";
	saver = reinterpret_cast<uintptr_t>(ptr);
	return (saver);
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int	errord()
{
	std::cout << "new error" << std::endl;
	return (-1);
}

int main()
{
	Data		*data = new (Data);
	uintptr_t	saver;

	if (!data)
		return (errord());
	saver = serialize(data);
	Data	*data_new;
	data_new = deserialize(saver);
	std::cout << data_new->content << std::endl;
	delete data_new;
}
