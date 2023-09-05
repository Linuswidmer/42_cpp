#include <iostream>
#include <fstream>
#include <string>

int open_files(char *file_name, std::ifstream *infile, std::ofstream *outfile)
{
    std::string file_name_out(file_name);

    file_name_out += ".replace";
    const char* modifiedFilename = file_name_out.c_str();
    (*infile).open(file_name);
    (*outfile).open(modifiedFilename);
    if ((*infile).fail() || (*outfile).fail())
        return (1);
    else
        return (0);
}

int main(int argc, char **argv)
{
    std::string     filename_in(argv[1]);
    std::string     filename_out = filename_in + ".replace";
    std::ifstream   input_file(filename_in.c_str());
    std::ofstream   output_file(filename_out.c_str());
    std::string     line;

    if (argc != 4)
    {
        std::cout << "USAGE: <filename> <string to find> <string to replace>" << std::endl;
        return(1);
    }
    // if (!open_files(argv[1], &input_file, &output_file))
    // {
    //     std::cerr << "ERROR: could not open file" << std::endl;
    //     return (2);
    // }
    while (std::getline(input_file, line)) {
        output_file << line << std::endl;
    }
    input_file.close();
}