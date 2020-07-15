// Example from https://www.boost.org/doc/libs/1_66_0/libs/test/doc/html/boost_test/testing_tools/boost_test_universal_macro.html
#define BOOST_TEST_MODULE boost_test_macro_overview
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( test_macro_overview )
{
  namespace tt = boost::test_tools;
  int a = 1;
  int b = 2;
  BOOST_TEST(a != b - 1);
  BOOST_TEST(a + 1 < b);
  BOOST_TEST(b -1 > a, a << " < " << b - 1 << " does not hold");
  BOOST_TEST(a == b, tt::bitwise());
  BOOST_TEST(a + 0.1 == b - 0.8, tt::tolerance(0.01));
}