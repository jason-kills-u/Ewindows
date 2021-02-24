#ifndef SAVE_HPP
#define SAVE_HPP
#include <filesystem>
#include <fstream>

bool containsDot(std::string h)
{
	for(auto i = h.begin(); i != h.end(); ++i)
	{
		if(*i == '.')
		{
			return true;
		}
		else
		{
			continue;
		}
	}
	return false;
}
void delFile(std::string g)
{
	g = std::string("del ") + g;
	const char *G = g.c_str();
	system(G);
}
void save(std::string g, std::string content)
{
	if(containsDot(g) == false)
	{
		g += std::string(".txt");
	}
	if(std::filesystem::exists(g))
    {
    	delFile(g);
    	std::ofstream FILE(g);
    	FILE << content;
    	FILE.close();
    }
    else
    {
    	std::ofstream FILE(g);
    	FILE << content;
    	FILE.close();
    }
}

#endif