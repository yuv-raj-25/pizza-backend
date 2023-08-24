#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Operation {
public:
    virtual int calculate(const vector<int>& numbers) = 0;
};

class SumOperation : public Operation {
public:
    int calculate(const vector<int>& numbers) override {
        int sum = 0;
        for (int num : numbers) {
            sum += num;
        }
        return sum;
    }
};

class SubtractOperation : public Operation {
public:
    int calculate(const vector<int>& numbers) override {
        int result = numbers[0];
        for (size_t i = 1; i < numbers.size(); ++i) {
            result -= numbers[i];
        }
        return result;
    }
};

class EmptyOperation : public Operation {
public:
    int calculate(const vector<int>& numbers) override {
        return 0;
    }
};

class Calculator {
private:
    Operation* operation;

public:
    Calculator(Operation* op) : operation(op) {}

    int performOperation(const vector<int>& numbers) {
        return operation->calculate(numbers);
    }
};

int main() {
    string S;
    getline(cin, S);
    
    string numbersStr;
    getline(cin, numbersStr);
    stringstream ss(numbersStr);
    
    vector<int> numbers;
    int num;
    while (ss >> num) {
        numbers.push_back(num);
    }

    Operation* operation;
    
    if (S == "Sum") {
        operation = new SumOperation();
    } else if (S == "Subtract") {
        operation = new SubtractOperation();
    } else {
        operation = new EmptyOperation();
    }

    Calculator calculator(operation);
    int result = calculator.performOperation(numbers);
    cout << result << endl;

    delete operation; 

    return 0;
}
