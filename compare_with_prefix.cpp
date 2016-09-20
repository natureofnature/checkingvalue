//
//  main.cpp
//  CompareFigures
//
//  Created by NATURE on 19/9/2016.
//  Copyright © 2016 NATURE. All rights reserved.
//

/*
    Note! give the first non-ignore value to KEYWORD
 */

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int counter=0;
int pass=0;
#define FILTER
#ifdef FILTER
bool filter=true;
#define KEYWORD "0.000000"
#endif
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
        pass++;
        if(pass%100000==0){
            printf("have compared %d with %d diffrentces \n",pass, counter);
        }
        if(ins1.eof()){
            cout<<"have compared "<<pass<<" times"<<endl;
            cout<<"first file reach the end\n";
            printf("difference occurs %d times\n",counter);
            exit(0);
        }
        if(ins2.eof()){
            cout<<"have compared "<<pass<<" times"<<endl;
            cout<<"second file reach the end\n";
            printf("difference occurs %d times\n",counter);
            exit(0);
        }
        string number1,number2;
        ins1>>number1;
        ins2>>number2;


#ifdef FILTER
        /*according to your need*/
        while(filter&&number2!=KEYWORD){
            ins2>>number2;
            cout<<"number2 "<<number2<<endl;
        }
        
        filter=false;
#endif

        if(number1==""||number2==""){
            cout<<"have compared "<<pass<<" times"<<endl;
            cout<<"file reach the end\n";
            printf("difference occurs %d times\n",counter);
            exit(0);
        }
        float n1,n2;
        n1=atof(number1.c_str());
        n2=atof(number2.c_str());
        if(abs(n1-n2)>=0.00001){
            printf("%f vs %f =>Source ",n1,n2);
            cout<<number1<<" is different from "<<number2<<endl;
            counter++;
        }
        
        
    }
    ins1.close();
    ins2.close();
    return 0;
}
