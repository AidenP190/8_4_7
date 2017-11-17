/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: aparsons
 *
 * Created on November 13, 2017, 1:00 PM
 */

#include <iostream>

using namespace std;

class Matrix{
public:
    Matrix(int n1,int n2,int n3,int n4)
    {
        v[0][0] = n1;
        v[0][1] = n2;
        v[1][0] = n3;
        v[1][1] = n4;
    }
    
    void print(ostream &os) const
    {
        os<<v[0][0]<<" "<<v[0][1]<<endl;
        os<<v[1][0]<<" "<<v[1][1]<<endl;
        os<<"---------"<<endl;
    }
    
    void add(const int& rhs)
    {
        for(int i = 0; i<2;i++)
        {
            for(int j = 0;j<2;j++)
            {
                v[i][j] = v[i][j] + rhs;
            }
        }
    }
    
    void operator+(const int& rhs)
    {
        add(rhs);
    }
    
    void add(const Matrix& m)
    {
        for(int i = 0; i<2;i++)
        {
            for(int j = 0;j<2;j++)
            {
                v[i][j] += m.v[i][j];
            }
        }
    }
    void operator+(const Matrix& m)
    {
        add(m);
    }
    
    void minus(const int& rhs)
    {
        for(int i = 0; i<2;i++)
        {
            for(int j = 0;j<2;j++)
            {
                v[i][j] = v[i][j] - rhs;
            }
        }
    }
    
    void minus(const Matrix& m)
    {
        for(int i = 0; i<2;i++)
        {
            for(int j = 0;j<2;j++)
            {
                v[i][j] -= m.v[i][j];
            }
        }
    }
    
    void operator-(const int& rhs)
    {
        minus(rhs);
    }
    
    void operator-(const Matrix& m)
    {
        minus(m);
    }
    
private:
    int v[2][2];
};

int main(int argc, char** argv) {

    cout<<"Matrix A"<<endl;
    Matrix m(3,4,5,6);
    m.print(cout);
    
    cout<<"Matrix B"<<endl;
    Matrix n(7,8,9,1);
    n.print(cout);
    
    cout<<"Matrix A + 3"<<endl;
    m+3;
    m.print(cout);
    
    cout<<"Matrix A + Matrix B"<<endl;
    m+n;
    m.print(cout);
    
    cout<<"Matrix A - 3"<<endl;
    m-3;
    m.print(cout);
    
    cout<<"Matrix A - Matrix B"<<endl;
    m-n;
    m.print(cout);
}