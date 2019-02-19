#include "../include/encrypt.hpp"

cript::cript(std::string message):
mensaje(message)
{
    crearclave();
}

void cript::crearclave(void){
    srand(time(NULL));
    for(int i=0;i<mensaje.size()*8;i++){
        int random=rand()%2;
        if(random==0)
            clave+='0';
        else
            clave+='1';
    }       
}

std::string cript::conversion(std::string message){
    std::string aux;
    for(int i=0;i<message.size();i++){
        char x=message[i];
        int dec=x;
        dec++;
        std::string bin=dectobin(dec);
        for(int j=0;j<bin.size();j++){
            aux+=bin[j];
        }
    }
    return aux;
}

std::string cript::dectobin(int dec){
    int const bitmax=8;
    int ponderacion[bitmax]={128,64,32,16,8,4,2,1};
    std::string bin;
    for(int i=0;i<bitmax;i++){
        if(dec>ponderacion[i]){
            dec-=ponderacion[i];
            bin+='1';
        }
        else
            bin+='0';
    }
    return bin;
}

int cript::bintodec(std::string bin){
    int const bitmax=8;
    int ponderacion[bitmax]={128,64,32,16,8,4,2,1};
    int dec=0;
    for (int i=0;i<bitmax;i++){
        if(bin[i]=='1')
            dec+=ponderacion[i];
    }
    dec++;
    return dec;
}

std::string cript::reverse(std::string bin){
    std::string aux;
    int cont=0;
    for(int i=0;i<bin.size()/8;i++){
        std::string caracter;
        for(int j=0;j<8;j++){
            caracter+=bin[cont];
            cont++;
        }
        int dec=bintodec(caracter);
        dec--;
        char c=dec;
        aux+=c;
    }
    return aux;
}

std::string cript::get_clave(void){
    return clave;
}