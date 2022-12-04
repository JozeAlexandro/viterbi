

/// @test d
#include "xml_parser.hpp"
#include "coder.hpp"


#include <iostream>

int main()
{
    using namespace nsViterbiCoder;
    const std::string s("/home/alexandr/Useful/programming/c++/Alg/viterbi/doc/testEncoder.xml");
    cXmlParser parser(s);

    cCoder coder( parser );

    coder.testCreateTable();

    std::cout << coder.code( boost::dynamic_bitset<>( 5, 8 ) );



    return 0;
}
