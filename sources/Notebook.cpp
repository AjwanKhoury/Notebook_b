#include "Notebook.hpp"
#include <iostream>
const int minA=32, maxA=126;
using namespace std;

namespace ariel
{
    void Notebook::write(int page, int row, int column, Direction direction, string const &message)
    {
        //to check if the page and row and column numbers is legal ones ! that grater than 0!
        if (page < 0 || row < 0 || column < 0)
        {
           throw std::invalid_argument("BAD INPUT! Check the page or row or column size");
        }
        //to check if the column is smaller than gthe maximum length !
        if (column>max_row_length-1)
        {
            throw std::invalid_argument("BAD INPUT! Check the column number, the max row length is 100");
        }
        //to check if the message length is legal one! grater than 0!
        if (message.length() < 0)
        {
            throw std::invalid_argument("BAD INPUT! Check the message length! its impossible to a message to be in length smaller than 0!");
        }
        //to check when we write in a horizontal direction we didn't get out of bounds !
        if (column+(int)message.length() > max_row_length && Direction::Horizontal == direction)
        {
            throw std::invalid_argument("BAD INPUT! Check the message length in!");
        }
        //test student! to pass it! (don't need it in fact:))
        for (unsigned int i = 0; i < message.length(); i++)
        {
            if (message[i]<minA || message[i]>maxA)
            {
                throw std::invalid_argument("BAD INPUT! Check the message length, it must be between 32 and 126");
            }
            
        }
        for (int i =0; i< message.length(); i++)
        {
            char t=message[(unsigned int)i];
            if (t == '~')
            {
                throw std::invalid_argument("BAD INPUT! we cant write where we have deleted message before!");
            }
           // (direction == Direction::Horizontal)? this->notebook[page][row][column+i]: this->notebook[page][row+i][column];
            char c= this->notebook[page][row+i][column];
            char cc=this->notebook[page][row][column+i];
            if (direction==Direction::Horizontal)
            {
                if ( cc < maxA+1 && cc > minA  && cc != '_')
                {
                    throw std::invalid_argument("BAD INPUT! we cant write there!");
                }
            }
            else if (direction==Direction::Vertical)
            {
                if (c < maxA+1 && c > minA && c != '_')
                {
                    throw std::invalid_argument("BAD INPUT! we cant write there!");
                }  
            }
            //(direction == Direction::Horizontal)? column+=i: row+=i;
            //this->notebook[page][row][column]= t;   
            (direction == Direction::Horizontal)? this->notebook[page][row][column+i]=t: this->notebook[page][row+i][column]=t;   
        }
        if(direction != Direction::Vertical){
            cout << 0;
        }
    }

    std::string Notebook::read(int page, int row, int column, Direction direction, int length)
    {
    //to check when we write in a horizontal direction we didn't get out of bounds !
        if (column+length > max_row_length && Direction::Horizontal == direction)
        {
            throw std::invalid_argument("BAD INPUT! Check the message length in!");
        }   
    //to check if the page and row and column numbers is legal ones ! that grater than 0!
        if (page < 0 || row < 0 || column < 0 || length < 0)
        {
           throw std::invalid_argument("BAD INPUT! Check the page or row or column size");
        }
    //to check if the column is smaller than gthe maximum length !
        if (column>max_row_length-1)
        {
            throw std::invalid_argument("BAD INPUT! Check the column number, the max row length is 100");
        }
        string s;
        for (int i =0; i< length; i++)
        {
            //(direction == Direction::Horizontal)? column+=i: row+=i;
            char c= this->notebook[page][row+i][column];
            char cc= this->notebook[page][row][column+i];
            if (direction==Direction::Horizontal){
                if (cc > maxA || cc < minA)
                {
                    s+='_';  
                }
                else{
                    s+=cc;
                }
            }
            else if (direction==Direction::Vertical)
            {
                if (c > maxA || c < minA)
                {
                    s+='_';  
                }
                else{
                    s+=c;
                }
            }
        }
        return s; 
    }
    void Notebook::erase(int page, int row, int column, Direction direction, int length)
    {
    //to check when we write in a horizontal direction we didn't get out of bounds !
        if (column+length > max_row_length && Direction::Horizontal == direction)
        {
            throw std::invalid_argument("BAD INPUT! Check the message length in!");
        }   
    //to check if the page and row and column numbers is legal ones ! that grater than 0!
        if (page < 0 || row < 0 || column < 0 || length < 0)
        {
           throw std::invalid_argument("BAD INPUT! Check the page or row or column size");
        }
    //to check if the column is smaller than gthe maximum length !
        if (column>max_row_length-1)
        {
            throw std::invalid_argument("BAD INPUT! Check the column number, the max row length is 100");
        }
        for (int i =0; i< length; i++)
        {
           // (direction == Direction::Horizontal)? column+=i: row+=i;
            //this->notebook[page][row][column]='~';  
            (direction == Direction::Horizontal)? this->notebook[page][row][column+i]='~': this->notebook[page][row+i][column]='~';
        }
    }
    void Notebook::show( int page) {
        if (page < 0)
        {
            throw std::invalid_argument("The page number must be a positive one! ERROR!!");
        }
        for (int i = 0; i < maxA; i++)
        {
            for (int j = 0; i < max_row_length; i++)
            {
                cout <<i<<':'<<" ";
                char c= this->notebook[page][i][j];
                if (c < minA || c > maxA)
                {
                    cout <<'_';
                }
                else if(c > minA || c < maxA) { 
                    cout << c;
                }
            }
            cout <<"\n";
        }
    }
}