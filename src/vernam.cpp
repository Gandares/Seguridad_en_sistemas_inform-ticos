#include "../include/encrypt.hpp"

#include <stdio.h>
#include <iostream>
#include <string>

std::string XOR(std::string a, std::string b){
    std::string aux;
    for (int i=0;i<a.size();i++){
        if(a[i]==b[i])
            aux+='0';
        if(a[i]!=b[i])
            aux+='1';
    }
    return aux;
}

int main(void){

    std::string x;
    std::cout << "Introduzca el mensaje a cifrar: ";
    std::getline(std::cin,x);

    cript CR(x);

    std::string enbinario=CR.conversion(x);

    std::string laclave;
    int opt;

    std::cout << "1. Generar clave pseudoaleatoria." << std::endl << "2. Introducir clave." << std::endl << "-> ";
    std::cin >> opt;
    if(opt==1)
        laclave = CR.get_clave();
    else if(opt==2){
        std::cout << "Clave: ";
        std::cin >> laclave;
        if(laclave.size()!=enbinario.size()){
            std::cout << "Sizes de clave y mensaje distintos" << std::endl;
            return 0;
        }
    }
    else{
        std::cout << "Error en la seleccion" << std::endl;
        return 0;
    }
    

    std::cout << " " << enbinario << "   (" << CR.reverse(enbinario) << ")" << std::endl;
    std::cout << "+" << std::endl;
    std::cout << " " << laclave << "   (" << CR.reverse(laclave) << ")" << std::endl;
    for(int i=0;i<enbinario.size();i++)
        std::cout << "-";
    std::cout << "--" << std::endl;

    std::string encriptado=XOR(enbinario,laclave);

    std::cout << " " << encriptado << "   (" << CR.reverse(encriptado) << ")" << std::endl;

    std::cout << std::endl << "Para volver a conseguir el mensaje original, se debe aplicar al mensaje encriptado una operacion XOR";
    std::cout << std::endl << std::endl;
    std::cout << " " << encriptado << "   (" << CR.reverse(encriptado) << ")" << std::endl;
    std::cout << "+" << std::endl;
    std::cout << " " << laclave << "   (" << CR.reverse(laclave) << ")" << std::endl;
    for (int i = 0; i < enbinario.size(); i++)
        std::cout << "-";
    std::cout << "--" << std::endl;
    encriptado = XOR(encriptado, laclave);
    std::cout << " " << encriptado << "   (" << CR.reverse(encriptado) << ")" << std::endl;
}