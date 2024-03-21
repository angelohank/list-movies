import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQml 2.15

import "../custom"
import  MainScreenControl 1.0

Item {
    id: root

    signal finish

    MainScreenControl {
        id: control
    }

    Column {
        id: container

        anchors {
            fill: parent
            topMargin: 15
            leftMargin: 10
            rightMargin: 10
        }

        spacing: 15

        SearchField {
            id: searchField
            height: parent.height * 0.07
            width: parent.width

            anchors.horizontalCenter: parent.horizontalCenter

            onSearch: function( filter ) {
                //root.finish()
                control.doStart()
            }
        }

        Divider {
            width: parent.width - 10
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Text {
            text: control.sessionDescription

            anchors.left: searchField.left
            font {
                weight: Font.Thin
                pixelSize: root.height * 0.03
                family: "Helvetica"
                italic: true
            }
        }

        Repeater {
            id: repeater
            model: control.qtMovies

            MoviePreview {

            }
        }

        //repeater com os componentes das series
    }
}
