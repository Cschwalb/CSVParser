//
//  parseFile.cpp
//  GUTS scheduler
//
//  Created by Caleb Schwalb on 9/28/22.
//
#include "parseFile.hpp"
#include <fstream>
#include <string>
#include <istream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <sstream>

// function prototype
void write(std::string words, bool bEndl);

void parseThis(std::string sFileAddress)
{
	
}

bool fileParse::parseFile(std::string sFileAddress)
{
    std::string line;
    std::ifstream myfile (sFileAddress);
	char cLion[500];
	const char delim[2] = ",";
	char * token;
    if (myfile.is_open())
    {
      while ( getline (myfile, line) )
      {
		  write(line, true);
		  host* pSingleSlot = new host();
          std::ifstream file;
          // Open existing file
          file.open(sFileAddress);
		  while(!file.eof())
		  {
			  file>>line;
			  strcpy(cLion, line.c_str());
			  token = strtok(cLion, delim);
			  if(token == NULL)
			  {
				  std::cout<<"token is null 0"<<std::endl;
				  break;
			  }
			  int nCounter = 0;
			  try
			  {
				while(token != NULL)
				{
					nCounter = 0;
					pSingleSlot->setName(token);
					for(int w = 1; w < 7; w++)
					{
						token = strtok(NULL, delim);
						if(token == NULL)
						{
							break;
						}
						pSingleSlot->bAvailable[w-1] = (bool)token;
					}
					nCounter = 0;
					/*for(auto nInd = this->m_hostHours->begin(); nInd != this->m_hostHours->end();)
					{
						
						this->m_hostHours->push_back(pSingleSlot->m_hostHours->at(nCounter));
						
						std::cout<<this->m_hostHours->at(nCounter)<<std::endl;
						nCounter++;
					}*/
					pSingleSlot->toString();
				}
			  }
			catch(std::exception e)
			  {
				  std::cout<<e.what()<<std::endl;
			  }
			  myfile.close();
		  }
		  delete pSingleSlot;
		  return true;
		}
	}
	return false;
}

/*void fileParse::toString(host* x)
{
	for(auto &tupac : this->getHosts())
	{
		tupac->toString();
	}
	x->toString();
}*/

void fileParse::write(std::string words, bool bEndl)
{
	std::cout<<"[+]----  "<<words;
	if(bEndl)
		std::cout<<std::endl;
}
