#ifndef _CCWP_H
#define _CCWP_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "options.h"

class FileProcessor
{
private:
    std::vector<std::unique_ptr<Option>> options;
public:
    FileProcessor() = default;
    ~FileProcessor() = default;

    // No copiable
    FileProcessor(const FileProcessor&) = delete;
    FileProcessor& operator=(const FileProcessor&) = delete;

    // Movible
    FileProcessor(FileProcessor&&) noexcept = default;
    FileProcessor& operator=(FileProcessor&&) noexcept = default;

    void add_option(std::string& opt);
    void add_option(const char* opt);
    size_t num_options() const;
    void process_file(std::string& file);
    static FileProcessor create_from_arguments(std::vector<std::string> options);
    friend std::ostream& operator<<(std::ostream& stream, FileProcessor& processor);
};

void print_help(std::ostream& stream);
void print_version(std::ostream& stream);

#endif