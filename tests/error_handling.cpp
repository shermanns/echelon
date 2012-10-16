#define BOOST_TEST_DYN_LINK

#include <echelon/echelon.hpp>

#define BOOST_TEST_MODULE "error handling"
#include <boost/test/unit_test.hpp>

#include "basic_fixture.hpp"

BOOST_FIXTURE_TEST_CASE( error_handling_test, basic_fixture )
{
    BOOST_CHECK_THROW(root["bar"],echelon::hdf5::can_not_open_object_exception);

    root.create_group("foo");
    BOOST_CHECK_THROW(root.create_group("foo"),echelon::hdf5::symbol_already_exists_exception);
}