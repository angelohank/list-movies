import QtQuick 2.15
import QtQuick.Controls 2.0

Rectangle {
    id: root

    height: 30
    width: 240
    radius: 8
    color: "#DCDCDC"

    property string _text: ""

    TextArea {
        id: textArea

        anchors.fill: parent
        background: transparent
        font.pixelSize: 15

        onTextChanged: {
            root._text = textArea.text
        }
    }
}
