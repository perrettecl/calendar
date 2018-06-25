#include "sqlerror.h"

SqlError::SqlError(int errorCode) : m_errorCode(errorCode)
{
	
}

const char* SqlError::what() const throw()
{
	return sqlite3_errstr(m_errorCode);
}

