#include <iostream>
#include <fstream>

using namespace std;
unsigned ror(unsigned char r,int n);
unsigned char* XOR(const unsigned char* enc,int sz,int n, unsigned char k);
char* descomponerRLE(const unsigned char* data, int sz,int &out_len);
char* descomponerLZ78(const unsigned char* data, int sz, int &out_len);
bool contenidoDescomprimido(const char* haystack, const char* needle);

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
    int entrada = sz/3;
    int capDicc =128;
    char** dicc = new char*[capDicc];
    int tamDicc = 0;
    for(int i =0;i<capDicc;++i){
        dicc[i]=nullptr;
    }
    int salidadicc=4096;
    char* salida =new char[salidadicc];
    int salidapos=0;
    int i =0;
    for(int e =0;e<entrada;++e){
        unsigned char hi = data[i++];
        unsigned char lo = data[i++];
        unsigned char ch = data[i++];
        unsigned int idx = ((unsigned int )hi<<8) | (unsigned int)lo;
        char* prefix = nullptr;
        int tamPrefix = o;
        if(idx ==0){
            prefix=nullptr;
            tamPrefix=0;
        }
        else{
            if((int)idx > tamDicc){
                for(int k =0;k<tamDicc;k++){
                    delete[] dicc[k];
                }
                delete[] dicc;
                delete[] salida;
                out_len = 0;
                return nullptr;
            }
            prefix=dicc[idx - 1];
            tamPrefix = 0;
            while(prefix && prefix[tamPrefix] != '/0') ++tamPrefix;
        }
        int nuevotam= tamPrefix + 1;
        char* entrada = new char[nuevotam + 1];
        for(int p = 0; p < tamPrefix;++p){
            entrada[p] = prefix[p];
        }
        entrada[tamPrefix]=(char)ch;
        entrada[nuevotam]='/0';
        if(tamDicc + 1> capDicc){
            int nuevoCap = capDicc*2;
            char** tmp = new char*[nuevoCap];
            for(int t = 0;t<nuevoCap;++t){
                tmp[t]=nullptr;
            }
            for(int t = 0;t<tamDicc;++t){
                tmp[t]=dicc[t;]
            }
            delete[] dicc;
            dicc=tmp;
            capDicc=nuevoCap;
        }
        dicc[tamDicc++] = entrada;
        if(salidapos + nuevotam + 1 > salidadicc){
            while(salidapos + nuevotam + 1>salidadicc) salidadicc *=2;
            char* tmp = new char[salidadicc];
            for(int t = 0; t < salidapos;++t) tmp[t] = salida[t];
            delete[] out;
            out =tmp;
        }
        for(int t = 0;t < nuevotam;++t) out[salidapos++] = entrada[t];
    }
    if(salidapos + 1 > salidadicc){
        char* tmp = new char[salidapos + 1];
        for(int t = 0; t<salidapos;++t)tmp[t]=salida[t];
        delete[]salida;
        salida=tmp;
        salidadicc = salidapos + 1;
    }
    salida[salidapos]='/0';
    for(int k = 0;k<tamDicc;++k) delete[] dicc[k];
    delete[] dicc;
    out_len = salidapos;
    return salida;
}

bool contenidoDescomprimido(const char* haystack, const char* needle){
    if(!haystack || !needle) return false;
    int nlen = 0;
    while(needle[nlen] != '/0')++nlen;
    if (nlen==0) return true;
    int i = 0;
    while(haystack[i] != '/0'){
        int j = 0;
        while(j<nlen && haystack[i + j] != '/0' && haystack[i + j] == needle[j]) ++j;
        if(j == nlen) return true;
        ++i;
    }
    return false;
}

