#include "vigenere.h"
#include "clogger.h"

Vigenere::Vigenere()
{}

Vigenere::Vigenere(const char *pPlainText)
{
  if (pPlainText)
  {
    m_sPlainText = pPlainText;
  }
  else if (pPlainText == nullptr)
  {
    LOGGER->Log("NULL pointer given as argument");
  }
  else
  {
    LOGGER->Log("Invalid text given to encrypt");
  }
}

// Copy semantics

Vigenere::Vigenere(const Vigenere& rVigenere)
{
  m_sPlainText    = rVigenere.sPlainText();
  m_sChiperedText = rVigenere.sPlainText();
  m_sChiperedText = rVigenere.getKey();
}

Vigenere& Vigenere::operator=(const Vigenere& rVigenere)
{
  Vigenere copy(rVigenere);

  swap(*this, copy);
  return *this;
}

// Move semantics
Vigenere::Vigenere(Vigenere&& rVigenere) noexcept
  : m_sPlainText(""),
  m_sChiperedText(""),
  m_sKey("")
{
  swap(*this, rVigenere);
}

Vigenere& Vigenere::operator=(Vigenere&& rVigenere) noexcept
{
  swap(*this, rVigenere);
  return *this;
}

Vigenere::~Vigenere()
{}

std::string Vigenere::chiper()
{
  if (!m_sPlainText.empty())
  {
    chiper(m_sPlainText);
  }
  else
  {
    LOGGER->Log("No text to encrypt!\n");
    LOGGER->Log("If you use chiper() wihtout arguments, "
                "you must call object like this vigenereOb(" "textToEncrypt" "");
  }
  return m_sChiperedText;
}

std::string Vigenere::chiper(const char *pPlainText)
{
  if (pPlainText)
  {
    m_sPlainText = pPlainText;
    chiper(m_sPlainText);
  }
  else if (pPlainText == nullptr)
  {
    LOGGER->Log("NULL pointer given as argument");
  }
  else
  {
    LOGGER->Log("Invalid text given to encrypt");
  }

  return m_sChiperedText;
}

std::string Vigenere::chiper(const std::string& rPlainText)
{
  if (!rPlainText.empty())
  {
    m_sPlainText = rPlainText;

    int keyIndex = 0;

    for (unsigned int textIndex = 0; textIndex < rPlainText.length(); textIndex++)
    {
      char symbol = rPlainText[textIndex];

      // If @symbol is lowercase make it uppercase
      if ((symbol >= 'a') && (symbol <= 'z'))
      {
        symbol += 'A' - 'a';
      }
      else if ((symbol < 'A') || (symbol > 'Z'))
      {
        continue;
      }

      // c = m + k(mod n)
      m_sChiperedText += (symbol + m_sKey[keyIndex] - 2 * 'A') % 26 + 'A';

      keyIndex         = (keyIndex + 1) % m_sKey.length();
    }
  }
  else
  {
    LOGGER->Log("Invalid string to encrypt");
  }

  return m_sChiperedText;
}

std::string Vigenere::dechiper()
{
  std::string result = "";

  if (!m_sChiperedText.empty())
  {
    int keyIndex = 0;

    for (unsigned int textIndex = 0; textIndex < m_sChiperedText.length();
         textIndex++)
    {
      char symbol = m_sChiperedText[textIndex];

      // If @symbol is lowercase make it uppercase
      if ((symbol >= 'a') && (symbol <= 'z'))
      {
        symbol += 'A' - 'a';
      }
      else if ((symbol < 'A') || (symbol > 'Z'))
      {
        continue;
      }

      result  += (symbol - m_sKey[keyIndex] + 26) % 26 + 'A';
      keyIndex = (keyIndex + 1) % m_sKey.length();
    }
  }
  else
  {
    LOGGER->Log("There is no text to dechiper");
  }
  return result;
}

// Friend function
void swap(Vigenere& rLeftVig, Vigenere& rRightVig) noexcept
{
  std::swap(rLeftVig.m_sPlainText,    rRightVig.m_sPlainText);

  std::swap(rLeftVig.m_sChiperedText, rRightVig.m_sChiperedText);
  std::swap(rLeftVig.m_sKey,          rRightVig.m_sKey);
}

std::string Vigenere::sPlainText() const
{
  return m_sPlainText;
}

void Vigenere::setSPlainText(const std::string& sPlainText)
{
  m_sPlainText = sPlainText;
}

std::string Vigenere::sChiperedText() const
{
  return m_sChiperedText;
}

void Vigenere::setSChiperedText(const std::string& sChiperedText)
{
  m_sChiperedText = sChiperedText;
}

std::string Vigenere::getKey() const
{
  return m_sKey;
}

void Vigenere::setKey(const std::string& rKey)
{
  for (unsigned int i = 0; i < rKey.length(); i++)
  {
    if ((rKey[i] >= 'A') && (rKey[i] <= 'Z'))
    {
      this->m_sKey += rKey[i];
    }
    else if ((rKey[i] >= 'a') && (rKey[i] <= 'z'))
    {
      this->m_sKey += rKey[i] + ('A' - 'a');
    }
  }
}
