#ifndef _CODER_HPP_
#define _CODER_HPP

#include "coder_types.hpp"
#include "coder_descr_iface.hpp"

#include <memory>

#include <boost/dynamic_bitset.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

namespace nsViterbiCoder
{

namespace pt = boost::property_tree;
/// @bug
using namespace nsViterbiCoder;

class cCoder final
{
public:
   /* cCoder() = delete;
    ~cCoder() = default;
    cCoder( const cCoder &rght ) = default;
    cCoder( const cCoder &&rght ) = default;
    const cCoder & operator = ( const cCoder &rght ) = default;*/

    cCoder( cCoderDescrIface &coderDescr );

    /// @todo Это должно быть неявно, скрыто и тыды
    /// @todo Должна быть возможность изменить mrCoderDescr
    void testCreateTable();


    boost::dynamic_bitset<> code( boost::dynamic_bitset<> data );
    boost::dynamic_bitset<> deCode(boost::dynamic_bitset<> codeData );


    /// @todo Не уверен, что должны быть тут, а если тут , то нуэно докуметировать кода сбрасываются
    unsigned input( int bit );
    void reset() { crntState = 0; } /// @todo Добавить возможность сброса таблицы и возврата к предыдущей и тд..

    unsigned getBitCount() const { return mOutBitCount; }

private:


    /// @todo имя id_t ...?
    /// @brief Текущее состояние кодера.
    nsViterbiCoder::id_t crntState = 0;

    bitCount_t mOutBitCount;
    table_t mTable;

    /// @todo
    cCoderDescrIface & mrCoderDescr;


    ///
    unsigned distanceCount( unsigned left, unsigned right );

    std::pair<const sCoderStateDescr &, const sCoderStateDescr &> test();
};

}




#endif // _CODER_HPP
