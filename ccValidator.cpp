#include <iostream>

void getCc(std::string &cc);
int evenSum(const std::string cc);
int oddSum(const std::string cc);

int main(){
    // variable we need to store credit card and total value after doing luhn algorithm.
    std::string cc;
    int result = 0;

    // Asking user to input cc and calling functions to get total sum after doing luhn algorithm.
    getCc(cc);
    result = evenSum(cc) + oddSum(cc);
    
    // If total sum received from luhn algorithm is divisible by 10 then that means it's valid, we are doing the same below.
    if(result % 10 == 0){
        std::cout << cc << " is valid!\n";
    }
    else{
        std::cout << cc << " is not valid!\n";
    }

    return 0;
}

void getCc(std::string &cc) // Referenced to original variable using '&' to directly assign value from user input.
{ 
    // Running a loop for input until user enter exact 16 digits digits.
    do{
        std::cout << "Enter you cc: ";
        std::cin >> cc;

        if(cc.size() != 16) // if user enters more than 16 or less than that, then we will show error!
        {
            std::cout << "Error, Please enter 16 digits cc!\n";
        }

    }while(cc.size() != 16); // Asking for cc input until user enters exactly 16 digits.
}

// Function to multiply digits at even position from left by 2 and if it is greater than 9
// The code will seprate them into two and then add them like: 18, seperated: 1, 8, adding: 1+8.
// We can do this by little trick in maths which is done below by getting remainder of 10,
// Then dividing the multiplied number by 10 then adding both of them together to the process as above lines.
int evenSum(const std::string cc){
    int total = 0;
    int temp = 0;

    for(int i = cc.size() - 2; i >= 0; i -= 2){
        temp = (cc[i] - '0') * 2;  // Doubling the digit.
        temp = (temp % 10) + (temp / 10); // seperating them and then adding together.
        total += temp; // adding the result in total which is being returned by function in the end.
    }
    return total; // returing total even sum after multiplying by 2 and adding them all.
}
int oddSum(const std::string cc)
{
    int total = 0;

    for(int i = cc.size() - 1; i >= 0; i -= 2) // from left odd position of numbers, we are adding all digits. 
    {
        total += cc[i] - '0'; // - '0' because in ASCII 0 is 48 and in ASCII doing subtraction with 0 with do - 48 which will give the actual number.
    }
    
    return total;
}
