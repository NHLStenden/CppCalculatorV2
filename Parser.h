#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <regex>

class Parser {
private:
    std::regex expression_regex;

public:
    Parser();
    bool parse(const std::string& input, double& operand1, char& op, double& operand2);
};

#endif // PARSER_H
