
#include <iostream>
#include <string>
#include <array>
#include <cstring>
#include <cstdio>
#include <exception>
#include "snowman.hpp"

using namespace std;

namespace ariel{

    //define megic numbers
    const int array_size = 8;
    const int mod = 10;
    const int digits_range = 4;
    const int zero = 0;
    const int one = 1;
    const int two = 2;
    const int three = 3;
    const int four = 4;
    const int five = 5;
    const int six = 6;
    const int hatIndex = 0;
    const int s = 1;
    const int leftEyeIndex = 2;
    const int rightEyeIndex = 3;
    const int LeftArmIndex = 4;
    const int rightArmIndex = 5;
    const int s = 6;
    const int baseIndex = 7;

    
    //define arrays for each part of the snowman
    array<string,4> hats = {" _===_ ", "  ___  \n ..... ", "   _   \n  /_\\  ", "  ___  \n (_*_) "};
    array<string,4> noses = {",", ".", "_", " "};
    array<string,4> lefteye = {".", "o", "O", "-"};
    array<string,4> righteye = {".", "o", "O", "-"};
    array<string,4> leftarm = {"<", "\\", "/", " "};
    array<string,4> rightarm = {">", "/", "\\", " "};
    array<string,4> torsos = {" : ", "] [", "> <", "   "};
    array<string,4> bases = {" : ","\" \"","___","   "};

    //throw error function for invalid input
    void invalid_input(int num)
    {
        string res = "Invalid code '" + std::to_string(num) + "'";
        throw out_of_range(res);
    }

    //build the correct snowman string from the given number 
    string snowman(int num)
    {    
        if(num < zero)  //if the number is not positive 
        {            
            invalid_input(num);  //call the throw error function 
        }

        string res;
        //array to hold the number digits for more comfortable use
        array<int, array_size> digits = {};
        int current_digit = zero;
        int temp = num;
        int digit_count = zero;
        //go through each digit in the number
        while(temp > zero && digit_count < array_size)
        {
            current_digit = temp%mod;  //take the last digit 
            if(current_digit <= digits_range && current_digit > zero)  //if the digit is in range
            {
                
                digits.at((array_size-1) - digit_count) = current_digit;  //put the digit into the array in the currect index
                digit_count++;
                temp = temp / mod;  //remove the last digit from the number
            }
            else
            {
                invalid_input(num);  //call the throw error function
            }
        }
        //if the number's length wasn't like the the array's size 
        if(temp != zero || digit_count != array_size)
        {
            invalid_input(num);  //call the throw error function
        }

        //create string variables for the diff parts of his body
        string hat;
        string head;
        string body;
        string base;

        hat = hats.at(digits.at(hatIndex)-1);  //assigning to hat variable the hat format from the array by the correct index
        head = "(" + lefteye.at(digits.at(leftEyeIndex)-1) + noses.at(digits.at(noseIndex)-1) + righteye.at(digits.at(rightEyeIndex)-1) + ")";  //assigning to head variable all the wanted strings (eyes and nose)
        body = "(" + torsos.at(digits.at(torsosIndex)-1) + ")";  //assigning to body variable the body format from the array by the correct index
        base = " (" + bases.at(digits.at(baseIndex)-1) + ") ";  //assigning to base variable the base format from the array by the correct index

        //now we have to add the hands to the body and head parts respectively
        //switch case for the left arm
        switch (digits.at(LeftArmIndex))
        {
            case one:
                head = " " + head;
                body = leftarm.at(zero) + body;
                break;
            case two:
                head = leftarm.at(one) + head;
                body = " " + body;
                break;
            case three:
                head = " " + head;
                body = leftarm.at(two) + body;
                break;
            case four:
                head = " " + head;
                body = leftarm.at(three) + body;
                break;
            default:
                invalid_input(num);
        }

        //switch case for the right arm
        switch (digits.at(rightArmIndex))
        {
            case one:
                head = head + " ";
                body = body + rightarm.at(zero);
                break;
            case two:
                head = head + rightarm.at(one);
                body = body + " ";
                break;
            case three:
                head = head + " ";
                body = body + rightarm.at(two);
                break;
            case four:
                head = head + " ";
                body = body + rightarm.at(three);
                break;
            default:
                invalid_input(num);
        }
        
        //add the diffrent parts of the snowman to the one snowman string 
        res = hat + "\n" + head + "\n" + body + "\n" + base;
        return res;
    }
}


