#include <iostream>
#include <sstream>
using namespace std;

#include "Stack.h"

/*
Post: The program has executed simple arithmetic
      commands entered by the user.
Uses: The class Stack and the functions
      introduction, instructions, do_command, and get_command.
*/

char get_command();
bool do_command(char command, Stack &numbers);
bool introduction();
void classic_calculator();
bool isOperation(string expression);

int main()
/*
Post: The program has executed simple arithmetic
      commands entered by the user.
Uses: The class Stack and the functions
      introduction, instructions, do_command, and get_command.
*/

{
    Stack stored_numbers;
    if (introduction())
       while (do_command(get_command(), stored_numbers));
    else classic_calculator();
}



bool introduction(){
    cout << "Do you want to use calculator with prompts? (y/n): ";
    char input;
    bool waiting = true;
    while (waiting) {
        cin >> input;
        input = tolower(input);
        if (input == 'y' || input == 'n')
            waiting = false;

        else
            cout << "Please enter a valid command (y or n): ";
    }
    if (input == 'y') return true;
    else return false;
};



char get_command()
{
   char command;
   bool waiting = true;
   cout << "Select command and press <Enter>:";

   while (waiting) {
      cin >> command;
      command = tolower(command);
      if (command == '?' || command == '=' || command == '+' ||
          command == '-' || command == '*' || command == '/' ||
          command == 'x' || command == 's' || command == 'a' ||
          command == 'q')  waiting = false;


      else {
         cout << "Please enter a valid command:"   << endl
              << "[?]push to stack   [=]print top" << endl
              << "[+] [-] [*] [/]   are arithmetic operations" << endl
              << "[x] exchange    [s] sum    [a] average" << endl
              << "[Q]uit." << endl;
      }
   }
   return command;
}


bool do_command(char command, Stack &numbers)
/*
Pre:  The first parameter specifies a valid calculator command.
Post: The command specified by the first parameter
      has been applied to the Stack of numbers given by the second parameter.
      A result of true is returned unless command == 'q'.
Uses: The class Stack.
*/

