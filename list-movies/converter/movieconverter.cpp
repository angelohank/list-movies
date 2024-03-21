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

                 if( jsonObj.contains( MovieModel::SCORE ) ) {
                    movie->setScore(jsonObj.value( MovieModel::SCORE ).toDouble());
                 }

                 if( jsonObj.contains( ShowModel::SHOW ) ) {
                     movie->setShow( showConverter.fromJson( jsonObj ) );
                 }

                 movies.append( movie );

                 }
             }
         }

    return movies;
}
