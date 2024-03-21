#ifndef MOVIECONTROLLER_H
#define MOVIECONTROLLER_H

#include <QObject>
#include <QJsonDocument>

#include "./model/moviemodel.h"
#include "./converter/movieconverter.h"

class MovieController : public QObject {
public:
    MovieController();
    QList<MovieModel*> moviesConverter( const QByteArray& data );

private:
    QList<MovieModel*> _movies;
    MovieConverter converter;
    QJsonDocument dataToJSON( const QByteArray& data ) const;
};

#endif // MOVIECONTROLLER_H
