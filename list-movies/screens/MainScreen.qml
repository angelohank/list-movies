import QtQuick 2.15

import "../custom"

Window {
    id: root
    width: 400
    height: 600
    visible: true
    title: qsTr( "List Movies" )

    Column {
        anchors {
            fill: parent
            topMargin: 15
        }

        spacing: 10

        SearchField {
            id: searchField
            height: 40
            width: 300

            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
