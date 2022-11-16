/** ****************************************************************************
 * @brief Исходные коды парсера xml файлов, описывающих состояния кодера.
 * @file xml_parser.cpp
 * @author Петров А.С.
 * ****************************************************************************/

/* --- Подключение заголовочных файлов -------------------------------------- */

// Файлы проекта
#include "xml_parser.hpp" // Объявление класса

// Boost
#include <boost/property_tree/ptree.hpp> /// @todo
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

/// @todo
namespace pt = boost::property_tree;
//using namespace boost::property_tree;

// Стандартная библиотека С++
#include <istream> // Потоковый ввод

namespace nsViterbiCoder
{



/* --- Определение конструкторов/деструкторов ------------------------------- */

cXmlParser::cXmlParser( const std::string &fileXmlName ) : mrFileXml( fileXmlName )
{

}

cXmlParser::~cXmlParser()
{

}


/* --- Определение интерфейсных функций cCoderDescrIface -------------------- */

bitCount_t cXmlParser::getOutBitCount()
{
    if( !checkXmlFile() )
    {
        /// @todo throw "need it?";
    }

    /// @test ngcode
    return mPropTree.get< bitCount_t >( "ngCode.outBitCount" );
}

table_t cXmlParser::createTable()
{
    if( !checkXmlFile() )
    {
        /// @todo throw "need it?";
    }

    table_t table;

    for( const auto &node : mPropTree.get_child( "ngCode" ) )
    {
        if( node.first == "node" )
        {
            unsigned state( node.second.get<int>( "state" ) );
            std::array< sCoderStateDescr, 2 > meaning;

            for( const auto &nodeChild : node.second.get_child("") )
            {
                if( nodeChild.first == "input" )
                {
                    const unsigned inputValue( nodeChild.second.get<int>("<xmlattr>.inputValue") );
                    const unsigned output( nodeChild.second.get<int>("output" ) );
                    const unsigned nextState( nodeChild.second.get<int>("nextState" ) );

                    meaning[ inputValue ] = sCoderStateDescr{ nextState, output };
                }

            }
            table[ state ] = meaning;
        }

    }

    return table;
}

/* --- Определение приватных методов ---------------------------------------- */

bool cXmlParser::checkXmlFile()
{
    static bool isFileValid = true;

    if( !misFileChecked )
    {
        /// @todo Проверка файла на валидность XML... Хть минимальная
        misFileChecked = true;
        pt::read_xml( mrFileXml, mPropTree );
    }


    return isFileValid;
}



} // nsViterbiCoder
