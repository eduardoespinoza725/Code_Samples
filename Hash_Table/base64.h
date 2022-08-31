// ****************************************************************************
// * Filename:   base64.h                                                      *
// * Author:     Brad Conte (brad AT bradconte.com)                            *
// * Copyright:  Creative Commons                                              *
// * Disclaimer: This code is presented "as is" without any guarantees.        *
// * Details:    Defines the API for the corresponding Base64 implementation.  *
// * Modified by: Dr. David A. Gaitros                                         *
// * Date Modified: July 8th, 2021                                             *
// * Description:  Modified for C++11 rather than the C standard libraries.    *
// *****************************************************************************

#ifndef BASE64_H
#define BASE64_H

// *****************************************************************************
// *************************** HEADER FILES ************************************
// *****************************************************************************
#include <iostream>
#include <stddef.h>
#include <string.h>
#include <cstring>
#include <string>
using namespace std;
// *****************************************************************************
// **************************** DATA TYPES *************************************
// *****************************************************************************

typedef char BYTE;             // 8-bit byte

// *****************************************************************************
// *********************** FUNCTION DECLARATIONS *******************************
// *****************************************************************************

// *****************************************************************************
// * Encodes a string into an encrypted string.   Takes in a character array   *
// *           with the size (use strlen) and outputs an encrypted version.    *
// *                                                                           *
// * How to use:                                                               *
// * BYTE in[] is a character array that contains the input string you want    *
// *           to encode. The size of the array should be large enough to hold *
// *           the largest character array you want to encode.  The NULL       *
// *           terminating character will tell the routine where to stop       *
// *           the encoding.                                                   *
// * BYTE out[] is the corresponding array that contains the output string     *
// *           of the resulting encoded output. It should never by NULL        *
// *           because the routine will only return the size of the output     *
// *           and not the output itself. The encode will generate one extra   *
// *           byte for every three input bytes so make sure the out[] size    *
// *           will be sufficient.                                             *
// * len is the number of bytes in the in[] parameter NOT COUNTING the null    *
// *           terminating character.                                          *
// * newline is a flag indicating when to insert a newline character.  Always  *
// *           make it 1.                                                      *
// *****************************************************************************

size_t base64_encode(const BYTE in[], BYTE out[], size_t len, int newline_flag);

// *****************************************************************************
// * Accepts an incoded string and decodes it.  Use strlen for the size of     *
// *           inputstring.
// * How to use:                                                               *
// * BYTE in[] is a character array that contains the input string you want    *
// *           to decode.  The NULL terminating character will tell the        *
// *           routine where to stop the dencoding.                                                   *
// * BYTE out[] is the corresponding array that contains the output string     *
// *           of the resulting decoded output. It should never by NULL        *
// *           because the routine will only return the size of the output     *
// *           and not the output itself. The decoded string will be about     *
// *           25% smaller then the encoded version.                           *
// * len is the number of bytes in the in[] parameter NOT COUNTING the null    *
// *           terminating character.                                          *
// *****************************************************************************

size_t base64_decode(const BYTE in[], BYTE out[], size_t len);

#endif   // BASE64_H
