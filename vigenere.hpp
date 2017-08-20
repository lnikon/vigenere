#pragma once

class Vigenere {
  public:
  typedef unsigned long long size_t;

  public:
  /*
   * Default Ctor
   */
  Vigenere();

  /*
   * Get plain text from user copy it to @plainText filed
   */
  Vigenere(const char *pPlainText);

  /*
   * Allocate necessary memory for
   * @plainText and @chiperText dynamically
   */
  void memoryAllocation();

  /*
   * Default dtor
   */
  ~Vigenere();

  /*
   * Cipher plain text and copy it to the @chiperText
   */
  void chiper();

  /*
   * Dechiper text from @chiperText and save it to
   * temporaryPlainText
   */
  void dechiper();

  /*
   * Setter and getter for textSize
   */
  const int &getTextSize() const;

  private:
  char *mPlainText = nullptr;
  char *mChiperText = nullptr;
  char *mTemporaryPlainText = nullptr;
  int mKey = -1;
  size_t mTextSize = 2;

  void setTextSize(const int &rTextSize);
};
