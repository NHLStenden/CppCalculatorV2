#include "Parser.h"

Parser::Parser() : expression_regex("\\s*(-?\\d*\\.?\\d+)\\s*([+\\-*/])\\s*(-?\\d*\\.?\\d+)\\s*") {}

bool Parser::parse(const std::string& input, double& operand1, char& op, double& operand2) {
    std::smatch match;
    if (std::regex_match(input, match, expression_regex)) {
        operand1 = std::stod(match[1]);
        op = match[2].str()[0];
        operand2 = std::stod(match[3]);
        return true;
    }
    return false;
}
