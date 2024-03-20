#include "showconverter.h"

ShowModel* ShowConverter::fromJson( const QJsonObject& json) const {

    QJsonObject showObject = json.value("show").toObject();
    ShowModel* show = new ShowModel();

    //TODO isolar key no showModel
    if( showObject.contains("name") ) {
        show->setNome( showObject.value("name").toString() );
    }

    if( showObject.contains("summary") ) {
        show->setDescricao( showObject.value("summary").toString() );
    }

    //IMAGE
    //RATING -> AVERAGE
    //GENEROS

    return show;
}
