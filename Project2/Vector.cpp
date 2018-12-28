#include "Vector.h"
#include <exception>

int Vector::GetThis(int value)
{
	if (value < 0)
		throw new exception("Индекс не может быть отрицательным");
	if (value >= elems.size())
		throw new exception("Выход за пределы границы вектора");
	return elems.at(value);
}

void Vector::PushBack(int value) 
{
	elems.push_back(value);
}

void Vector::PopBack()
{
	if (elems.size() > 0)
	{
		elems.pop_back();
	}
	else
	{
		throw new exception("Вектор пуст");
	}
}

bool Vector::IsEmpty()
{
	return elems.empty();
}

void Vector::Clear()
{
	elems.clear();
}

Vector::Vector()
{
	elems = vector<int>();
}


Vector::~Vector()
{
}
