#include <iostream>
#include <string>

using namespace std;

#include "vigenere.h"
#include "clogger.h"

int main()
{
  //  Work's fine
  //  {
  //    Vigenere vig;

  //    std::string plainText = "Bilibirda";
  //    vig.setKey("heEllOOVaAHAgG");
  //    cout << '\n';

  //    vig.chiper(plainText);
  //    cout << vig.sChiperedText() << '\n';
  //  }

  {
    Vigenere vig("BAREV LIANA");
    vig.setKey("VAHAG");
    cout << '\n';
    cout << vig.chiper() << '\n';
    cout << vig.dechiper() << '\n';
  }

  return 0;
}
