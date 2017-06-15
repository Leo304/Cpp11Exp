#include <string>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/foreach.hpp>
#include "SimpleXML.h"

using namespace std;


SimpleXML::SimpleXML()
{
}


SimpleXML::~SimpleXML()
{
}

int SimpleXML::Execute()
{
	string xml_str( "<table><pairs><pair name=\"One\"><x>1</x><y>1</y></pair><pair name=\"One\"><x>1</x><y>1</y></pair><pair name=\"Two\"><x>2</x><y>4</y></pair><pair name=\"Three\"><x>3</x><y>9</y></pair></pairs></table>" );
	boost::property_tree::ptree pt1(xml_str);
	return 1;
}
