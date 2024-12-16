/** @file InfixToPostfixEvaluation.cpp
 * InfixToPostfixEvaluation converts an infix expression to postfix and evaluates the resulting postfix expression.
 * @class InfixToPostfixEvaluation
 * @author Stephen Wagner
 * @date 11/26/2024
 * CSCI 591 Section 1
 */

#include "InfixToPostfixEvaluation.h"

InfixToPostfixEvaluation::InfixToPostfixEvaluation() : variableValues{}
{} // end default constructor

int InfixToPostfixEvaluation::precedence(char operatorChar) const noexcept
{
    if (operatorChar == '+' || operatorChar == '-')
    {
        return 1; // Operators '+' and '-' have a precedence of 1
    }
    if (operatorChar == '*' || operatorChar == '/')
    {
        return 2; // Operators '*' and '/' have a precedence of 2
    }
    return 0;
} // end precedence

void InfixToPostfixEvaluation::convertInfixToPostfix(const std::string& infixExpression) noexcept
{
    postfixExpQueue = LinkedDeque<char>();       // Initialize an empty deque for queue functionality
    operatorStack = LinkedDeque<char>();         // Initialize an empty deque for stack functionality

    for (char currentChar : infixExpression) // Range-based loop over infix expression
    {
        currentChar = std::tolower(currentChar);  // Convert to lowercase if uppercase

        if (std::isalpha(currentChar))
        {
            postfixExpQueue.enqueueBack(currentChar);  // Enqueue operand to postfix expression
        }
        else
        {
            switch (currentChar)
            {
            case '(':  // Opening parenthesis
                operatorStack.enqueueBack(currentChar);  // Save '(' on stack
                break;

            case '+': case '-': case '*': case '/':  // Valid operators
                while (!operatorStack.isEmpty() && operatorStack.peekBack() != '(' &&
                    precedence(currentChar) <= precedence(operatorStack.peekBack()))
                {
                    char nextOperator = operatorStack.peekBack();
                    postfixExpQueue.enqueueBack(nextOperator);  // Enqueue operator
                    operatorStack.dequeueBack();
                }
                operatorStack.enqueueBack(currentChar);  // Save the operator on stack
                break;

            case ')':  // Closing parenthesis
                while (operatorStack.peekBack() != '(')
                {
                    char nextOperator = operatorStack.peekBack();
                    postfixExpQueue.enqueueBack(nextOperator);  // Enqueue operator
                    operatorStack.dequeueBack();
                }
                operatorStack.dequeueBack();  // Remove the open parenthesis
                break;
            }
        }
    }

    // Add remaining operators to postfix expression
    while (!operatorStack.isEmpty())
    {
        char nextOperator = operatorStack.peekBack();
        postfixExpQueue.enqueueBack(nextOperator);  // Enqueue remaining operators
        operatorStack.dequeueBack();
    }
} // end convertInfixToPostfix

std::string InfixToPostfixEvaluation::getPostfixExpression() const noexcept
{
    // Convert the contents of postfixExpQueue to a string for output
    LinkedDeque<char> tempQueue = postfixExpQueue;  // Copy the deque to avoid modifying the original
    std::string postfixExpression;

    while (!tempQueue.isEmpty())
    {
        postfixExpression += tempQueue.peekFront();
        tempQueue.dequeueFront();
    }

    return postfixExpression;
} // end getPostfixExpression

void InfixToPostfixEvaluation::readValuesFromFile(const std::string& filename)
{
    std::ifstream file(filename); // Open the file
    if (!file) // Throw error if the file could not be opened
    {
        throw std::runtime_error("Could not open file: " + filename);
    }

    for (size_t i = 0; i < CAPACITY; ++i) // Add values from the file into array
    {
        if (!(file >> variableValues[i]))
        {
            throw std::runtime_error("File does not contain enough values."); // Throw error if there are not enough values
        }
    }
} // end readValuesFromFile

void InfixToPostfixEvaluation::clearVariableValues() noexcept
{
    for (size_t i = 0; i < CAPACITY; ++i) // Set values to zero to clear the array
    {
        variableValues[i] = 0;
    }
} // end clearVariableValues

std::string InfixToPostfixEvaluation::getVariableValues() const noexcept
{
    std::string result = "Variable values : "; // Declare string to concatenate values
    for (size_t i = 0; i < CAPACITY; ++i)
    {
        result += " " + std::to_string(variableValues[i]); // Concatenate all values from the array to the string
    }
    return result; // Return string of values
} // end getVariableValues

double InfixToPostfixEvaluation::evaluatePostfixExpression()
{
    LinkedDeque<double> evaluationStack;  // Deque to hold intermediate results

    // Loop through each character in the postfix expression deque
    while (!postfixExpQueue.isEmpty())
    {
        char currentChar = postfixExpQueue.peekFront();
        postfixExpQueue.dequeueFront();

        if (std::isalpha(currentChar))  // Operand
        {
            int variableIndex = currentChar - 'a';  // Convert variables to corresponding index
            evaluationStack.enqueueBack(variableValues[variableIndex]);
        }
        else  // Operator
        {
            if (evaluationStack.isEmpty()) throw std::runtime_error("Invalid postfix expression");

            // Pop the top two operands
            double operand2 = evaluationStack.peekBack();
            evaluationStack.dequeueBack();

            if (evaluationStack.isEmpty()) throw std::runtime_error("Invalid postfix expression");
            double operand1 = evaluationStack.peekBack();
            evaluationStack.dequeueBack();

            double result = 0;

            // Perform the operation based on the operator
            switch (currentChar)
            {
            case '+': result = operand1 + operand2; break;
            case '-': result = operand1 - operand2; break;
            case '*': result = operand1 * operand2; break;
            case '/':
                if (operand2 == 0) throw std::runtime_error("Division by zero");
                result = operand1 / operand2;
                break;
            default:
                throw std::runtime_error("Unknown operator encountered");
            }

            // Push the result back onto the deque
            evaluationStack.enqueueBack(result);
        }
    }

    // The final result should be the only element in the deque
    if (evaluationStack.isEmpty()) throw std::runtime_error("Invalid postfix expression");

    double finalResult = evaluationStack.peekBack();
    evaluationStack.dequeueBack();

    // If the deque is not empty, it means the postfix expression was invalid
    if (!evaluationStack.isEmpty()) throw std::runtime_error("Invalid postfix expression");

    return finalResult;
} // end evaluatePostfixExpression