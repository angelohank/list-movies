import QtQuick 2.15
import QtQuick.Controls 2.15

import "../custom"
import DetailScreenControl 1.0

Item {
    id: root

    property var model: undefined

    signal finish

    function setModel( model ) {
        root.model = model
    }

    function doStart() {

    }

    DetailScreenControl {
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

        DetailComponent {
            id: detailComponent

            height: parent.height * 0.9
            width: parent.width

            modelData: root.model
        }

        //TODO ajustar responsividade vertical
        ButtonCustom {
            id: returnButton

            height: parent.height * 0.05
            width: parent.width * 0.15
            anchors.horizontalCenter: parent.horizontalCenter
            src: "qrc:/resources/images/RETURN-ICON.png"

            onClicked: {
                root.finish()
            }
        }
    }
}
