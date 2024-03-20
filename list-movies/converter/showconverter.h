#ifndef SHOWCONVERTER_H
#define SHOWCONVERTER_H

#include <QJsonObject>

#include "./model/showmodel.h"

class ShowConverter {
public:
    ShowModel* fromJson( const QJsonObject& json ) const;
};

#endif // SHOWCONVERTER_H
