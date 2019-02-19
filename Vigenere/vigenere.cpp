#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#define modulo 26

int main(void){
    std::string clave;
    std::string mensaje;
    std::cout << "Mensaje a encriptar: ";
    std::getline(std::cin,mensaje);
    std::cout << "Clave: ";
    std::cin >> clave;

    /////////////////////////QUITAR ESPACIOS DEL TEXTO

    int espacios[mensaje.size()];
    std::string aencriptar;
    int contador=0;
    for(int i=0;i<mensaje.size();i++){
        if(mensaje[i]==' '){
            espacios[contador]=i;
            contador++;
        }
        else
            aencriptar.push_back(mensaje[i]);
    }

    ////////////////////////////PARTIR EL TEXTO EN FRAGMENTOS TAMAÑO CLAVE 

    std::vector<std::string> partido;
    int aux=0;
    int restriccion;
    if(aencriptar.size()%clave.size()==0)
        restriccion=aencriptar.size()/clave.size();
    else
        restriccion=(aencriptar.size()/clave.size())+1;
    
    for(int i=0;i<restriccion;i++){
        std::string partes;
        for(int j=0;j<clave.size();j++){
            if(aux<aencriptar.size()){
                partes.push_back(aencriptar[aux]);
                aux++;
            }
        }
        partido.push_back(partes);
    }

    ///////////////////////////MOSTRAR TEXTO Y CLAVE

    std::cout << std::endl << "Mensaje:   ";
    for(int i=0;i<partido.size();i++)
        std::cout << partido[i] << " ";
    std::cout << std::endl << "->" << std::endl << "Clave:     ";
    for(int i=0;i<partido.size()-1;i++)
        std::cout << clave << " ";
    for (int i=0;i<aencriptar.size()%clave.size();i++)
        std::cout << clave[i];
    if (aencriptar.size()%clave.size()==0)
        std::cout << clave;
    std::cout << std::endl;

    //////////////////////ENCRIPTAR (DESPPLAZAR)

    aux=0;
    std::vector<std::string> encriptado;
    for(int i=0;i<restriccion;i++){
        std::string parte;
        for(int j=0;j<clave.size();j++){
            if (aux<aencriptar.size()){
                int x1 = clave[j];
                int x2 = aencriptar[aux];
                x1 -= 65;
                x2 -= 65;
                int sol = x1 + x2;
                if (sol > 25)
                    sol -= modulo;
                sol += 65;
                char x3 = sol;
                parte.push_back(x3);
                aux++;
            }
        }
        encriptado.push_back(parte);
    }

    ////////////////////////////////////MOSTRAR TEXTO ENCRIPTADO

    std::cout << "Virgenere: ";
    for(int i = 0;i<encriptado.size(); i++)
        std::cout << encriptado[i] << " ";
    std::cout << std::endl << std::endl;

    /////////////////////////////////////MOSTRAR POR PANTALLA PPARA EL DESENCRIPPTADO

    std::cout << "Para desencriptar el mensaje se debe desplazar la clave al reves con la contrasena" << std::endl << std::endl;
    std::cout << "Virgenere: ";
    for(int i=0;i<encriptado.size();i++)
        std::cout << encriptado[i] << " ";
    std::cout << std::endl << "<-" << std::endl << "Clave:     ";
    for (int i = 0; i < partido.size() - 1; i++)
        std::cout << clave << " ";
    for (int i = 0; i < aencriptar.size() % clave.size(); i++)
        std::cout << clave[i];
    if (aencriptar.size() % clave.size() == 0)
        std::cout << clave;
    std::cout << std::endl;

    ///////////////////////////////////////DESENCRIPTAR

    aux=0;
    std::vector<std::string> normal;
    for(int i=0;i<restriccion;i++){
        std::string parte;
        for(int j=0;j<clave.size();j++){
            if(aux<aencriptar.size()){
                int x1=clave[j];
                int x2=encriptado[i][j];
                x1-=65;
                x2-=65;
                int sol=x2-x1;
                if(sol<0)
                    sol+=modulo;
                sol+=65;
                char x3=sol;
                parte.push_back(x3);
                aux++;
            }
        }
        normal.push_back(parte);
    }

    std::cout << "Normal:    ";
    for (int i = 0; i < encriptado.size(); i++)
        std::cout << normal[i] << " ";
    std::cout << std::endl << std::endl;
}