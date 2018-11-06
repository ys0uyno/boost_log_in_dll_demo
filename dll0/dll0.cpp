// dll0.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <Windows.h>
#include "../common/boost_logger.h"

void dll0_func0()
{
	BOOST_LOG_SEV(my_logger::get(), boost::log::trivial::info)
		<< "dll0_func0 called boost log";
}

void dll0_func1()
{
	BOOST_LOG_SEV(my_logger::get(), boost::log::trivial::info)
		<< "dll0_func1 called boost log";
}
