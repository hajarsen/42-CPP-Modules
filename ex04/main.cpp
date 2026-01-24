#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

bool replaceInFile(const std::string& filename, 
                   const std::string& s1, 
                   const std::string& s2)
{  
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Cannot open file '" << filename << "'" << std::endl;
        return false;
    }
    
    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Cannot create file '" << outputFilename << "'" << std::endl;
        inputFile.close();
        return false;
    }
    
    std::string line;
    while (std::getline(inputFile, line))
    {
        std::string result;
        size_t pos = 0;
        size_t found;
        
        while ((found = line.find(s1, pos)) != std::string::npos)
        {
            result += line.substr(pos, found - pos);
            result += s2;
            pos = found + s1.length();
        }
        result += line.substr(pos);
        outputFile << result;
        
        if (!inputFile.eof())
        {
            outputFile << '\n';
        }
    }
    inputFile.close();
    outputFile.close();
    
    return true;
}

int main(int argc, char* argv[])
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    if (s1.empty())
    {
        std::cerr << "Error: s1 cannot be empty." << std::endl;
        return 1;
    }
    
    if (!replaceInFile(filename, s1, s2))
    {
        return 1;
    }
    
    return 0;
}
