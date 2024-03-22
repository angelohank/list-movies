#include "showconverter.h"

#include <QJsonArray>

ShowModel* ShowConverter::fromJson( const QJsonObject& json) const {

    QJsonObject showObject = json.value( ShowModel::SHOW ).toObject();
    ShowModel* show = new ShowModel();

    if( showObject.contains( ShowModel::NAME ) ) {
        show->setNome( showObject.value( ShowModel::NAME ).toString() );
    }

    if( showObject.contains( ShowModel::SUMMARY ) ) {
        show->setDescricao( showObject.value( ShowModel::SUMMARY ).toString() );
    }

    if( showObject.contains(ShowModel::IMAGE ) ) {

        QJsonObject imageObject = showObject.value( ShowModel::IMAGE ).toObject();

        if( imageObject.contains( ShowModel::ORIGINAL ) ) {
            show->setImagem( imageObject.value( ShowModel::ORIGINAL ).toString() );
        }
    }

    if( showObject.contains( ShowModel::RATING ) ){
        QJsonObject ratingObject = showObject.value( ShowModel::RATING ).toObject();

        if( ratingObject.contains( ShowModel::AVERANGE ) ) {
            show->setAverage( ratingObject.value( ShowModel::AVERANGE ).toDouble() );
        }
    }

    if( showObject.contains( ShowModel::GENRES ) ) {
        QJsonArray genres = showObject.value( ShowModel::GENRES ).toArray();

        QList<QString> genresToString = {};

        for( auto genre : genres ) {
            genresToString.append( genre.toString() );
        }

        show->setGeneros( genresToString );
    }

    return show;
}
