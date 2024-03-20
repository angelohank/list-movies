#include "movieconverter.h"

#include <QJsonArray>
#include <QJsonObject>

QList<MovieModel*> MovieConverter::fromJson( const QJsonDocument& json ) {
    QList<MovieModel*> movies = {};

    if( json.isArray() ) {
         QJsonArray jsonArray = json.array();

         for ( const auto& jsonValue : jsonArray ) {
             if ( jsonValue.isObject() ) {

                 MovieModel* movie = new MovieModel();
                 QJsonObject jsonObj = jsonValue.toObject();

                 if( jsonObj.contains("score") ) {
                    movie->setScore(jsonObj.value("score").toDouble());
                 }

                 if( jsonObj.contains("show") ) {
                     movie->setShow( showConverter.fromJson( jsonObj ) );
                 }

                 movies.append(movie);
                 //DELETAR O PONTEIRO OU NAO? testar
                 }
             }
         }
    return movies;
}
