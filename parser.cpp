#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

class CSVFile
{
    std::string s1,s2,s3;
    public:
    CSVFile()
    {
        s1 = "";
        s2 = "";
        s3 = "";
    }
    void setFirst(std::string val)
    {
        s1 = val;
    }

    void setSecond(std::string val)
    {
        s2 = val;
    }

    void setThree(std::string val)
    {
        s3 = val;
    }

    std::string toString()
    {
        std::string retval = s1 + "\n" + s2 + "\n" + s3 + "\n";
        std::cout<<retval<<std::endl;
        return retval;
    }
};


int main(void)
{
    std::fstream file ("test.csv", std::ios::in);
    std::vector< std::vector<std::string> > content;
    std::vector<std::string> row;
    std::string line, word;
    std::vector<CSVFile> csvfile;
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();
            CSVFile csv = CSVFile();
            std::stringstream sLine(line);
            std::cout<<sLine.str()<<std::endl;
            
            int count = 0;
            while(getline(sLine, word, ','))
            {
                if(count == 0)
                {
                    csv.setFirst(word);
                }
                else if(count == 1)
                {
                    csv.setSecond(word);
                }
                else if(count == 2)
                {
                    csv.setThree(word);
                }
                count++;
                row.push_back(word);
            }
            content.push_back(row);
            csvfile.push_back(csv);

        }
    }
    else
    {
        std::cout<<"Could not open file!"<<std::endl;
        throw new std::exception();
    }
    
    for(int i=0;i<content.size();i++)
	{
		for(int j=0;j<content[i].size();j++)
		{
			std::cout<<content[i][j]<<" ";
		}
		std::cout<<"\n";
	}
    for(auto i : csvfile)
    {
        i.toString();
    }
 
	return 0;
}