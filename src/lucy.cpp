#include "lucy/lucy.hpp"
#include "lucy/lexer.hpp"
#include "lucy/parser.hpp"
#include "lucy/runtime.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace lucy;

void lucy::run_source(
    const std::string& source,
    const std::string& name,
    const std::vector<std::string>& argv) {
    try {
        Lexer lexer(source);
        Parser parser(lexer.scan());
        Interpreter interpreter(argv);
        interpreter.set_current_file(name);
        interpreter.run(parser.parse());
    } catch (const std::exception& error) {
        throw std::runtime_error(std::string("in ") + name + ": " + error.what());
    }
}

void lucy::run_file(
    const std::string& path,
    const std::vector<std::string>& argv) {
    std::ifstream file(path);
    if (!file) {
        throw std::runtime_error(
            "IOError: cannot open source file '" + path + "'");
    }

    std::ostringstream source;
    source << file.rdbuf();
    run_source(source.str(), path, argv);
}

void lucy::repl() {
    Interpreter interpreter;
    interpreter.repl();
}
