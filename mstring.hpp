/*
 * This class will be used in compisiting with
 * logger class, so there was some limitations
 * on @mTextSize and some other things.
 */

#pragma once
#include <cstddef>
#include <cstring>
#include <iostream>
using namespace std;
class MString {
  public:
  /*
   * Default ctor
   */
  MString();

  MString(const char* pBuffer);

  /*
   * Copy ctor
   */
  MString(const MString& rMString);

  /*
   * Move ctor
   */
  MString(MString&& rMString) noexcept;
  /*
   * Dtor
   */
  ~MString() noexcept;
  /*
   * Copy assign op
   */
  MString& operator=(const MString& rMString);

  /*
   * Move assign op
   */
  MString& operator=(MString&& rMString);

  /*
   * Getters/Setters
   */

  size_t getStrMaxSize() const;
  // No setter for @mStrMaxSize cause it's an const filed

  size_t getStrDefaultSize() const;
  // No setter for @mStrDefaultSize

  /*
   * Just call @calculateStrCurrentSize()
   */
  size_t getStrCurrentSize() const;
  void setStrCurrentSize(const size_t& rCurrentSize);

  const char* getBuffer() const;
  // Implement or not implement? That is the question
  // void setBuffer();

  /*
   * Just calc (strlen(mBuffer) + 1) and return it,
   * that is include terminating null character
   */
  size_t calculateStrCurrentSize() const;

  /*
   * Allocate memory for class members
   */
  void memoryAllocation();

  /*
   * Reallocate mBuffer with new size and save information
   */
  void resize(const size_t& rNewSize);

  /*
   * Just call @getStrCurrentSize();
   */
  const size_t& size();

  private:
  static const size_t mStrMaxSize = 32768;
  static const size_t mStrDefaultSize = 2048;
  size_t mStrCurrentSize = 0;
  char* mBuffer = nullptr;
};

MString::MString() { memoryAllocation(); }

MString::MString(const char* pBuffer) {
  memoryAllocation();
  size_t newSize = strlen(pBuffer) + 1;
  if (newSize > getStrCurrentSize()) {
    resize(newSize);
  }
  strncpy(mBuffer, pBuffer, newSize);
  strcat(mBuffer, "\n");
}

MString::MString(const MString& rMString) {
  memoryAllocation();
  if (rMString.getStrCurrentSize() != mStrCurrentSize) {
    resize(rMString.getStrCurrentSize());
  }
}

MString::~MString() noexcept { delete[] mBuffer; }

const char* MString::getBuffer() const { return mBuffer; }

size_t MString::getStrMaxSize() const { return mStrMaxSize; }

size_t MString::getStrDefaultSize() const { return mStrDefaultSize; }

size_t MString::getStrCurrentSize() const { return calculateStrCurrentSize(); }

void MString::setStrCurrentSize(const size_t& rCurrentSize) {
  mStrCurrentSize = calculateStrCurrentSize();
  if (mStrCurrentSize != rCurrentSize) {
    mStrCurrentSize = rCurrentSize;
  }
}

size_t MString::calculateStrCurrentSize() const { return strlen(mBuffer) + 1; }

void MString::memoryAllocation() {
  mBuffer = new char[mStrDefaultSize];
  strcpy(mBuffer, "");
}

void MString::resize(const size_t& rNewSize) {
  // Create temporary buffer for current buffer
  char* newTempBuffer = new char[mStrCurrentSize];
  strncpy(newTempBuffer, mBuffer, strlen(newTempBuffer));

  // Delete current buffer
  // and create another one with new size equal to @rNewSize
  delete[] mBuffer;
  mBuffer = new char[rNewSize];

  // Copy temp buffer text to new buffer
  strncpy(mBuffer, newTempBuffer, strlen(mBuffer));

  // Change current size of buffer to new
  mStrCurrentSize = rNewSize;

  // Delete temp buffer
  delete[] newTempBuffer;
}
