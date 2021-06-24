#include "field.h"

Field::Field()
{
	status = 0;
}

Field::Field(const Field& f)
{
	status = f.status;
}

Field& Field :: operator=(const Field& f)
{
	if (&f != this)
	{
		status = f.status;
	}
	return *this;
}

void Field::setIceFloe()
{
	status = 1;
}

bool Field::getInformation()
{
	return status;
}