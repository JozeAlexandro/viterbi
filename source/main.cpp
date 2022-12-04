

/// @test d
#include "xml_parser.hpp"
#include "coder.hpp"


#include <iostream>


unsigned getBlockValue(boost::dynamic_bitset<> &bs)
{
    /// @todo Проверки
    /// @todo Универсальность
    unsigned val = bs[ 0 ] | ( bs[ 1 ] << 1 );


    bs >>= 2;
    bs.pop_back();
    bs.pop_back();

    return val;
}



int main()
{
    using namespace nsViterbiCoder;
    const std::string s("/home/alexandr/Useful/programming/c++/Alg/viterbi/doc/testEncoder.xml");
    cXmlParser parser(s);

    cCoder coder( parser );

    coder.testCreateTable();

   // std::cout << coder.code( boost::dynamic_bitset<>( 5, 8 ) );

    boost::dynamic_bitset<> tt( 5, 6 );

    std::cout << "Init "<< tt << std::endl;

    auto val = getBlockValue( tt );

    std::cout << "Value " << val << std::endl;
    std::cout << "Remain block " << tt << std::endl;

    return 0;
}
