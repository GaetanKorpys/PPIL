#include "Exception.h"

ostream& operator << (ostream& os, const Exception& e)
{
	os << e.getMessage() << endl;
	return os;
}