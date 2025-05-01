#include <iostream>
#include <string>
#include <vector>

#include "ccwp.h"

int main(int argc, char* argv[]) {
    if (argc > 1) {
        std::string arg = argv[1];
        if (arg == "--help" || arg == "-h") {
            print_help(std::cout);
            return 0;
        }

        if (arg == "--version") {
            print_version(std::cout);
            return 0;
        }
    }
        
    std::vector<std::string> options;
    std::vector<std::string> files;
    for (int i = 1; i < argc; i++) {
        std::string val = argv[i];
        if (val.compare(0, 1, "-")){
            files.push_back(val);
        } else {
            options.push_back(val);
        }
    }

    FileProcessor processor = FileProcessor::create_from_arguments(options);

    if (files.empty()) {
        std::string input_file;
        std::cout << "No file specified, please specify a file" << std::endl;
        std::cin >> input_file;
        files.push_back(input_file);
    }

    if (files.empty()) {
        std::cout << "No valid files found" << std::endl;
        std::cout << "Run with --help to see usage." << std::endl;
        return -1;
    }

    for (std::string& file : files) {
        processor.process_file(file);
    }

    std::cout << processor << std::endl;
    return 0;
}

