#include "ccwp.h"

#include <fstream>

#include "config.h"

using namespace std;

void print_help(ostream& stream) {
    stream << "Usage: mywc [OPTION]... [FILE]..." << endl
              << "Print newline, word, and byte counts for each FILE, and a total line if more than one FILE is specified." << endl
              << endl
              << "With no FILE, or when FILE is -, read standard input." << endl
              << endl
              << "Options:" << endl
              << "  -c, --bytes            print the byte counts" << endl
              << "  -m, --chars            print the character counts" << endl
              << "  -l, --lines            print the newline counts" << endl
              << "  -w, --words            print the word counts" << endl
              << "  -L, --max-line-length  print the length of the longest line" << endl
              << "      --help             display this help and exit" << endl
              << "      --version          output version information and exit" << endl;
}

void print_version(ostream& stream) {
    stream << "Version " << CCWC_VERSION_MAJOR << "." << CCWC_VERSION_MINOR << "." << CCWC_VERSION_MINOR;
}

void FileProcessor::add_option(const char* opt)
{
    std::string sopt = opt;
    this->add_option(sopt);
}

void FileProcessor::add_option(std::string& opt)
{
    unique_ptr<Option> optObj = get_option(opt);
    if (optObj != nullptr)
        this->options.push_back(move(optObj));
}

void FileProcessor::process_file(std::string& filename)
{
    ifstream file_stream (filename);
    string line;
    while (getline(file_stream, line)) {
        for (const unique_ptr<Option>& opt : options) {
            opt->process_file_line(line);
        }
    }
}

std::ostream& operator<<(std::ostream& stream, FileProcessor& processor)
{
    for (const unique_ptr<Option>& opt : processor.options) {
        stream << *opt << "\t";
    }
    return stream;
}

size_t FileProcessor::num_options() const
{
    return this->options.size();
}

FileProcessor FileProcessor::create_from_arguments(std::vector<std::string> options)
{
    FileProcessor processor;
    for(string& opt : options) {
        processor.add_option(opt);
    }
    
    if (!processor.num_options()) {
        processor.add_option("-l");
        processor.add_option("-w");
        processor.add_option("-c");
    }
    return processor;
}
