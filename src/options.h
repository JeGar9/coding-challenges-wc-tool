#ifndef _OPTIONS_H
#define _OPTIONS_H

#include <iostream>

class Option {

protected:
  size_t _counter;

public:
  virtual void process_file_line(std::string &line) = 0;
  Option() : _counter(0) {}
  virtual ~Option() = default;
  size_t counter() const;
  friend std::ostream &operator<<(std::ostream &stream, Option &optr) {
    stream << optr.counter();
    return stream;
  }

};

class NumBytesOption : public Option {
public:
  virtual void process_file_line(std::string &line);
};

class NumCharsOption : public Option {
public:
  virtual void process_file_line(std::string &line);
};

class NumLinesOption : public Option {
public:
  virtual void process_file_line(std::string &line);
};

class MaxLineOption : public Option {
public:
  virtual void process_file_line(std::string &line);
};

class NumWordsOption : public Option {
public:
  virtual void process_file_line(std::string &line);
};

std::unique_ptr<Option> get_option(char *arg);
std::unique_ptr<Option> get_option(std::string &arg);

#endif