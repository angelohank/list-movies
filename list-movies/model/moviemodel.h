#ifndef MOVIEMODEL_H
#define MOVIEMODEL_H

#include <QObject>
#include "showmodel.h"

class MovieModel : public QObject {
public:
    MovieModel();

    double score() const;
    void setScore( const double score );

    ShowModel* show() const;
    void setShow( ShowModel* show );

    static constexpr const char* SCORE = "score";

private:
    double _score;
    ShowModel* _show;
};

#endif // MOVIEMODEL_H
