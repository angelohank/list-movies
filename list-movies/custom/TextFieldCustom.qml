import QtQuick 2.15
import QtQuick.Controls 2.12

TextArea {
    id: root

    background: Rectangle {
        height: parent.height
        width: parent.width
        radius: 8
        color: "#DCDCDC"
        border.color: "#DCDCDC"
    }

    font.pixelSize: root.height * 0.5
    placeholderText: "Buscar"

    //TODO tratar para pesquisar quando pressionar o enter
    Keys.onReturnPressed: {
        return
    }
}
