#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>
#include <math.h>

int  priority(char c){
    switch(c){
    case '^':
        return 4;
    case '/':
    case '*':
        return 3;
    case '+':
    case '-':
        return 2;
    default:
        return 0;
    }
}

bool isNumber(char symb){
    if((symb >= '0' && symb <= '9')||(symb == '.')){
        return true;
    }else{
        return false;
    }
}

std::string inftopol(std::string expression){
    std::stack<char> operators;
    std::string result;
    for(size_t i=0;i < expression.size();i++){
        if(expression[i] == ' '){
            continue;
        }
        if(isNumber(expression[i])){
            std::stringstream s;
            s << expression[i];
            result += s.str();
            if(expression[i+1] == ' ' || (i+1) >= expression.size()){
                result += ' ';
            }
        }
        else if(expression[i] == '('){
            operators.push(expression[i]);
        }
        else if(!(operators.empty())){
            if(expression[i] == ')'){
                while(operators.top() != '('){
                    result += operators.top();
                    result += " ";
                    operators.pop();
                }
                operators.pop();
            }
            else if((priority(expression[i]) <= priority(operators.top()))){
                result += operators.top();
                result += " ";
                operators.pop();
                operators.push(expression[i]);
            }else{
                operators.push(expression[i]);
            }
        }else{
            operators.push(expression[i]);
        }
    }
    while(!operators.empty()){
        if(priority(operators.top()) > 1){
            result += operators.top();
            result += " ";
        }
        operators.pop();
    }
    return result;
}

double countPol(std::string result){
    std::stack<double> nums;
    std::string temp_str_d;
    double count;
    for(size_t i=0;i<result.length();i++){
        if(isNumber(result[i])){
            std::stringstream s;
            s << result[i];
            temp_str_d += s.str();
        }else if(result[i] == ' ' && isNumber(result[i-1])){
            nums.push(stod(temp_str_d));
            temp_str_d = "";
        }else{
            switch (result[i]) {
            case '^':{
                    double power = nums.top();
                    nums.pop();
                    double temp_num = pow(nums.top(),power);
                    nums.pop();
                    nums.push(temp_num);
                    break;
                }
            case '/':{
                    double operand = nums.top();
                    nums.pop();
                    double num = nums.top() / operand;
                    nums.pop();
                    nums.push(num);
                    break;
            }
            case '*':{
                    double operand = nums.top();
                    nums.pop();
                    double num = nums.top() * operand;
                    nums.pop();
                    nums.push(num);
                    break;
            }
            case '-':{
                    double operand = nums.top();
                    nums.pop();
                    double num = nums.top() - operand;
                    nums.pop();
                    nums.push(num);
                    break;
            }
            case '+':{
                    double operand = nums.top();
                    nums.pop();
                    double num = nums.top() + operand;
                    nums.pop();
                    nums.push(num);
                    break;
            }
            }
        }
    }
    count = nums.top();
    return count;
}

int main()
{
    std::string expression;
    std::getline(std::cin, expression);
    std::string result = inftopol(expression);
    double count_pol = countPol(result);
    std::cout << result << std::endl;
    std::cout << count_pol << std::endl;
    return 0;
}
