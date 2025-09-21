#include <iostream>
#include <fstream>

using namespace std;
unsigned ror(unsigned char r,int n);
unsigned char* XOR(const unsigned char* enc,int sz,int n, unsigned char k);
char* descomponerRLE(const unsigned char* data, int sz,int &out_len);

int main()
{
    cout << "esta es mi primer avance del desafio" << endl;
    return 0;
}

unsigned ror(unsigned char r,int n){
    return (unsigned char)((v>>n) | (v<<(8-n))));
}

unsigned char* XOR(const unsigned char* enc,int sz,int n, unsigned char k){
    unsigned char* out = new unsigned char[sz];
    for(int i=0;i<sz;++i);{
       unsigned char b = enc[i];
       unsigned char x = b ^ K;
       unsigned char y = ror(x, n);
       out[i] = y;
       }
    return out;
}

char* descomponerRLE(const unsigned char* data, int sz,int &out_len){
    int cap = 1024;
    char* out = new char[cap];
    int outpos = 0;
    int i = 0;
    while(i<sz){
        if(!(data[i]>='0'&& data[i]<='9'))
        {
            delete[]out;out_len=0;
            return nullptr;
        }
        long long num = 0;
        while (i<sz && data[i]>='0' && data[i]<='9'){
            num = num*10+(data[i]-'0');
            ++i;
            if (num > 100000000) break;
        }
        if(i >= sz){
            delete[] out;
            out_len = 0;
            return nullptr;
        }
    }
}





