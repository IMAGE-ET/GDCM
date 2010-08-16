/*=========================================================================
:w

  Program: GDCM (Grassroots DICOM). A DICOM library
  Module:  $URL$

  Copyright (c) 2006-2010 Mathieu Malaterre
  All rights reserved.
  See Copyright.txt or http://gdcm.sourceforge.net/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#ifndef GDCMMAXIMUMLENGTHSUB_H
#define GDCMMAXIMUMLENGTHSUB_H

#include "gdcmTypes.h"

namespace gdcm
{

namespace network
{

/**
Annex D
Table D.1-1
MAXIMUM LENGTH SUB-ITEM FIELDS (A-ASSOCIATE-RQ)

Table D.1-2
Maximum length sub-item fields (A-ASSOCIATE-AC)
 */
class MaximumLengthSub
{
public:
  MaximumLengthSub();
  std::istream &Read(std::istream &is);
  const std::ostream &Write(std::ostream &os) const;
private:
  static const uint8_t ItemType;
  static const uint8_t Reserved2;
  uint16_t ItemLength;
  uint32_t MaximumLength;
};

} // end namespace network

} // end namespace gdcm

#endif //GDCMMAXIMUMLENGTHSUB_H
