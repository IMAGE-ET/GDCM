/*=========================================================================

  Program: GDCM (Grassroots DICOM). A DICOM library
  Module:  $URL$

  Copyright (c) 2006-2010 Mathieu Malaterre
  All rights reserved.
  See Copyright.txt or http://gdcm.sourceforge.net/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "gdcmImplementationVersionNameSub.h"
#include "gdcmSwapper.h"

namespace gdcm
{
namespace network
{
const uint8_t ImplementationVersionNameSub::ItemType = 0x55;
const uint8_t ImplementationVersionNameSub::Reserved2 = 0x00;

ImplementationVersionNameSub::ImplementationVersionNameSub()
{
  ImplementationVersionName = "OFFIS_DCMTK_355"; // OFFIS_DCMTK_35510.3.0.3.5.5
  ItemLength = ImplementationVersionName.size();
}

std::istream &ImplementationVersionNameSub::Read(std::istream &is)
{
  uint8_t itemtype = 0x0;
  is.read( (char*)&itemtype, sizeof(ItemType) );
  assert( itemtype == ItemType );
  uint8_t reserved2;
  is.read( (char*)&reserved2, sizeof(Reserved2) );
  uint16_t itemlength;
  is.read( (char*)&itemlength, sizeof(ItemLength) );
  SwapperDoOp::SwapArray(&itemlength,1);
  ItemLength = itemlength;

  char name[256];
  assert( itemlength < 256 );
  is.read( name, itemlength );
  ImplementationVersionName = name;

  return is;
}

const std::ostream &ImplementationVersionNameSub::Write(std::ostream &os) const
{
  os.write( (char*)&ItemType, sizeof(ItemType) );
  os.write( (char*)&Reserved2, sizeof(Reserved2) );
  //os.write( (char*)&ItemLength, sizeof(ItemLength) );
  uint16_t copy = ItemLength;
  SwapperDoOp::SwapArray(&copy,1);
  os.write( (char*)&copy, sizeof(ItemLength) );

  os.write( ImplementationVersionName.c_str(), ImplementationVersionName.size() );

  return os;
}

} // end namespace network
} // end namespace gdcm
