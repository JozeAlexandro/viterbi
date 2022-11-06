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

namespace nsViterbiCoder
{

/// @todo
namespace pt = boost::property_tree;

/* --- Определение конструкторов/деструкторов ------------------------------- */

cXmlParser::cXmlParser(const std::string &fileXmlName)
{

}

cXmlParser::~cXmlParser()
{

}


/* --- Определение интерфейсных функций cCoderDescrIface -------------------- */

bitCount_t cXmlParser::getOutBitCount()
{

}

table_t cXmlParser::createTable()
{

}



} // nsViterbiCoder
