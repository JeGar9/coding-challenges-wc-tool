#include "options.h"

#include <memory>

std::unique_ptr<Option> get_option(char *arg) {
  std::string sarg = arg;
  return get_option(sarg);
}

std::unique_ptr<Option> get_option(std::string &arg) {

  if (arg == "--bytes" || arg == "-c") {
    return std::make_unique<NumBytesOption>();
  } else if (arg == "--chars" || arg == "-m") {
    return std::make_unique<NumCharsOption>();
  } else if (arg == "--lines" || arg == "-l") {
    return std::make_unique<NumLinesOption>();
  } else if (arg == "--max-line-length" || arg == "-L") {
    return std::make_unique<MaxLineOption>();
  } else if (arg == "--words" || arg == "-w") {
    return std::make_unique<NumWordsOption>();
  }
  return nullptr;
}

size_t Option::counter() const {
    return this->_counter;
}

void NumBytesOption::process_file_line(std::string &line) {
  this->_counter += line.length() * sizeof(char);
}

void NumCharsOption::process_file_line(std::string &line) {
  this->_counter += line.length();
}

void NumLinesOption::process_file_line(std::string &line) { this->_counter++; }

void MaxLineOption::process_file_line(std::string &line) {
  size_t current_len = line.length();
  if (current_len >= this->_counter) {
    this->_counter = current_len;
  }
}

void NumWordsOption::process_file_line(std::string &line) {
  bool prev_was_whitespace = true;
  for (char &c : line) {
    if (c == ' ' || c == '\t' || c == '\n') {
      prev_was_whitespace = true;
    } else if (prev_was_whitespace) {
      this->_counter++;
      prev_was_whitespace = false;
    }
  }
}