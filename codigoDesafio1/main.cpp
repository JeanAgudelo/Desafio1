#include <iostream>
#include <fstream>

using namespace std;
unsigned ror(unsigned char r,int n);
unsigned char* XOR(const unsigned char* enc,int sz,int n, unsigned char k);
char* descomponerRLE(const unsigned char* data, int sz,int &out_len);
char* descomponerLZ78(const unsigned char* data, int sz, int &out_len);

int main()
{
    cout << "esta es mi primer avance del desafio" << endl;
    cout << "Cuantos casos vas a evaluar? ";
    int ncases = 0;
    if (!(cin >> ncases)) {
        cout << "Entrada invalida.\n";
        return 1;
    }
    char dunny;
    cin.get(dunny);

    for(int numCasos = 0;numCasos <=ncases; ++numCasos){

    }
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
        unsigned char ch = data[i++];
        if (outpos+(int)num + 1>cap) {
            while (outpos + (int)num + 1 > cap) cap *= 2;
            char* tmp = new char[cap];
            for (int k = 0; k < outpos; ++k) tmp[k] = out[k];
            delete[] out;
            out = tmp;
        }
        for(long long r = 0;r<num;++r)
            out[outpos++] = (char)ch;
    }
    if(outpos+1>cap){
        char* tmp = new char[outpos+1];
        for(int k =0;k<outpos;++k)
            tmp[k] = out[k];
        delete[] out;
        out = tmp;
        cap =outpos + 1;
    }
    out[outpos] = '\0';
    out_len = outpos;
    return out;
}
//voy a iniciar a descomponer el LZ78 a partir de hoy, creo que es la parte mas dificil y no he podido desifrar como hacerlo, estube investigando en algunos sitios de internet y siempre es largo y tedioso.

char* descomponerLZ78(const unsigned char* data, int sz, int &out_len){

}


