#include "Calculator.h"

double Calculator::compute(double operand1, char op, double operand2) {
    switch (op) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                throw std::runtime_error("Error: Division by zero is not allowed.");
            }
            return operand1 / operand2;
        default:
            throw std::runtime_error("Error: Unknown operator.");
    }
}
