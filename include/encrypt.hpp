#include <string>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <sstream>

class cript{

    private:

        std::string mensaje;
        std::string clave;

    public:

      cript(std::string message);
      void crearclave(void);
      std::string conversion(std::string message);
      std::string dectobin(int dec);
      int bintodec(std::string bin);
      std::string reverse(std::string bin);
      std::string get_clave(void);
};