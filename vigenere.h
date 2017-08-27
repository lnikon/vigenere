#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>

class Vigenere {
public:

  // ctor
  Vigenere();

  // Get plain text
  Vigenere(const char *pPlainText);

  // copy ctor
  Vigenere(const Vigenere& rVigenere);

  // copy assign op
  Vigenere& operator=(const Vigenere& rVigenere);

  // move ctor
  Vigenere(Vigenere&& rVigenere) noexcept;

  // move assign op
  Vigenere& operator=(Vigenere&& rVigenere) noexcept;

  // dtor
  ~Vigenere();

  // Chiper text stored in @m_sPlainText
  std::string chiper();

  // Chiper text given by @pPlainText
  std::string chiper(const char *pPlainText);

  // Chiper text given @rPlainText
  std::string chiper(const std::string& rPlainText);

  // Dechiper text stored in @m_sChiperedText
  std::string dechiper();

  // Use this in copy assign op
  friend void swap(Vigenere& rLeftVig,
                   Vigenere& rRightVig) noexcept;

  std::string sPlainText() const;
  void        setSPlainText(const std::string& sPlainText);

  std::string sChiperedText() const;
  void        setSChiperedText(const std::string& sChiperedText);

  std::string getKey() const;
  void        setKey(const std::string& rString);

private:

  std::string m_sPlainText    = "";
  std::string m_sChiperedText = "";
  std::string m_sKey          = "";
};

#endif // VIGENERE_H
