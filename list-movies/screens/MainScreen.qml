import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQml 2.15

import "../custom"
import  MainScreenControl 1.0

Item {
    id: root

    signal showDetail( var movie )

    function doStart() {
        control.doStart()
    }

    Component.onCompleted: {
        control.doStart()
    }

    MainScreenControl {
        id: control

        onMovies: function( movies ) {
            repeater.model = movies
        }

        onShowDetail: function( movie ) {
            root.showDetail( movie )
        }
    }

    Column {
        id: container

        anchors.fill: parent

        Header {
            id: header

            width: parent.width
            height: 50
            anchors.margins: 10
        }
    }
}
