#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>

using namespace std;

#include "vigenere.hpp"

Vigenere::Vigenere() { memoryAllocation(); }

Vigenere::Vigenere(const char* pPlainText) {
  memoryAllocation();

  if (strlen(pPlainText) > mTextSize) {
    delete[] mPlainText;
    mPlainText = nullptr;

    mTextSize = strlen(pPlainText);
    mPlainText = new char[mTextSize];
  }

  strncpy(mPlainText, pPlainText, strlen(mPlainText));
}

Vigenere::~Vigenere() {
  delete[] mPlainText;
  delete[] mChiperText;
  delete[] mTemporaryPlainText;
}

void Vigenere::memoryAllocation() {
  mPlainText = new char[mTextSize];
  mPlainText[0] = '\0';

  mChiperText = new char[mTextSize];
  mChiperText[0] = '\0';

  mTemporaryPlainText = new char[mTextSize];
  mTemporaryPlainText[0] = '\0';
}
