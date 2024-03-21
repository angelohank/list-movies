#include "detailscreencontrol.h"

#include <QEventLoop>

void DetailScreenControl::doStart() {
    QEventLoop eventLoop;
    QObject::connect( this, &DetailScreenControl::quit, &eventLoop, &QEventLoop::quit );

    eventLoop.exec();
}
