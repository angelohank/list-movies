import QtQuick 2.15

import "../custom"

Item {
    id: root

    signal finish

    Column {
        id: container

        anchors.fill: parent

        Rectangle {
            height: parent.height * 0.9
            width: parent.width

            Text {
                anchors.centerIn: parent
                text: "detail screen"
            }
        }

        ButtonCustom {
            height: 50
            width: 50
            anchors.horizontalCenter: parent.horizontalCenter

            onClicked: {
                root.finish()
            }
        }
    }
}
