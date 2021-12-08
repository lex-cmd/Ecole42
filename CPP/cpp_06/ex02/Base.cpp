#include "Base.hpp"

Base::Base()
{
	name = "F";
}

Base::Base(std::string name) : name(name)
{

}

Base::~Base()
{

}

std::string Base::getName() const
{
	return (this->name);
}

std::ostream	&operator<<(std::ostream &out, const Base &other)
{
	out << other.getName();
	return (out);
}
