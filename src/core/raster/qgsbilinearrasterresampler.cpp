/***************************************************************************
                         qgsbilinearrasterresampler.cpp
                         ------------------------------
    begin                : December 2011
    copyright            : (C) 2011 by Marco Hugentobler
    email                : marco at sourcepole dot ch
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "qgsbilinearrasterresampler.h"
#include <QImage>
#include <cmath>

QgsBilinearRasterResampler *QgsBilinearRasterResampler::clone() const
{
  return new QgsBilinearRasterResampler();
}

Q_NOWARN_DEPRECATED_PUSH
void QgsBilinearRasterResampler::resample( const QImage &srcImage, QImage &dstImage )
{
  dstImage = srcImage.scaled( dstImage.width(), dstImage.height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation );
}
Q_NOWARN_DEPRECATED_POP

QImage QgsBilinearRasterResampler::resampleV2( const QImage &source, const QSize &size )
{
  return source.scaled( size.width(), size.height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation );
}

QString QgsBilinearRasterResampler::type() const
{
  return QStringLiteral( "bilinear" );
}
