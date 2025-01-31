#include <iostream>
#include <string>
#include <stdexcept>
#include "Calculator.h"
#include "Parser.h"

int main() {
    Parser parser;
    Calculator calculator;
    std::string input;

    std::cout << "Enter an expression (e.g., 5.5 + 3.2) or press Ctrl+D to exit: " << std::endl;

    while (std::getline(std::cin, input)) {
        double operand1, operand2;
        char op;

        if (parser.parse(input, operand1, op, operand2)) {
            try {
                double result = calculator.compute(operand1, op, operand2);
                std::cout << operand1 << " " << op << " " << operand2 << " = " << result << std::endl;
            } catch (const std::runtime_error& e) {
                std::cerr << e.what() << std::endl;
            }
        } else {
            std::cerr << "Invalid input format. Use the format: number operator number (e.g., 5.5 + 3.2)" << std::endl;
        }
        std::cout << "Enter another expression or press Ctrl+D to exit: " << std::endl;
    }

    std::cout << "Goodbye!" << std::endl;
    return 0;
}
