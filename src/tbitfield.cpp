// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"
#include "../include/tbitfield.h"

#include <math.h>

TBitField::TBitField(int len): BitLen(len)
{
    int SizeOfTelem = sizeof(TELEM) * 8;
    MemLen = (BitLen + SizeOfTelem - 1) / SizeOfTelem; // округление вверх
    pMem = new TELEM[MemLen];
    for (size_t i = 0; i < MemLen; ++i) { // тк массив telem'ов
        pMem[i] = 0;
    }
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    MemLen = bf.MemLen;
    BitLen = bf.BitLen;
    pMem = new TELEM[MemLen];
    for (size_t i = 0; i < MemLen; ++i) {
        pMem[i] = bf.pMem[i];
    }
}

TBitField::~TBitField()
{
    delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    return n / (sizeof(TELEM) * 8); //тк индексация идет с нуля, не прибавляем 1
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    int IndexInMem = n % (sizeof(TELEM) * 8);
    TELEM Mask = (1 << IndexInMem);
    return Mask;
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    pMem[GetMemIndex(n)] | GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    pMem[GetMemIndex(n)] | (~GetMemMask(n));
}

int TBitField::GetBit(const int n) const // получить значение бита
{
  return pMem[GetMemIndex(n)] & GetMemMask(n);
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (this != &bf) {
        delete[] pMem;
        BitLen = bf.BitLen;
        MemLen = bf.MemLen;
        pMem = new TELEM[MemLen];
        for (size_t i = 0; i < MemLen; ++i) {
            pMem[i] = bf.pMem[i];
        }
    }
    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
  return 0;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
  return 0;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    return TBitField(0);
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    return TBitField(0);
}

TBitField TBitField::operator~(void) // отрицание
{
    return TBitField(0);
}

// ввод/вывод

std::istream &operator>>(std::istream &istr, TBitField &bf) // ввод
{
    return istr;
}

std::ostream &operator<<(std::ostream &ostr, const TBitField &bf) // вывод
{
    return ostr;
}