{
   double p, q;
   switch (command) {
   case '?':
      cout << "Enter a real number: " << flush;
      cin >> p;
      if (numbers.push(p) == overflow)
         cout << "Warning: Stack full, lost number" << endl;
      break;

   case '=':
      if (numbers.top(p) == underflow)
         cout << "Stack empty" << endl;
      else
         cout << p << endl;
      break;

   case '+':
      if (numbers.top(p) == underflow)
         cout << "Stack empty" << endl;
      else {
         numbers.pop();
         if (numbers.top(q) == underflow) {
            cout << "Stack has just one entry" << endl;
            numbers.push(p);
         }

         else {
            numbers.pop();
            if (numbers.push(q + p) == overflow)
               cout << "Warning: Stack full, lost result" << endl;
         }
      }
      break;
           
           
    case '-':
        if (numbers.top(p) == underflow)
               cout << "Stack empty" << endl;
        else {
               numbers.pop();
               if (numbers.top(q) == underflow) {
                   cout << "Stack has just one entry" << endl;
                   numbers.push(p);
               }
               
               else {
                   numbers.pop();
                   if (numbers.push(q - p) == overflow)
                       cout << "Warning: Stack full, lost result" << endl;
               }
        }
        break;
           
    
           
    case '*':
        if (numbers.top(p) == underflow)
                  cout << "Stack empty" << endl;
        else {
                  numbers.pop();
                  if (numbers.top(q) == underflow) {
                      cout << "Stack has just one entry" << endl;
                      numbers.push(p);
                  }
                  
                  else {
                      numbers.pop();
                      if (numbers.push(q * p) == overflow)
                          cout << "Warning: Stack full, lost result" << endl;
                  }
        }
        break;
           
           
    case '/':
        if (numbers.top(p) == underflow)
                     cout << "Stack empty" << endl;
        else {
                     numbers.pop();
                     if (numbers.top(q) == underflow) {
                         cout << "Stack has just one entry" << endl;
                         numbers.push(p);
                     }
                     
                     else {
                         numbers.pop();
                         if (numbers.push(q / p) == overflow)
                             cout << "Warning: Stack full, lost result" << endl;
                     }
        }
        break;

           
           
    //1.1.2.
    case 'x':
        if (numbers.top(p) == underflow)
                        cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }
            
            else {
                numbers.pop();
                if (numbers.push(p) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
                else if (numbers.push(q) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        }
        break;
              
              
           
    
    //1.1.3
    case 's':
        if (numbers.top(p) == underflow)
                cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }
            
            else {
                numbers.pop();
                double i = 0, sum = p+q;
                while (numbers.top(i) != underflow) {
                    sum += i;
                    numbers.pop();
                }
                
                if (numbers.push(sum) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
        
            }
        }
        break;
           
           
    //1.1.4
    case 'a':
           if (numbers.top(p) == underflow)
               cout << "Stack empty" << endl;
           else {
               numbers.pop();
               if (numbers.top(q) == underflow) {
                   cout << "Stack has just one entry" << endl;
                   numbers.push(p);
               }
               
               else {
                   numbers.pop();
                   double i = 0, sum = p+q;
                   int counter = 0;
                   while (numbers.top(i) != underflow) {
                       sum += i;
                       counter++;
                       numbers.pop();
                   }
                   
                   if (numbers.push(sum/(counter+2)) == overflow)
                       cout << "Warning: Stack full, lost result" << endl;
                   
               }
           }
           break;
                     
   //1.1.5
       case '^':
           if (numbers.top(p) == underflow)
               cout << "Stack empty" << endl;
           else {
               numbers.pop();
               if (numbers.top(q) == underflow) {
                   cout << "Stack has just one entry" << endl;
                   numbers.push(p);
               }
               
               else {
                   numbers.pop();
                   if (numbers.push(pow(q, p)) == overflow)
                       cout << "Warning: Stack full, lost result" << endl;
                   
               }
           }
           break;

        //1.1.5
       case 'v':
           if (numbers.top(p) == underflow)
               cout << "Stack empty" << endl;
           else {
               numbers.pop();
               if (numbers.push(sqrt(p)) == overflow)
                   cout << "Warning: Stack full, lost result" << endl;
           }
           break;
    
 
        //1.1.5
       case '%':
           if (numbers.top(p) == underflow)
               cout << "Stack empty" << endl;
           else {
               numbers.pop();
               if (numbers.top(q) == underflow) {
                   cout << "Stack has just one entry" << endl;
                   numbers.push(p);
               }
               
               else {
                   numbers.pop();
                   if (numbers.push(remainder(q, p)) == overflow)
                       cout << "Warning: Stack full, lost result" << endl;
               }
           }
           break;
           
 

    case 'q':
      cout << "Calculation finished.\n";
      return false;
   }
   return true;
}



void classic_calculator() {
    char ch;
    Stack calc_stack;
    double number;
    string line, expression, symbols;
    cin.ignore();
    getline(cin,line);
    
    istringstream linestream(line);
    while (linestream >> line) {
        //cout << "Line =" << line << endl;
        istringstream expression(line);
        if (expression >> number) {
            calc_stack.push(number);
            cout << "Current stack (recent entry on the left): ";
            calc_stack.print();
        }
        else
            if (isOperation(line))
            {
                do_command(line[0], calc_stack);
                cout << "Current stack (recent entry on the left): ";
                calc_stack.print();
            }
            else
            {
                cout << "Invalid expression!" << endl;
                break;
            }
    }
    
}


bool isOperation (string expression) {
    
    if (expression == "+" || expression == "-" || expression == "*" ||
        expression == "/" || expression == "%" || expression == "^" ||
        expression == "v" || expression == "a" || expression == "x" ||
        expression == "s")
        return true;
    else return false;
}
