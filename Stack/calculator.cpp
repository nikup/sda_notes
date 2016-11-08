#include <iostream>
#include <stdint.h>
#include "ImplementedStack.h"

//split string by char; return stack with the resulting substrings
LinkedStack<std::string> split(const std::string &txt, char ch);
//calculate result by given 2 numbers and an operand
float calc(float x, float y, std::string op);

int main(int argc, const char * argv[]) {
    std::string input = "5 1 2 + 4 * + 3 -";
    
    LinkedStack<std::string> parsedInput = split(input, ' ');
    LinkedStack<float> temp;
    
    std::string popped;
    
    while (parsedInput.GetSize()) {
        parsedInput.Pop(popped);
        
        try {
            temp.Push(std::stof(popped));
        } catch (const std::invalid_argument& ex) {
            float operand1, operand2;
            temp.Pop(operand2);
            temp.Pop(operand1);
            
            temp.Push(calc(operand1, operand2, popped));
        }
    }

    std::cout << temp.Peek() << std::endl;

    return 0;
}

LinkedStack<std::string> split(const std::string &txt, char ch)
{
    unsigned long pos = txt.find(ch);
    unsigned long initialPos = 0;
    LinkedStack<std::string> st;
    
    while(pos != std::string::npos) {
        st.Push(txt.substr(initialPos, pos - initialPos));
        initialPos = pos + 1;
        
        pos = txt.find(ch, initialPos);
    }
    
    st.Push(txt.substr(initialPos, std::min(pos, txt.size()) - initialPos));
    
    LinkedStack<std::string> result;
    std::string temp;

    while (st.GetSize()) {
        st.Pop(temp);
        result.Push(temp);
    }

    return result;
}

float calc(float x, float y, std::string op) {
    if (op == "+") {
        return x + y;
    } else if (op == "-") {
        return x - y;
    } else if (op == "*") {
        return x * y;
    } else if (op == "/") {
        return x / y;
    }
    
    return 0;
}
