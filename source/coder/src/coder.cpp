
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

