#include "iosutils.h"

IosUtils::IosUtils( QObject *parent ): QObject( parent )
{
  mImagePicker = new IOSImagePicker();
  QObject::connect( mImagePicker, &IOSImagePicker::imageCaptured, this, &IosUtils::imageSelected );
}

bool IosUtils::isIos() const
{
#ifdef Q_OS_IOS
  return true;
#else
  return false;
#endif
}

void IosUtils::callImagePicker( const QString &targetPath )
{
  mImagePicker->showImagePicker( 0, targetPath );
}

void IosUtils::callCamera( const QString &targetPath )
{
  mImagePicker->showImagePicker( 1, targetPath );
}

IOSImagePicker *IosUtils::imagePicker() const
{
  return mImagePicker;
}
