
#include "coder.hpp"

using namespace nsViterbiCoder;


cCoder::cCoder( cCoderDescrIface &coderDescr ) :
    mrCoderDescr( coderDescr )
{

}

void cCoder::testCreateTable()
{
    mOutBitCount = mrCoderDescr.getOutBitCount();
    mTable = mrCoderDescr.createTable();
}


boost::dynamic_bitset<> cCoder::code(boost::dynamic_bitset<> data)
{
    reset();

    boost::dynamic_bitset<> codeData;

    const unsigned CODE_LEN = data.size() * mOutBitCount;
    codeData.resize( CODE_LEN );

    for( unsigned bit = 0; bit < data.size(); bit++ )
    {
        unsigned result = input( data[ bit ] );

        for( unsigned orderBit = 0; orderBit < mOutBitCount; ++orderBit )
        {
            codeData[ (bit * mOutBitCount) + orderBit ] = result & ( 1 << orderBit );
        }


    }

    return codeData;
}

boost::dynamic_bitset<> cCoder::deCode(boost::dynamic_bitset<> codeData)
{
    /// остаток от деления на размер кодовый должен = 0

    reset();

    const unsigned result = input( codeData[ 0 ] );

    auto [ zeroInput, unitInput ] = test(); {}

//    auto i = zeroInput.mNextState == unitInput.mNextState ? 1 : 0;

/// @todo expected val...    distanceCount( 0, zeroInput.mOutValue );



    return boost::dynamic_bitset<>();
}



std::pair<const sCoderStateDescr &, const sCoderStateDescr &> cCoder::test()
{
    const auto &zeroVar = mTable.at( crntState )[ 0 ];
    const auto &unitVar = mTable.at( crntState )[ 1 ];

    return std::make_pair(zeroVar, unitVar);
}

unsigned cCoder::input(int bit)
{
    /// @todo create есчли не креат еще
    const auto &stateVar = mTable.at( crntState )[ bit ];
    crntState = stateVar.mNextState;

    return stateVar.mOutValue;
}



unsigned cCoder::distanceCount( unsigned left, unsigned right )
{
    auto xorRes{ left ^ right };

    unsigned distance = 0;
    while( xorRes > 0 )
    {
        if( xorRes & 1 )
        {
            distance++;
        }

        xorRes >>= 1;
    }

    return distance;
}

