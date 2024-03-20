#ifndef MAINSCREENCONTROL_H
#define MAINSCREENCONTROL_H

#include <QObject>

class MainScreenControl : public QObject {
    Q_OBJECT

public slots:

    void doStart();
};

#endif // MAINSCREENCONTROL_H
