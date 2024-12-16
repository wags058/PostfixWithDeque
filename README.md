# PostfixWithDeque

## Overview
`InfixToPostfixEvaluation` is a C++ program that:
- Converts mathematical expressions from infix notation (e.g., `(a+b)*c`) to postfix notation (`ab+c*`).
- Evaluates postfix expressions using integer variables (`a` to `f`).
- Allows users to load variable values from a text file, manage those values, and view or evaluate expressions interactively.

This project demonstrates the use of custom data structures like a circular doubly linked deque (`LinkedDeque`) and a node-based implementation to manage operations.

## Features
- **Infix to Postfix Conversion**: Transforms valid infix expressions into postfix notation.
- **Postfix Evaluation**: Evaluates postfix expressions using user-defined integer values for variables.
- **File Integration**: Reads and assigns variable values from a text file.
- **Error Handling**: Catches invalid expressions, division by zero, and missing variable values.

## Setup and Compilation
### Visual Studio
1. Open the project in Visual Studio.
2. Exclude non-required `.cpp` files from the build as needed (e.g., `LinkedDeque.cpp`).
3. Build and run the program.

### Command Line
1. Navigate to the project directory:
   ```bash
   cd path/to/project
   ```
2. Compile using `g++`:
   ```bash
   g++ -o PostfixWithDeque main.cpp
   ```
3. Run the program:
   ```bash
   ./PostfixWithDeque
   ```

## Usage
1. Load variable values from a file (`variables.txt`) containing six integers separated by spaces.
   ```cpp
   instance.readValuesFromFile("variables.txt");
   ```
2. Convert an infix expression to postfix:
   ```cpp
   instance.convertInfixToPostfix("(a+b)*c");
   ```
3. View the postfix expression:
   ```cpp
   std::cout << instance.getPostfixExpression() << std::endl;
   ```
4. Evaluate the postfix expression:
   ```cpp
   double result = instance.evaluatePostfixExpression();
   ```

## Example
For the input file `variables.txt`:
```
5 5 15 10 20 25
```
and the expression `(a+b)*c`, the program will:
- Convert to postfix: `ab+c*`
- Evaluate the result: `225`

## Future Enhancements
- Support for more variables (e.g., `a-z` instead of `a-f`).
- Floating-point variable support for real-number calculations.
- Extended operator support (e.g., exponentiation).

## License
This project is open-source and available under the MIT license.
