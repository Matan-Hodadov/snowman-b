//include needed files
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
    const int seven = 7;
    
    //define arrays for each part of the snowman
    //array of possible hats  
    array<string,4> hats = {" _===_ ", "  ___  \n ..... ", "   _   \n  /_\\  ", "  ___  \n (_*_) "};
    //array of possible noses 
    array<string,4> noses = {",", ".", "_", " "};
    //array of possible left eyes
    array<string,4> lefteye = {".", "o", "O", "-"};
    //array of possible right eyes 
    array<string,4> righteye = {".", "o", "O", "-"};
    //array of possible left arms 
    array<string,4> leftarm = {"<", "\\", "/", " "};
    //array of possible right arms 
    array<string,4> rightarm = {">", "/", "\\", " "};
    //array of possible torsos 
    array<string,4> torsos = {" : ", "] [", "> <", "   "};
    //array of possible bases 
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

        hat = hats.at(digits.at(zero)-1);  //assigning to hat variable the hat format from the array by the correct index
        head = "(" + lefteye.at(digits.at(two)-1) + noses.at(digits.at(one)-1) + righteye.at(digits.at(three)-1) + ")";  //assigning to head variable all the wanted strings (eyes and nose)
        body = "(" + torsos.at(digits.at(six)-1) + ")";  //assigning to body variable the body format from the array by the correct index
        base = " (" + bases.at(digits.at(seven)-1) + ") ";  //assigning to base variable the base format from the array by the correct index

        //now we have to add the hands to the body and head parts respectively
        //switch case for the left arm
        switch (digits.at(four))
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
        switch (digits.at(five))
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


