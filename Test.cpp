/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Shalev Asor
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good snowman code-similar type") {
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(22222222)) == nospaces("___\n.....\n(o.o)\n\(] [)/\n(" ")"));
	CHECK(nospaces(snowman(33333333)) == nospaces(" _ \n/_\\n(O_O)\n/(> <)\\n(___)"));
	CHECK(nospaces(snowman(44444444)) == nospaces(" ___ \n(_*_)\n(- -)\n(   )\n(   )"));
	CHECK(nospaces(snowman(12341234)) == nospaces(" _===_\n(O.-)\n<(> <)/\n(   )"));
	CHECK(nospaces(snowman(11112222)) == nospaces(" _===_\n(.,.)\n\(] [)/\n(" ")"));
	CHECK(nospaces(snowman(11113333)) == nospaces(" _===_\n(.,.)\n/(> <)\\n(___)"));
	CHECK(nospaces(snowman(11114444)) == nospaces(" _===_\n(.,.)\n(   )\n(   )"));
	CHECK(nospaces(snowman(44441111)) == nospaces("  ___ \n(_*_)\n(- -)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(44442222)) == nospaces("  ___ \n(_*_)\n(- -)\n\(] [)/\n(" ")"));
	CHECK(nospaces(snowman(44443333)) == nospaces("  ___ \n(_*_)\n(- -)\n/(> <)\\n(___)"));
	CHECK(nospaces(snowman(22221111)) == nospaces("___\n.....\n(o.o)\n<( : )>\n( : )"));
	CHECK(nospaces(snowman(22223333)) == nospaces("___\n.....\n(o.o)\n/(> <)\\n(___)"));
	CHECK(nospaces(snowman(22224444)) == nospaces("___\n.....\n(o.o)\n(   )\n(   )"));
	CHECK(nospaces(snowman(11221122)) == nospaces("_===_\n(o,o)\n<(] [)>\n(" ")"));
	CHECK(nospaces(snowman(22112211)) == nospaces("___\n.....\n(...)\n\( : )/\n( : )"));
	
}

TEST_CASE("good snowman code-different types"){
    CHECK(nospaces(snowman(33142231)) == nospaces(" _ \n/_\\n(.__)\n\(> <)/\n( : )"));
	CHECK(nospaces(snowman(23331444)) == nospaces("___\n.....\n(O_O)\n<(   )\n(   )"));
	CHECK(nospaces(snowman(42231314)) == nospaces(" ___ \n(_*_)\n(o.O)\n<( : )\\n(   )"));
	CHECK(nospaces(snowman(33322211)) == nospaces("_ \n/_\\n(O_o)\n\( : )/\n( : )"));
	CHECK(nospaces(snowman(12121212)) == nospaces("_===_\n(..o)\n<( : )/\n(" ")"));
	CHECK(nospaces(snowman(21212121)) == nospaces("___\n.....\n(o,.)\n\(] [)>\n( : )"));
	CHECK(nospaces(snowman(13122113)) == nospaces("_===_\n(._o)\n\( : )>\n(___)"));
	CHECK(nospaces(snowman(44132213)) == nospaces("  ___ \n(_*_)\n(. O)\n\( : )/\n(___)"));
	CHECK(nospaces(snowman(33331244)) == nospaces(" _ \n/_\\n(O_O)\n<(   )/\n(   )"));
	CHECK(nospaces(snowman(44213121)) == nospaces("  ___ \n(_*_)\n(o .)\n/(] [)>\n( : )"));


}
/**
 * This test verify the following edge cases: 
 * input length should be 8 (0-7 should throw exception )
 * only numbers  in [1,4] range
 * 15 cases
 */ 
TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(0));
	CHECK_THROWS(snowman(1));
	CHECK_THROWS(snowman(11));
	CHECK_THROWS(snowman(111));
	CHECK_THROWS(snowman(1111));
	CHECK_THROWS(snowman(11111));
	CHECK_THROWS(snowman(111111));
	CHECK_THROWS(snowman(1111111));
	CHECK_THROWS(snowman(55555555));
	CHECK_THROWS_AS(snowman(22222225),std::out_of_range);
	CHECK_THROWS_AS(snowman(12341281),std::out_of_range);
	CHECK_THROWS_AS(snowman(55555555),std::out_of_range);
	CHECK_THROWS_AS(snowman(61234123),std::out_of_range);
	CHECK_THROWS_AS(snowman(22341229),std::out_of_range);
	CHECK_THROWS_AS(snowman(01233341),std::out_of_range);

    
}


/* Add more test cases here */