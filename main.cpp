#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include "Calculator.h"
#include "Parser.h"

int main() {
    Parser parser;
    Calculator calculator;
    std::string input;
    bool eofDetected = false;

    while (! eofDetected) {
        std::getline(std::cin, input);
        eofDetected = std::cin.eof();
        if (!eofDetected) {

            double operand1, operand2;
            char op;

            if (parser.parse(input, operand1, op, operand2)) {
                try {
                    double result = calculator.compute(operand1, op, operand2);
                    std::cout << std::fixed << std::setprecision(3) << operand1 << " " << op << " " << operand2 << " = "
                              << result << std::endl;
                } catch (const std::runtime_error &e) {
                    std::cerr << e.what() << std::endl;
                }
            } else {
                std::cerr << "Invalid input format. Use the format: number operator number (e.g., 5.5 + 3.2)"
                          << std::endl;
            }
        }
    }

    return 0;
}
