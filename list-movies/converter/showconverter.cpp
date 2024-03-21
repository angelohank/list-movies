#include "showconverter.h"

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
        show->setImagem( showObject.contains( ShowModel::ORIGINAL ) ?
                             showObject.value( ShowModel::ORIGINAL ).toString() :
                             showObject.value( ShowModel::MEDIUM ).toString() );
    }

    if( showObject.contains( ShowModel::RATING ) && showObject.contains( ShowModel::AVERANGE) ) {
        show->setAverage( showObject.value( ShowModel::AVERANGE ).toDouble() );
    }

    //TODO ajustar converter dos generos
//    if( showObject.contains( ShowModel::GENRES ) ) {
//        show->setGeneros( showObject.value( ShowModel::GENRES).toArray() );
//    }

    return show;
}
