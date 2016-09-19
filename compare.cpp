//
//  main.cpp
//  CompareFigures
//
//  Created by NATURE on 19/9/2016.
//  Copyright © 2016 NATURE. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int counter=0;
int main(int argc, const char * argv[]) {
    if(argc!=3){
        cout<<"args number should be 3\n";
        return 0;
    }
    const char* file1=argv[1];
    const char* file2=argv[2];
    ifstream ins1;
    ifstream ins2;
    ins1.open(file1,ios::in);
    ins2.open(file2,ios::in);
    while(true){
        if(ins1.eof()){
            cout<<"first file reach the end\n";
            printf("difference occurs %d times\n",counter);
            exit(0);
        }
        if(ins2.eof()){
            cout<<"second file reach the end\n";
            printf("difference occurs %d times\n",counter);
            exit(0);
        }
        string number1,number2;
        if(number1==""||number2==""){
            cout<<"file reach the end\n";
            printf("difference occurs %d times\n",counter);
            exit(0);
        }
        ins1>>number1;
        ins2>>number2;
        float n1,n2;
        n1=atof(number1.c_str());
        n2=atof(number2.c_str());
        if(abs(n1-n2)>=0.00001)
            counter++;
        
    }
    return 0;
}
