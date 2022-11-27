

/// @test d
#include "xml_parser.hpp"
#include "coder.hpp"

int main()
{
    using namespace nsViterbiCoder;
    const std::string s("/home/alexandr/Useful/programming/c++/Alg/viterbi/doc/testEncoder.xml");
    cXmlParser parser(s);

    cCoder coder( parser );
    coder.testCreateTable();


    return 0;
}
