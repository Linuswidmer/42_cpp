#include <iostream>
#include <fstream>
#include <string>

void    find_and_replace(std::ifstream *input_file, std::ofstream *output_file, std::string find, std::string replace)
{
    unsigned long   start;
    size_t          pos;
    std::string     line;

    start = 0;
    while(std::getline(*input_file, line))
    {
        pos = line.find(find);
        while (pos < line.size())
        {
            *output_file << line.substr(start, pos);
            *output_file << replace;
            line = line.substr(pos + find.size());
            pos = line.find(find);
        }
        *output_file << line << std::endl;
    }
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "USAGE: <filename> <string to find> <string to replace>" << std::endl;
        return(1);
    }
    std::string     find(argv[2]);
    std::string     replace(argv[3]);
    std::string     filename_in(argv[1]);
    std::string     filename_out = filename_in + ".replace";
    std::ifstream   input_file(filename_in.c_str());
    std::ofstream   output_file(filename_out.c_str());
    if (find.empty())
    {
        std::cerr << "ERROR: string to find cannot be empty" << std::endl;
    }
    find_and_replace(&input_file, &output_file, find, replace);
    input_file.close();
}