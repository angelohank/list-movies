#ifndef MOVIECONVERTER_H
#define MOVIECONVERTER_H

#include <QJsonDocument>
#include "./model/moviemodel.h"
#include "showconverter.h"

class MovieConverter
{
public:
    QList<MovieModel*> fromJson( const QJsonDocument& json );

private:
    ShowConverter showConverter;
};

#endif // MOVIECONVERTER_H
