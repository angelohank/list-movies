#include "moviecontroller.h"

#include <QDebug>

MovieController::MovieController() {}

QList<MovieModel*> MovieController::moviesConverter( const QByteArray& data ) {
    QList<MovieModel*> movies = {};

    QJsonDocument moviesToJSON = dataToJSON( data );

    return movies;
}

QJsonDocument MovieController::dataToJSON( const QByteArray& data ) const {
    QJsonDocument JSON = QJsonDocument::fromJson( data );

    qDebug() << JSON;
    return JSON;
}
