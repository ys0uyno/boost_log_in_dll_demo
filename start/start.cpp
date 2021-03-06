// start.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <Windows.h>
#include <iostream>
#include "../common/boost_logger.h"

typedef void(*DLL0_FUNC0)();
typedef void(*DLL0_FUNC1)();

int main()
{
	boost::log::add_console_log(
		std::clog,
		boost::log::keywords::format = (
			boost::log::expressions::stream << "[custom format] "
			<< boost::log::expressions::smessage
			)
	);

	typedef boost::log::sinks::synchronous_sink< boost::log::sinks::debug_output_backend > sink_t;
	boost::shared_ptr< sink_t > sink(new sink_t());
	boost::log::core::get()->add_sink(sink);

	BOOST_LOG_SEV(my_logger::get(), boost::log::trivial::info) << "from main()";

	HMODULE hmod_dll0 = LoadLibrary(L"dll0");
	if (hmod_dll0)
	{
		DLL0_FUNC0 d0f0 = (DLL0_FUNC0)GetProcAddress(hmod_dll0, "dll0_func0");
		if (d0f0)
		{
			d0f0();
		}

		DLL0_FUNC1 d0f1 = (DLL0_FUNC1)GetProcAddress(hmod_dll0, "dll0_func1");
		if (d0f1)
		{
			d0f1();
		}

		FreeLibrary(hmod_dll0);
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
