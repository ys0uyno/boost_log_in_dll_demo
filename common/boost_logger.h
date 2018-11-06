#pragma once

#include <boost/log/sources/global_logger_storage.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/sinks/debug_output_backend.hpp>

BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT(my_logger,
	boost::log::sources::severity_logger_mt<boost::log::trivial::severity_level>);
