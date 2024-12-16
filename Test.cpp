/** @file Test.cpp
 * Tests valid, boundary, invalid values, and user testing interface.
 * @author Stephen Wagner
 * @date 11/26/2024
 * CSCI 591 Section 1
 */

#include <iostream>
#include "InfixToPostfixEvaluation.h"
#include "LinkedDeque.h"

using namespace std;

int main()
{
	//Testing Deque specifically for valid and boundry
	cout << "=== Testing Deque for valid and boundry values ===" << endl;

	LinkedDeque<int> testDeque;

	// Testing isEmpty() on a new deque
	cout << "Checking if the deque contains items initially" << endl;
	if (testDeque.isEmpty())
	{
		cout << "Deque is empty" << endl;
	}
	else
	{
		cout << "Deque is not empty" << endl;
	}
	cout << "Deque should be empty" << endl;
	cout << endl;

	// Testing enqueueBack()
	testDeque.enqueueBack(2);
	testDeque.enqueueBack(4);

	cout << "enqueueBack two numbers to deque" << endl;
	cout << "Deque contents: ";
	// Make a temporary copy to avoid modifying the original
	LinkedDeque<int> tempDeque1 = testDeque;
	while (!tempDeque1.isEmpty()) 
	{
		cout << tempDeque1.peekFront() << " ";
		tempDeque1.dequeueFront();
	}
	cout << endl;
	cout << "Should be: 2 4" << endl;
	cout << endl;


	//Testing enqueueFront()
	testDeque.enqueueFront(1);
	testDeque.enqueueFront(0);
	
	cout << "enqueueFront two numbers to deque" << endl;
	cout << "Deque contents: ";
	// Make a temporary copy to avoid modifying the original
	LinkedDeque<int> tempDeque3 = testDeque;
	while (!tempDeque3.isEmpty()) 
	{
		cout << tempDeque3.peekFront() << " ";
		tempDeque3.dequeueFront();
	}
	cout << endl;
	cout << "Should be: 0 1 2 4" << endl;
	cout << endl;


	// Testing dequeueFront()
	testDeque.dequeueFront();

	cout << "dequeueFront to remove front number" << endl;
	cout << "Deque contents: ";
	// Make a temporary copy to avoid modifying the original
	LinkedDeque<int> tempDeque5 = testDeque;
	while (!tempDeque5.isEmpty()) 
	{
		cout << tempDeque5.peekFront() << " ";
		tempDeque5.dequeueFront();
	}
	cout << endl;
	cout << "Should be: 1 2 4 " << endl;
	cout << endl;

	// Testing dequeueBack()
	testDeque.dequeueBack();

	cout << "dequeueBack to remove back number" << endl;
	cout << "Deque contents: ";
	// Make a temporary copy to avoid modifying the original
	LinkedDeque<int> tempDeque6 = testDeque;
	while (!tempDeque6.isEmpty()) 
	{
		cout << tempDeque6.peekFront() << " ";
		tempDeque6.dequeueFront();
	}
	cout << endl;
	cout << "Should be: 1 2 " << endl;
	cout << endl;

	// Testing peekFront()
	cout << "Using peekFront to check front value" << endl;
	cout << "Deque front: " << testDeque.peekFront() << endl;
	cout << "Should be: 1" << endl;

	// Checking to make sure the deque is unaltered from peekFront()
	cout << "Deque contents: ";
	// Make a temporary copy to avoid modifying the original
	LinkedDeque<int> tempDeque7 = testDeque;
	while (!tempDeque7.isEmpty()) 
	{
		cout << tempDeque7.peekFront() << " ";
		tempDeque7.dequeueFront();
	}
	cout << endl;
	cout << "Should be: 1 2 " << endl;
	cout << endl;

	// Testing peekBack()
	cout << "Using peekBack to check the back value" << endl;
	cout << "Deque back: " << testDeque.peekBack() << endl;
	cout << "Should be: 2" << endl;

	// Checking to make sure the deque is unaltered from peekBack()
	cout << "Deque contents: ";
	// Make a temporary copy to avoid modifying the original
	LinkedDeque<int> tempDeque8 = testDeque;
	while (!tempDeque8.isEmpty()) 
	{
		cout << tempDeque8.peekFront() << " ";
		tempDeque8.dequeueFront();
	}
	cout << endl;
	cout << "Should be: 1 2 " << endl;
	cout << endl;

	// Testing isEmpty() on a deque that contains values
	cout << "Checking if the deque contains items" << endl;
	if (testDeque.isEmpty())
	{
		cout << "Deque is empty" << endl;
	}
	else
	{
		cout << "Deque is not empty" << endl;
	}
	cout << "Deque should not be empty" << endl;
	cout << endl;

	// Testing clear()
	cout << "Using clear on the deque" << endl;
	testDeque.clear();

	// Checking to make sure the deque is unaltered from peekBack()
	cout << "Deque contents: ";
	// Make a temporary copy to avoid modifying the original
	LinkedDeque<int> tempDeque9 = testDeque;
	while (!tempDeque9.isEmpty()) 
	{
		cout << tempDeque9.peekFront() << " ";
		tempDeque9.dequeueFront();
	}
	cout << endl;
	cout << "Should be: " << endl;
	cout << endl;


	// Testing error handling for invalid values
	cout << "=== Testing error handling on empty deque ===" << endl;

	// Test dequeueFront on an empty deque
	try 
	{
		testDeque.dequeueFront();
	}
	catch (const PrecondViolatedExcept& e) 
	{
		cout << "Caught exception on dequeueFront with empty deque: " << e.what() << endl;
	}

	// Test dequeueBack on an empty deque
	try 
	{
		testDeque.dequeueBack();
	}
	catch (const PrecondViolatedExcept& e) 
	{
		cout << "Caught exception on dequeueBack with empty deque: " << e.what() << endl;
	}

	// Test peekFront on an empty deque
	try 
	{
		cout << "Front value: " << testDeque.peekFront() << endl;
	}
	catch (const PrecondViolatedExcept& e) 
	{
		cout << "Caught exception on peekFront with empty deque: " << e.what() << endl;
	}

	// Test peekBack on an empty deque
	try 
	{
		cout << "Back value: " << testDeque.peekBack() << endl;
	}
	catch (const PrecondViolatedExcept& e) 
	{
		cout << "Caught exception on peekBack with empty deque: " << e.what() << endl;
	}

	cout << endl;


	// Testing valid values
	cout << "=== Valid Values InfixToPostfixEvaluation ===" << endl;

	// Create an instance of the class for testing
	InfixToPostfixEvaluation evaluator;

	// Testing that the variableValues array contains zeros
	cout << evaluator.getVariableValues() << endl;
	cout << "Should be all zeros: 0 0 0 0 0 0" << endl << endl;

	// Testing reading file for variable values
	evaluator.readValuesFromFile("variables.txt");

	// Outputting the variable values again
	cout << evaluator.getVariableValues() << endl;
	cout << "Should be numbers: 5 10 15 20 25 30" << endl << endl;

	// Testing clear variable values
	evaluator.clearVariableValues();
	cout << evaluator.getVariableValues() << endl;
	cout << "Should be all zeros: 0 0 0 0 0 0" << endl << endl;

	// Setting variable values for testing
	evaluator.readValuesFromFile("variables.txt");
	cout << evaluator.getVariableValues() << endl;
	cout << "Should be numbers: 5 10 15 20 25 30" << endl << endl;

	// Creating an array with required test infix expressions
	std::string testExpressions[] =
	{
		"a+b*c",           // Example (a)
		"(a+b)*c",         // Example (b)
		"a+b*c-d",         // Example (c)
		"a+b*(c-d)",       // Example (d)
		"(a+b)*(c-d)",     // Example (e)
		"a+b+c+d",         // Example (f)
		"a+b*c/d-e+f",     // Example (g)
		"a*(b+c)*(d-e)+f"  // Example (h)
	};

	// Loop through each expression, convert, and evaluate
	for (const std::string& infixExpr : testExpressions)
	{
		cout << "Infix Expression: " << infixExpr << endl;
		evaluator.convertInfixToPostfix(infixExpr);
		cout << "Postfix Expression: " << evaluator.getPostfixExpression() << endl;
		double result = evaluator.evaluatePostfixExpression();
		cout << "Evaluation Result: " << result << endl << endl;
	}
	cout << endl;


	// Testing boundary values
	cout << "=== Boundary Values InfixToPostfixEvaluation ===" << endl;

	// Testing a small expression
	evaluator.convertInfixToPostfix("a");
	cout << "Postfix expression: " << evaluator.getPostfixExpression() << endl;
	cout << "Should be: a" << endl;
	double result = evaluator.evaluatePostfixExpression();
	cout << "Result is: " << result << endl;
	cout << "Should be: 5" << endl << endl;

	// Testing a large expression
	evaluator.convertInfixToPostfix("a+b+c+d+e+f");
	cout << "Postfix expression: " << evaluator.getPostfixExpression() << endl;
	cout << "Should be: ab+c+d+e+f+" << endl;
	result = evaluator.evaluatePostfixExpression();
	cout << "Result is: " << result << endl;
	cout << "Should be: 105" << endl << endl;

	// Testing an expression resulting in zero
	evaluator.convertInfixToPostfix("a-a");
	cout << "Postfix expression: " << evaluator.getPostfixExpression() << endl;
	cout << "Should be: aa-" << endl;
	result = evaluator.evaluatePostfixExpression();
	cout << "Result is: " << result << endl;
	cout << "Should be: 0" << endl << endl;

	// Testing invalid values
	cout << "=== Invalid Values InfixToPostfixEvaluation ===" << endl;

	// Changing variable values for additional boundary cases
	evaluator.readValuesFromFile("boundaryVariables.txt");

	// Outputting the variable values again
	cout << evaluator.getVariableValues() << endl;
	cout << "Should be numbers: 5 0 15 20 25 30" << endl << endl;

	// Using a try catch block to test division by zero
	try
	{
		evaluator.convertInfixToPostfix("a/b");
		cout << "Postfix expression: " << evaluator.getPostfixExpression() << endl;
		cout << "Should be: ab/" << endl;

		result = evaluator.evaluatePostfixExpression();
		cout << "Result is: " << result << endl;
		cout << "Expected output: Division by zero error handled" << endl << endl;
	}
	catch (const std::runtime_error& error) {
		cout << "Caught exception: " << error.what() << endl;
		cout << "Expected output: Division by zero" << endl << endl;
	}

	// Using a try catch block to test for invalid expression
	try
	{
		evaluator.convertInfixToPostfix("+");
		cout << "Postfix expression: " << evaluator.getPostfixExpression() << endl;
		cout << "Should be: +" << endl;

		result = evaluator.evaluatePostfixExpression();
		cout << "Result is: " << result << endl;
	}
	catch (const std::runtime_error& error)
	{
		cout << "Caught exception: " << error.what() << endl;
		cout << "Expected output: Invalid postfix expression" << endl << endl;
	}

	// Testing no operators
	try
	{
		evaluator.convertInfixToPostfix("abcdef");
		cout << "Postfix expression: " << evaluator.getPostfixExpression() << endl;
		cout << "Should be: abcdef" << endl;

		result = evaluator.evaluatePostfixExpression();
		cout << "Result is: " << result << endl;
		cout << "Expected output: Sum of all variable values if valid" << endl << endl;
	}
	catch (const std::runtime_error& error)
	{
		cout << "Caught exception: " << error.what() << endl;
		cout << "Expected output: Exception handled for invalid expression" << endl << endl;
	}

	try {
		// Trying to change variables with an invalid input file
		evaluator.readValuesFromFile("invalidVariables.txt");

		// Outputting the variable values again
		cout << evaluator.getVariableValues() << endl;
		cout << "Should be numbers: 5 10 15" << endl << endl;
	}
	catch (const std::runtime_error& error) {
		cout << "Caught exception: " << error.what() << endl;
		cout << "Expected output: file does not contain enough values" << endl << endl;
	}
	cout << endl;

	// User testing interface
	cout << "=== User Input Testing InfixToPostfixEvaluation ===" << endl;

	// Changing variables back to a valid file
	evaluator.readValuesFromFile("variables.txt");

	// Outputting the variable values again
	cout << evaluator.getVariableValues() << endl;
	cout << "Should be numbers: 5 10 15 20 25 30" << endl << endl;

	// Prompting user for expressions
	string userInput;
	cout << "Type a valid infix expression using letters 'a' through 'f' and binary operators to convert and evaluate, or type 'quit' to end." << endl;
	while (true)
	{
		cout << "Enter an infix expression (or 'quit' to exit): ";
		getline(cin, userInput);

		if (userInput == "quit")
		{
			cout << "Exiting user test program." << endl;
			break;
		}

		try
		{
			evaluator.convertInfixToPostfix(userInput);
			cout << "Postfix Expression: " << evaluator.getPostfixExpression() << endl;

			double result = evaluator.evaluatePostfixExpression();
			cout << "Evaluation Result: " << result << endl;
		}
		catch (const std::runtime_error& error)
		{
			cout << "Error: " << error.what() << endl;
		}
	}
	return 0;
}