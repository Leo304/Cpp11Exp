#ifdef _AIX
#include <array>
#else
#include <boost/array.hpp>
#endif

#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include "ArrayItem.h"
//using namespace std;
#ifndef _AIX
//using namespace boost;
#endif

static void make_unique(std::vector<NuNu> &v )
{
    //std::unordered_map<int, NuNu> m;
    //for (std::vector<NuNu>::iterator it = v.begin(); it != v.end(); ++it)
    //{

    //}

    //
    //v.assign(s1.begin(), s1.end());
}

int ArrayItem::Execute() { 
#ifdef _AIX
	typedef std::tr1::array<std::string, 3> array;
#else	
	typedef boost::array<std::string, 3> array;
#endif
	array a;

	a[0] = "cat";
	a.at(1) = "shark";
	*a.rbegin() = "spider";

	std::sort(a.begin(), a.end());

	for (size_t i = 0; i < a.size(); i++ )
		std::cout << a[i] << std::endl;

	std::cout << a.size() << std::endl;
	std::cout << a.max_size() << std::endl;

    std::vector<int> v1;
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(5);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(5);
    v1.push_back(5);
    v1.push_back(4);
    v1.push_back(4);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(5);
    v1.push_back(5);
    v1.push_back(5);
    v1.push_back(0);
    ///make_unique(v1);

#ifndef _AIX
	system("pause");
#endif
	return 0;
}

