#include "moviecontroller.h"

#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>

MovieController::MovieController() :
    _movies( {} ){}

QList<MovieModel*> MovieController::moviesConverter( const QByteArray& data ) {
    //QList<MovieModel*> movies = {};

    QJsonDocument moviesToJSON = dataToJSON( data );
    QJsonObject jsonObject = moviesToJSON.object();

    _movies = converter.fromJson( moviesToJSON );

    return _movies;
}

QJsonDocument MovieController::dataToJSON( const QByteArray& data ) const {
    QJsonDocument JSON = QJsonDocument::fromJson( data );

    qDebug() << JSON;
    return JSON;
}
