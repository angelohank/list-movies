import QtQuick 2.15

import "../custom"

Item {
    id: root

    signal finish

    Column {
        id: container

        anchors {
            fill: parent
            topMargin: 15
            leftMargin: 10
            rightMargin: 10
        }

        spacing: 15

        Rectangle {
            id: detailContainer

            height: parent.height * 0.9
            width: parent.width

            Text {
                anchors.centerIn: parent
                text: "detail screen"
            }
        }

        //TODO ajustar responsividade vertical
        ButtonCustom {
            id: returnButton

            height: parent.height * 0.05
            width: parent.width * 0.15
            anchors.horizontalCenter: parent.horizontalCenter
            //TODO adicionar icone
            src: "qrc:/resources/images/RETURN-ICON.png"

            onClicked: {
                root.finish()
            }
        }
    }
}
