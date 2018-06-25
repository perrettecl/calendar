#ifndef SQLERROR_H
#define SQLERROR_H

#include <stdexcept>
#include "sqlite3.h"
#include <string>

class SqlError : public std::exception 
{
	private: 
		int m_errorCode;

	public:
		SqlError(int errorCode);
		virtual const char* what() const throw();
};

#endif //SQLERROR_H