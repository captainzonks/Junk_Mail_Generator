/////////////////////
// Matthew Barham
// 2022-04-11
///////////////////////////////////////////////////////////////////
// Junk Mail Generator
//
// Takes a provided input file, with a single string of #N#,
// and generates an output file with the #N# replaced by a name
// provided by an input prompt.
//
// Will throw errors if input or output files fail to open.
///////////////////////////////////////////////////////////////////


#include <iostream>
#include <fstream>

void create_junk_mail(std::ifstream&, std::ofstream&, std::string);

int main() {

    std::ifstream in_stream;
    std::ofstream out_stream;
    std::string file_name;

    std::cout << "Please enter a file name to open (it should exist in the same directory as the executable): ";
    std::cin >> file_name;

    create_junk_mail(in_stream, out_stream, file_name);

    return 0;
}

/**
 * Opens a given file name and then replaces the discovered string of #N# with a provided name before
 * writing to a new file.
 * @param in_stream ifstream reference
 * @param out_stream ofstream reference
 * @param file_name file name to open
 */
void create_junk_mail(std::ifstream& in_stream, std::ofstream& out_stream, std::string file_name)
{
    in_stream.open(file_name);
    if (in_stream.fail())
    {
        std::cout << "Failed to open input file." << std::endl;
        exit(1);
    }
    out_stream.open("junk-mail_output");
    if (out_stream.fail())
    {
        std::cout << "Failed to open output file." << std::endl;
        exit(1);
    }

    char next{};
    in_stream.get(next);
    while (!in_stream.eof())
    {
        if (next == '#')
        {
            std::string name;
            std::cout << "Please enter a name: ";
            std::cin >> name;
            in_stream.get(next);
            in_stream.get(next);
            in_stream.get(next);
            out_stream << name;
        }
        else
        {
            out_stream.put(next);
            in_stream.get(next);
        }
    }

    in_stream.close();
    out_stream.close();

    return;
}