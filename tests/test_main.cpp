#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>

#include "../src/options.h"
#include "../src/ccwp.h"

TEST_CASE("Option base class counter increases") {
    struct DummyOption : public Option {
        void process_file_line(std::string& line) override {
            this->_counter++;
        }
    };

    DummyOption opt;
    std::string dummy = "line";
    opt.process_file_line(dummy);
    opt.process_file_line(dummy);
    REQUIRE(opt.counter() == 2);
};
